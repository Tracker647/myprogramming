#include <stdio.h>
int main()
{
    FILE *fp = NULL;
    char buff[255];
    fp = fopen("test.txt","r");
    // fprintf(fp,"This is a testing for fprintf\n");
    // fputs("write end",fp);

    // fscanf(fp,"%[^\n]",buff);
    // printf("1:%s\n",buff);

    fgets(buff,255,fp);
    printf("2:%s\n",buff);

    fclose(fp);


}