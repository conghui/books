#include <stdio.h>
#include "info.h"

int main(void) {
    int count;
    cudaDeviceProp prop;

    cudaGetDeviceCount(&count);

    for (int i = 0; i < count; i++) {
        cudaGetDeviceProperties(&prop, i);
        getGeneralInfo(&prop, i);
        getMemInfo(&prop, i);
        getMPInfo(&prop, i);

    }
    return 0;
}
