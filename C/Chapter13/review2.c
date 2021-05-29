#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SLEN 30
#define BUFSIZE 4096
void append(FILE *source,FILE *dest);
char* s_gets(char* st,int n);

int main()
{
   
    FILE *fa,*fs;   //fa指向目标文件,fs指向源文件
    int files=0;            //附加的文件数量    
    char file_app[SLEN];    //目标文件名
    char file_src[SLEN];    //源文件名
    int ch;

    puts("Enter name of destination file:");
    s_gets(file_app,SLEN);
    if((fa=fopen(file_app,"a+"))==NULL) //若不能打开目标文件
    {
        fprintf(stderr,"Can't open %s\n",file_app);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file(empty line to quit):");
    s_gets(file_src,SLEN);
    
    if((fs=fopen(file_src,"r"))==NULL)     //若不能打开源文件
        fprintf(stderr,"Can't open %s\n",file_src);

    append(fs,fa);
    fclose(fs);

    printf("The content in %s has successfully appended to %s.\n",file_src,file_app);
    printf("%s contents:\n",file_app);
    rewind(fa);//不重置文件指针是没法打印的
    while((ch=getc(fa))!=EOF)
        putchar(ch);
    puts("\nDone displaying.");
    fclose(fa);

    return 0;
}

void append(FILE *source,FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];

    while((bytes = fread(temp,sizeof(char),BUFSIZE,source))>0)
        fwrite(temp,sizeof(char),bytes,dest);
}

char* s_gets(char* st,int n)    //字符输入检测函数
{
    char* ret_val;
    char* find;
    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n'); //查找输入的字符串在前n个字的范围内是否有换行符
        if(find)
            *find = '\0';   //若有将尾部的换行符替代掉
        else
            while(getchar()!='\n')  //若无将n后面的字符全部丢弃
                continue;       
    }
    return ret_val;
}