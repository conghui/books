#ifndef INFO_H
#define INFO_H
void getGeneralInfo(const cudaDeviceProp *prop, int i);
void getMemInfo(const cudaDeviceProp *prop, int i);
void getMPInfo(const cudaDeviceProp *prop, int i);
#endif
