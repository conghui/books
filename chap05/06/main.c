#include <stdio.h>
#include <ctype.h>
#include <string.h>


/**
 * @brief read a line into s, if the '\n' character is found, it will 
 * be read in either.
 *
 * @param s buffer storing the result
 * @param lim size of the buffer
 *
 * @return the length of the line
 */
int getline(char *s, int lim)
{
    int c;
    const char *t = s;

    for (c = getchar(); c != EOF && c != '\n' && --lim > 0; c = getchar())
    {
        *s++ = c;
    }

    if (c == '\n')
    {
        *s++ = c;
    }

    *s++ = '\0';

    return s - t;
}

/**
 * @brief convert string to int
 *
 * It convert the initial integer portioin of the string pointed by 
 * nptr to int
 *
 * @param nptr points to string of int
 *
 * @return the integer value of the string
 */
int atoi(const char *nptr)
{
    int value = 0;
    int sign = 1;

    if (nptr == NULL) {
        return 0;
    }

    /* skip the white space */
    while (isspace(*nptr)) {
        nptr++;
    }

    /* detect the sign */
    sign = (*nptr == '-') ? -1 : 1;
    if (*nptr == '+' || *nptr == '-') {
        nptr++;
    }

    for (; isdigit(*nptr); nptr++) {
        value = value * 10 + *nptr - '0';
    }

    return value * sign;
}

#define swap(T, a, b) \
    T ___tmp = a; \
    a = b; \
    b = ___tmp;

/**
 * @brief reverse the character in string pointed by s
 *
 * @param s 
 */
void reverse(char *s)
{
    char *t = s + strlen(s) - 1;

    for (; s < t; s++, t--) {
        swap(char, *s, *t);
    }
}

/**
 * @brief convert int to string
 *
 * @param n value of int
 * @param s address of the array
 */
void itoa(int n, char *s)
{
    int nagative = 0;
    char *t = s;

    if (n < 0) {
        nagative = 1;
        n = -n;
    }

    do {
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    
    if (nagative) {
        *s++ = '-';
    }

    *s = '\0';

    reverse(t);
}

/**
 * @brief get the index of substring t in s
 *
 * @param s 
 * @param t
 *
 * @return the index of t in s
 */
int strindex(const char *s, const char *t)
{
    size_t ts = strlen(t);
    const char *bs = s;

    for (; *(s + ts)!= '\0'; s++) {
        const char *pt;
        const char *ps;
        for (pt = t, ps = s; *pt != '\0' && *pt == *ps; pt++, ps++) {
            ;
        }

        if (*pt == '\0' && pt > t) {
            return s - bs;
        }
    }

    return -1;
}

double atof(char *s)
{
    int sign;
    int val = 0;
    int exp = 1;

    while (isspace(*s)) {
        s++;
    }

    sign = *s == '-' ? -1 : 1;
    if (*s == '-' || *s == '+') {
        s++;
    }

    for (; isdigit(*s); s++) {
        val = val * 10 + *s - '0';
    }

    if (*s == '.') {
        s++;
    }

    for (; isdigit(*s); s++) {
        val = val * 10 + *s - '0';
        exp *= 10;
    }

    return (double)val * sign / exp;
}

int main(void)
{
    return 0;
}
