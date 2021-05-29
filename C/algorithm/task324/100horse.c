#include <stdio.h>
int main()
{
    int x, y, z;
    for (x = 1; x < 100; x++)
    {
        for (y = 1; y < 100; y++)
        {
            z = 100 - x - y;
            if (x + y + z == 100 && 3 * x + 2 * y + 0.5 * z == 100)
            {
                printf("Big horse: %d\nMedium horse: %d\nSmall horse:%d\n", x, y, z);
                printf("\n");
            }
        }
    }
}