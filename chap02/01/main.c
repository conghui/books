#include <stdio.h>
#include <limits.h>

static void calByHand();
static void calByStd();

int main(void)
{
    calByStd();
    printf("\n------------------------------------------------------------\n\n");
    calByHand();
    return 0;
}

static void calByStd() {
    printf("%20s%20s%20s\n", "", "MIN", "MAX");
    printf("%20s%20d%20d\n", "signed char:", SCHAR_MIN, SCHAR_MAX);
    printf("%20s%20d%20d\n", "signed short:", SHRT_MIN, SHRT_MAX);
    printf("%20s%20d%20d\n", "signed int:", INT_MIN, INT_MAX);
    printf("%20s%20ld%20ld\n", "signed long:", LONG_MIN, LONG_MAX);
    printf("\n");
    printf("%20s%20d%20u\n", "unsigned char:", 0, UCHAR_MAX);
    printf("%20s%20d%20u\n", "unsigned short:", 0, USHRT_MAX);
    printf("%20s%20d%20u\n", "unsigned int:", 0, UINT_MAX);
    printf("%20s%20d%20lu\n", "unsigned long:", 0, ULONG_MAX);
}

static void calByHand()
{
    signed char schar_max = (signed char)((unsigned char) ~0 >> 1);
    signed char schar_min = ~schar_max;

    signed short shrt_max = (signed short)((unsigned short) ~0 >> 1);
    signed short shrt_min = ~shrt_max;

    signed int int_max = (signed int)((unsigned int) ~0 >> 1);
    signed int int_min = ~int_max;

    signed long long_max = (signed long)((unsigned long) ~0 >> 1);
    signed long long_min = ~long_max;

    unsigned char uchar_max = (unsigned char) ~0;
    unsigned short ushrt_max = (unsigned short) ~0;
    unsigned int uint_max = (unsigned int) ~0;
    unsigned long ulong_max = (unsigned long) ~0;

    printf("%20s%20s%20s\n", "", "MIN", "MAX");
    printf("%20s%20d%20d\n", "signed char:", schar_min, schar_max);
    printf("%20s%20d%20d\n", "signed short:", shrt_min, shrt_max);
    printf("%20s%20d%20d\n", "signed int:", int_min, int_max);
    printf("%20s%20ld%20ld\n", "signed long:", long_min, long_max);
    printf("\n");
    printf("%20s%20d%20u\n", "unsigned char:", 0, uchar_max);
    printf("%20s%20d%20u\n", "unsigned short:", 0, ushrt_max);
    printf("%20s%20d%20u\n", "unsigned int:", 0, uint_max);
    printf("%20s%20d%20lu\n", "unsigned long:", 0, ulong_max);
}
