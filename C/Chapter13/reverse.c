#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z  '\032'
#define SLEN 81
int main()
{
    char file[SLEN];
    char ch;
    FILE *fp;
    long count,last;

    puts("Enter the name of the file to be processed:");
    scanf("%80s",file);

    if((fp=fopen(file,"rb"))==NULL)
    {
        printf("reverse can't open %s\n",file); //只读模式
        exit(EXIT_FAILURE);
    }   
    
    fseek(fp,0L,SEEK_END);      //定位到文件末尾
    last = ftell(fp);

    for(count = 1L; count <= last;count++)
    {
        fseek(fp,+count,SEEK_SET);  //回退
        ch = getc(fp);
        if(ch!=CNTL_Z && ch!='\r')
            putchar(ch);
    }

    putchar('\n');
    fclose(fp);
    return 0;
}

















