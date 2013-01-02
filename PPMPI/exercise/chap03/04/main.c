#include <stdio.h>
#include <string.h>

#include "mpi.h"

#define MAXSIZE 100

int main(int argc, char *argv[])
{
    int rank;
    int nproc;
    char msg[MAXSIZE];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    printf("Greeting from %d.\n", rank);

    int dest = nproc - 1;

    /* one process cannot send message to itself,
     * otherwise, it will cause deadlock */
    if (rank != dest) {
        printf("\tprocesss %d send message to process %d\n",
               rank, dest);
        sprintf(msg, "%s send by %d", "Hello World", rank);
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, dest,
                 0, MPI_COMM_WORLD);
    }

    if (rank == dest)  { /* rank == nproc - 1 */
        while (--nproc > 0) {
            MPI_Recv(msg, MAXSIZE, MPI_CHAR, MPI_ANY_SOURCE,
                     0, MPI_COMM_WORLD, &status);
            printf("\t\tReceived: ");
            printf("%s\n", msg);
        }
    }

    return MPI_Finalize();
}
