#include <stdio.h>
int main()
{
    int a, b, c, d, e;
    for (a = 1; a < 4; a++)
    {
        for (b = 1; b <= 4; b++)
        {
            if (a != b)
            {
                for (c = 1; c <= 4; c++)
                {
                    if (c != a && c != b)
                    {
                        for (d = 1; d <= 4; d++)
                        {
                            if (d != a && d != b && d != c)
                            {
                                for (e = 1; e < 4; e++)
                                {
                                    e = 15 - a - b - c - d;
                                    if (e != a && e != b && e != c && e != d)
                                    {
                                        if (((b == 3) + (c == 5)) && ((d == 2) + (e == 4)) && ((b == 1) + (d == 4)) && ((b == 2) + (c == 1)) && ((a == 3) + (d == 2)))
                                        {
                                            printf("a,b,c,d,e=%d %d %d %d %d", a, b, c, d, e);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}