#include <stdio.h>
#include <string.h>

#include "mpi.h"

static int first_send = 1;

static void send_first(int rank, int nproc, char *msg,
                       int tag, MPI_Status *status);

static void recv_first(int rank, int nproc, char *msg,
                       int tag, MPI_Status *status);

static void send(int rank, int nproc, char *msg,
                 int tag);

static void recv(int rank, int nproc, char *msg,
                 int tag, MPI_Status *status);

int main(int argc, char *argv[])
{
    int rank;
    int nproc;
    int tag = 0;
    char msg[BUFSIZ];
    MPI_Status status;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    if (first_send) {
        send_first(rank, nproc, msg, tag, &status);
    } else {
        recv_first(rank, nproc, msg, tag, &status);
    }

    MPI_Finalize();

    return 0;
}

static void send_first(
    int         rank,
    int         nproc,
    char       *msg,
    int         tag,
    MPI_Status *status)
{
    send(rank, nproc, msg, tag);
    recv(rank, nproc, msg, tag, status);
}

static void recv_first(
    int         rank,
    int         nproc,
    char       *msg,
    int         tag,
    MPI_Status *status)
{
    recv(rank, nproc, msg, tag, status);
    send(rank, nproc, msg, tag);
}

static void send(int rank, int nproc, char *msg, int tag)
{
    int dest = (rank + 1) % nproc;
    sprintf(msg, "Greetings of %d", rank);
    MPI_Send(msg, strlen(msg) + 1, MPI_CHAR, dest, tag, MPI_COMM_WORLD);
}

static void recv(int rank, int nproc, char *msg, int tag, MPI_Status *status)
{
    int src = (rank - 1 + nproc) % nproc;
    MPI_Recv(msg, BUFSIZ, MPI_CHAR, src, tag, MPI_COMM_WORLD, status);
    printf("process %d receive: %s\n", rank, msg);
}
