#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define SLEN 30
#define BUFSIZE 4096
void append(FILE *source,FILE *dest);
char* s_gets(char* st,int n);

int main()
{
   
    FILE *fa,*fs;   //faָ��Ŀ���ļ�,fsָ��Դ�ļ�
    int files=0;            //���ӵ��ļ�����    
    char file_app[SLEN];    //Ŀ���ļ���
    char file_src[SLEN];    //Դ�ļ���
    int ch;

    puts("Enter name of destination file:");
    s_gets(file_app,SLEN);
    if((fa=fopen(file_app,"a+"))==NULL) //�����ܴ�Ŀ���ļ�
    {
        fprintf(stderr,"Can't open %s\n",file_app);
        exit(EXIT_FAILURE);
    }

    puts("Enter name of first source file(empty line to quit):");
    s_gets(file_src,SLEN);
    
    if((fs=fopen(file_src,"r"))==NULL)     //�����ܴ�Դ�ļ�
        fprintf(stderr,"Can't open %s\n",file_src);

    append(fs,fa);
    fclose(fs);

    printf("The content in %s has successfully appended to %s.\n",file_src,file_app);
    printf("%s contents:\n",file_app);
    rewind(fa);//�������ļ�ָ����û����ӡ��
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

char* s_gets(char* st,int n)    //�ַ������⺯��
{
    char* ret_val;
    char* find;
    ret_val=fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n'); //����������ַ�����ǰn���ֵķ�Χ���Ƿ��л��з�
        if(find)
            *find = '\0';   //���н�β���Ļ��з������
        else
            while(getchar()!='\n')  //���޽�n������ַ�ȫ������
                continue;       
    }
    return ret_val;
}