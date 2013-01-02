#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "mpi.h"

typedef double (*F)(double);
static void set_fnc(F *fp, int rank, int nproc);
static inline double f1(double x);
static inline double f2(double x);
static inline double f3(double x);
static double trap( F f, double a, double b, double n, double h);

int main(int argc, char **argv)
{
    int        rank;                  /* my process rank                   */
    int        nproc;                 /* # of process                      */
    double     integral;              /* store result in integral          */
    double     a              = 1.0;  /* left end point                    */
    double     b              = 10.0;  /* right end point                   */
    double     h;                     /* trapezoid base lenght             */
    int        n              = 1024; /* # of trapezoids                   */
    double     local_a;               /* left endpoint of my process       */
    double     local_b;               /* right endpoint of my process      */
    double     local_n;               /* # of trapezoid for my calculation */
    double     local_integral;        /* integral for my process           */
    int        dest           = 0;    /* all messages go to 0              */
    int        tag            = 0;
    F          f;

    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    h       = (b - a) / n;          /* h is the same for all process */
    local_n = n / nproc;            /* so is the of trapezoid        */
    local_a = a + rank * local_n * h;
    local_b = local_a + local_n * h;

    set_fnc(&f, rank, nproc);
    local_integral = trap(f, local_a, local_b, local_n, h);

    if (rank != 0) {
        MPI_Send(&local_integral, 1, MPI_DOUBLE, dest,
                 tag, MPI_COMM_WORLD);
        printf("process %d send %f\n", rank, local_integral);
    } else { /* add up the integral calculated by each process */
        integral = local_integral;

        while (--nproc > 0) {
            MPI_Recv(&local_integral, 1, MPI_DOUBLE, MPI_ANY_SOURCE,
                     tag, MPI_COMM_WORLD, &status);
            integral += local_integral;
        }

    }

    if (rank == 0) {
        printf("With n = %d trapezoids, our estimate "
               "of the integral from %f to %f = %f\n",
               n, a, b, integral);
    }

    MPI_Finalize();
    return 0;
}


static void set_fnc(F *fp, int rank, int nproc) {
    if (rank == 0) {
        int choice;
        printf( "[1] f(x) = x;\n"
                "[2] f(x) = x^2;\n"
                "[3] f(x) = x^3;\n"
                "Which function would you like to select: ");
        
        assert(scanf("%d", &choice) == 1);
        putchar('\n');
        switch (choice) {
            case 1:
                *fp = f1;
                break;
            case 2:
                *fp = f2;
                break;
            case 3:
                *fp = f3;
                break;
            default:
                fprintf(stderr, "unknown choice\n");
                exit(EXIT_FAILURE);
                break;
        }

        int dest;
        for (dest = 1; dest < nproc; dest++) {
            MPI_Send(fp, 4, MPI_CHAR, dest, 
                    0, MPI_COMM_WORLD);
        }
    }
    else {
        MPI_Status status;
        MPI_Recv(fp, 4, MPI_CHAR, 0,
                0, MPI_COMM_WORLD, &status);
    }
}

static inline double f1(double x)
{
    return x;
}

static inline double f2(double x)
{
    return x*x;
}

static inline double f3(double x)
{
    return x*x*x;
}


static double trap(
        F f,
    double a,
    double b,
    double n,
    double h)
{
    double integral; /* store result in integral */
    double x;
    int i;

    integral = (f(a) + f(b)) / 2.0;
    x        = a;

    for (i = 1; i <= n - 1; i++) {
        x        += h;
        integral += f(x);
    }

    integral *= h;
    return integral;
}
