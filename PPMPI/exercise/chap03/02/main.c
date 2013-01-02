#include <stdio.h>
#include <string.h>

#include "mpi.h"

#define MAXSIZE 100

int main(int argc, char *argv[])
{
    int rank;
    int nproc;
    int tag;
    char msg[MAXSIZE];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    tag  = 0;

    if (rank != 0) {
        int dest = 0;
        sprintf(msg, "Greeting %d!", rank);
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
    } else { /* rank == 0 */
        while (--nproc > 0) {
            MPI_Recv(msg, MAXSIZE, MPI_CHAR, MPI_ANY_SOURCE,
                     tag, MPI_COMM_WORLD, &status);
            printf("%s\n", msg);
        }
    }

    MPI_Finalize();
    return 0;
}
