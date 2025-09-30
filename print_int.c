#include "main.h"
#include <unistd.h>

static int print_number(long n)
{
    char buf[20];
    int i = 0, count = 0;
    long x = n;

    if (x == 0)
        return (write(1, "0", 1));

    if (x < 0)
    {
        count += write(1, "-", 1);
        x = -x;
    }

    while (x > 0)
    {
        buf[i++] = (char)('0' + (x % 10));
        x /= 10;
    }
    while (i--)
        count += write(1, &buf[i], 1);

    return (count);
}

int print_int(int n)
{
    return (print_number((long)n));
}
