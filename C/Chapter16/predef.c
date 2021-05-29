#include <stdio.h>
void why_me();

int main()
{
    printf("The file is %s.\n",__FILE__);
    printf("The data is %s.\n",__DATE__);
    printf("The time is %s.\n",__TIME__);
    printf("The version is $ld.\n",__STDC_VERSION__);
    printf("This is line %d.\n",__LINE___);
    printf("This function is %s\n",__func__);
    why_me();
    return 0;
}

void