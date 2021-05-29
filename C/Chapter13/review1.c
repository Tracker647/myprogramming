#include <stdio.h>
#include <string.h>
#include "mylibrary.h"
#define SIZE 30
int main(void)
{
    FILE *fp;
    char words[SIZE];
    int k;
    printf("input the filename:\n");
    s_gets(words,SIZE);
    if((fp=fopen(words,"w"))==NULL)
    {
        printf("Can't open %s file.",words);
    }
    printf("input the text you need,# at beginning of new line to quit:\n");
    while(fscanf(stdin,"%s",words)==1 && words[0]!='#')
        fprintf(fp,"%s",words);

    printf("file content:\n");
    rewind(fp);
    while(fscanf(fp,"%s",words)==1)
         puts(words);

    if(fclose(fp)!=0)
        printf("Error in closing file.\n");
    return 0;
}