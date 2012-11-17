#include <stdio.h>
#include "info.h"

void getGeneralInfo(const cudaDeviceProp *prop, int i) {
    printf("\n   --- General information for device %d ---\n", i);
    printf("Name:               %s\n", prop->name);
    printf("Compute capalibity: %d.%d\n", prop->major, prop->minor);
    printf("Clock rate:         %d\n", prop->clockRate);
    printf("Device copy overlap: ");

    if (prop->deviceOverlap) {
        printf("Enabled\n");
    }
    else {
        printf("Disabled\n");
    }

    printf("Kernel excition timeout: ");

    if (prop->kernelExecTimeoutEnabled) {
        printf("Enabled\n");
    }
    else {
        printf("Disabled\n");
    }
}

void getMemInfo(const cudaDeviceProp *prop, int i) {
    printf("\n   --- Memory information for Device %d ---\n", i);
    printf("Total global mem:   %ld\n", prop->totalGlobalMem);
    printf("Total contant mem:  %ld\n", prop->totalConstMem);
    printf("Max mem pitch:      %ld\n", prop->memPitch);
    printf("Texture Alignment:  %ld\n", prop->textureAlignment);
}

void getMPInfo(const cudaDeviceProp *prop, int i) {
    printf("\n   --- MP information for Device %d --\n", i);
    printf("Multiprocessor count:   %d\n", prop->multiProcessorCount);
    printf("Shared mem per mp:      %ld\n", prop->sharedMemPerBlock);
    printf("Register per mp:        %d\n", prop->regsPerBlock);
    printf("Threads in warp:        %d\n", prop->warpSize);
    printf("Max threads per block:  %d\n", prop->maxThreadsPerBlock);
    printf("Max thread dimensions: (%d, %d, %d)\n",
            prop->maxThreadsDim[0],
            prop->maxThreadsDim[1],
            prop->maxThreadsDim[2]);
    printf("Max grid dimensions: (%d, %d, %d)\n",
            prop->maxGridSize[0],
            prop->maxGridSize[1],
            prop->maxGridSize[2]);
}
