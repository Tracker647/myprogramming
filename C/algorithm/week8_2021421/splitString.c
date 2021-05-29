#include <stdio.h>
#include <stdlib.h>
#include <string.h>
main()
{
    char s[] = "98+76+2+45";
    char *result;
    int temp;
    for (result = strtok(s, "+"); result != NULL; result = strtok(NULL, "+"))
    {
        temp = atoi(result);
        printf("%d ", temp);
    }
}

