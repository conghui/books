#include <stdio.h>
#include <string.h>

#include "mpi.h"

#define MAXSIZE 100

int main(int argc, char *argv[])
{
    int my_rank;
    int num_proc;
    int tag;
    int dest;
    char msg[MAXSIZE];
    MPI_Status status;

    MPI_Init(&argc, &argv);                   /* start up MPI          */
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);  /* find out process rake */
    MPI_Comm_size(MPI_COMM_WORLD, &num_proc); /* find out # of process */

    tag = 0;

    if (my_rank != 0) { /* create message */
        sprintf(msg, "Greetings from process %d!", my_rank);
        dest = 0;
        MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
    } else { /* my rank == 0 */
        while (--num_proc > 0) {
            MPI_Recv(msg, MAXSIZE, MPI_CHAR, MPI_ANY_SOURCE,
                     tag, MPI_COMM_WORLD, &status);
            printf("%s\n", msg);
        }
    }

    MPI_Finalize();/* shutdown MPI */
    return 0;
}
