#include <stdio.h>
#include <assert.h>

#include "mpi.h"

static void get_data(double *pa, double *pb, int *pn, int rank, int nproc);
static inline double f(double x);
static double trap(double a, double b, double n, double h);

int main(int argc, char **argv)
{
    int        rank;               /* my process rank                   */
    int        nproc;              /* # of process                      */
    double     integral;           /* store result in integral          */
    double     a;                  /* left end point                    */
    double     b;                  /* right end point                   */
    double     h;                  /* trapezoid base lenght             */
    int        n;                  /* # of trapezoids                   */
    double     local_a;            /* left endpoint of my process       */
    double     local_b;            /* right endpoint of my process      */
    double     local_n;            /* # of trapezoid for my calculation */
    double     local_integral;     /* integral for my process           */
    int        dest           = 0; /* all messages go to 0              */
    int        tag            = 0;
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    get_data(&a, &b, &n, rank, nproc);
    h       = (b - a) / n;          /* h is the same for all process */
    local_n = n / nproc;            /* so is the of trapezoid        */
    local_a = a + rank * local_n * h;
    local_b = local_a + local_n * h;

    local_integral = trap(local_a, local_b, local_n, h);

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

static void get_data(
    double *pa,
    double *pb,
    int   *pn,
    int    rank,
    int    nproc)
{

    if (rank == 0) {
        int dest;
        printf("Enter a, b and n: ");
        assert(scanf("%lf%lf%d", pa, pb, pn) == 3);

        for (dest = 1; dest < nproc; dest++) {
            MPI_Send(pa, 1, MPI_DOUBLE, dest,
                     0, MPI_COMM_WORLD);
            MPI_Send(pb, 1, MPI_DOUBLE, dest,
                     1, MPI_COMM_WORLD);
            MPI_Send(pn, 1, MPI_INT, dest,
                     2, MPI_COMM_WORLD);
        }
    } else {
        MPI_Status status;

        MPI_Recv(pa, 1, MPI_DOUBLE, 0,
                 0, MPI_COMM_WORLD, &status);
        MPI_Recv(pb, 1, MPI_DOUBLE, 0,
                 1, MPI_COMM_WORLD, &status);
        MPI_Recv(pn, 1, MPI_INT, 0,
                 2, MPI_COMM_WORLD, &status);
    }
}

static inline double f(double x)
{
    return x;
}

static double trap(
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
