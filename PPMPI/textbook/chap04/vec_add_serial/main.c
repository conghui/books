#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "util.h"
#include "vector.h"

static void vector_add(const vector_t v1, const vector_t v2, vector_t sum);
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

    /* calcuate the sum of two vector */
    vector_add(vec1, vec2, vec_sum);

    /* print the result */
    vector_print(vec_sum);

    vector_finalize(vec1);
    vector_finalize(vec2);
    vector_finalize(vec_sum);

    return 0;
}

static void vector_add(const vector_t v1, const vector_t v2,
                       vector_t sum)
{
    size_t i;
    assert(v1->size == v2->size && sum->capacity >= v1->size);
    
    for (i = 0; i < v1->size; i++) {
        sum->content[i] = v1->content[i]*1.0 / 1.0 + v2->content[i] * 1.0 / 1.0;
        sum->size++;
    }
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
