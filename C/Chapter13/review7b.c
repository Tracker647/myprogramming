#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylibrary.h"
#define SLEN 30
int main(int argc,char *argv[])
{
    FILE *f1,*f2;
    char file1[SLEN];    //Ŀ���ļ���
    char file2[SLEN];    //Դ�ļ���
    char ch;
    int line1=0,line2=0;
    puts("Enter name of file1:");
    s_gets(file1,SLEN);
    if((f1=fopen(file1,"a+"))==NULL) //�����ܴ�Ŀ���ļ�
    {
        fprintf(stderr,"Can't open %s\n",file1);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of file2:");
    s_gets(file2,SLEN);
    
    if((f2=fopen(file2,"r"))==NULL)     //�����ܴ�Դ�ļ�
        fprintf(stderr,"Can't open %s\n",file2);

    while(((ch=getc(f1))!=EOF) || ((ch=getc(f2))!=EOF))
    {   while(((ch=getc(f1))!=EOF) && ch!='\n')
        {
            putchar(ch);
                 
        }
        line1++;  

        while(((ch=getc(f2))!=EOF) && ch!='\n')
        {
            putchar(ch);       
        }
        line2++;

        if(line1=line2)
            printf("\n");
    }

    puts("Done.");
    return 0;

}
