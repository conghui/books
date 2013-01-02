#include <stdio.h>

#include "mpi.h"

#define MAXSIZE 100000ULL

static void init(unsigned long long *vector, unsigned long long size);

int main(int argc, char *argv[])
{
    int rank;
    int nproc;
    unsigned long long  vector[MAXSIZE];
    MPI_Status status;

    init(vector, MAXSIZE);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    unsigned long  nelem = (MAXSIZE + nproc - 1) / nproc;
    unsigned long long *vec_end     = vector + MAXSIZE;
    const unsigned long long  *begin = vector + rank * nelem;
    const unsigned long long  *end   = begin + nelem;
    end              = end < vec_end ? end : vec_end;

    unsigned long long  sum          = 0;

    for (; begin != end; begin++) {
        sum += *begin;
    }

    if (rank != 0) {
        /* send  the result to process 0*/
        MPI_Send(&sum, 1, MPI_UNSIGNED_LONG_LONG, 0, 0, MPI_COMM_WORLD);
    } else { /* rank == 0 */
        unsigned long long n;

        while (--nproc > 0) {
            MPI_Recv(&n, 1, MPI_UNSIGNED_LONG_LONG, MPI_ANY_SOURCE,
                     0, MPI_COMM_WORLD, &status);
            sum += n;
        }

        printf("the sum of %llu to %llu is: %llu\n", vector[0],
               vector[MAXSIZE - 1], sum);
    }

    MPI_Finalize();
    return 0;
}

static void init(unsigned long long *vector, unsigned long long size)
{
    unsigned long long i;

    for (i = 0; i < size; i++) {
        vector[i] = (i + 1);
    }
}
