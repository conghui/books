#include <stdio.h>

/* print Celsius-Fahrenhei ttable
 * for celsius = 0, 20, ..., 300; floating-point version */

int main(void)
{
    float fahr;
    float celsius;
    int lower;
    int upper;
    int step;

    lower = 0;      /* lower limit of temperature table */
    upper = 300;    /* upper limit */
    step = 20;      /* step size */

    printf("Celsius   Fahr\n");
    celsius = lower;

    while (celsius <= upper) {
        fahr = (9.0 * celsius) / 5.0 + 32.0;
        printf("%5.0f   %6.1f\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}
