#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#define SLEN 30
#define BUFSIZE 4096
void append(FILE *source,FILE *dest);   //拷贝文件函数
char* s_gets(char* st,int n);   //输入过滤
void contents(FILE *fp);    //文件内容打印
void toupperfile(FILE *fp); //将文件中的文字全部大写
int main()
{
   
    FILE *fa,*fs;   //fa指向目标文件,fs指向源文件
    int files=0;            //附加的文件数量    
    char file_app[SLEN];    //目标文件名
    char file_src[SLEN];    //源文件名

    puts("Enter name of destination file:");
    s_gets(file_app,SLEN);
    if((fa=fopen(file_app,"w+"))==NULL) //若不能打开目标文件
    {
        fprintf(stderr,"Can't open %s\n",file_app);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file(empty line to quit):");
    while(s_gets(file_src,SLEN)&&file_src[0]!='\0')
    {
        if(strcmp(file_src,file_app)==0)
        {
            fprintf(stderr,"Can't copy and stick same file!\n");
        }

        if((fs=fopen(file_src,"r"))==NULL)     //若不能打开源文件
        {
            fprintf(stderr,"Can't open %s\n",file_src);
        }
        else
        {       
            toupper(fs);
            append(fs,fa);
            if(ferror(fa)!=0)
            {
                fprintf(stderr,"Error in writing files.\n");
            }

            if(ferror(fs)!=0)
            {
                fprintf(stderr,"Error in reading files.\n");
            }  
            printf("The content in %s has successfully appended to %s.\n",file_src,file_app);
            files++;
            printf("Enter the next append file,empty line to quit:\n");
        }
        
    }
    
    printf("total has %d files append.\n",files);

    printf("append file %s contents:\n",file_app);
    contents(fa);

    fclose(fa);
    fclose(fs);
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

void contents(FILE *fp)
{
    int ch;
    rewind(fp);//不重置文件指针是没法打印的
    while((ch=getc(fp))!=EOF)
        putchar(toupper(ch));
    puts("\nDone displaying.\n");

}

void toupperfile(FILE *fp)
{
    

}









