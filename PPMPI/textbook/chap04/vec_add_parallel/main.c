#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "util.h"
#include "vector.h"
#include "mpi.h"

static void read_file(FILE *fp, vector_t vec);
static FILE *open_file(const char *fname1, const char *mode);
static void set_fname(int argc, char **argv, char *f1, char *f2);
static void usage(const char *progname);

int main(int argc, char *argv[])
{
    char fname1[FILENAME_MAX];
    char fname2[FILENAME_MAX];
    vector_t vec1;
    vector_t vec2;
    vector_t vec_sum;
    FILE *fp1;
    FILE *fp2;
    MPI_Status status;

    set_fname(argc, argv, fname1, fname2);
    fp1 = open_file(fname1, "r");
    fp2 = open_file(fname2, "r");

    /* allocate space for vec1 vec2 and vec3 */
    int size1;
    int size2;
    assert(fscanf(fp1, "%d", &size1) == 1);
    assert(fscanf(fp2, "%d", &size2) == 1);
    assert(size1 == size2);
    vec1 = vector_init(size1);
    vec2 = vector_init(size2);
    vec_sum = vector_init(size1);

    /* populate the vec1 and vec2 */
    read_file(fp1, vec1);
    read_file(fp2, vec2);

    /* MPI start up */
    int rank;
    int nproc;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nproc);

    /* ditribute the data */
    int nelem;
    size_t begin_idx;
    size_t end_idx;

    nelem = (vec1->size + nproc - 1) / nproc;
    begin_idx = rank * nelem;
    end_idx   = begin_idx + nelem;
    /* scale the end index */
    end_idx   = end_idx < vec1->size ? end_idx : vec1->size;

    /* calcuate the sum of two vector */
    size_t i;

    for (i = begin_idx; i != end_idx; i++) {
        vec_sum->content[i] = vec1->content[i] + vec2->content[i];
        vec_sum->size++;
    }

    if (rank != 0) {
        MPI_Send(vec_sum->content + begin_idx, end_idx - begin_idx,
                 MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    if (rank == 0) {
        for (rank = 1; rank < nproc; rank++) {
            begin_idx = rank * nelem;
            end_idx   = begin_idx + nelem;
            /* scale the end index */
            end_idx   = end_idx < vec1->size ? end_idx : vec1->size;

            
            MPI_Recv(vec_sum->content + begin_idx, end_idx - begin_idx,
                     MPI_INT, rank, 0, MPI_COMM_WORLD, &status);
            vec_sum->size += end_idx - begin_idx;
        }

        /* print the result */
        vector_print(vec_sum);
    }

    vector_finalize(vec1);
    vector_finalize(vec2);
    vector_finalize(vec_sum);

    MPI_Finalize();
    return 0;
}

static void read_file(FILE *fp, vector_t vec)
{
    size_t i;

    for (i = 0; i < vec->capacity; i++) {
        assert(fscanf(fp, "%d", &vec->content[i]) == 1);
        vec->size++;
    }

}

static FILE *open_file(const char *fname1, const char *mode)
{
    FILE *fp;
    fp             = fopen(fname1, mode);

    if (fp == NULL) {
        error("cannot open %s", fname1);
    }

    return fp;
}

static void set_fname(
    int    argc,
    char **argv,
    char  *f1,
    char  *f2)
{
    if (argc != 3) {
        usage(argv[0]);
    } else {
        strcpy(f1, argv[1]);
        strcpy(f2, argv[2]);
    }
}

static void usage(const char *progname)
{
    error("usage: %s file1 file2\n", progname);
}
