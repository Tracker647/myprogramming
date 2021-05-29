#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#define SLEN 30
#define BUFSIZE 4096
void append(FILE *source,FILE *dest);   //�����ļ�����
char* s_gets(char* st,int n);   //�������
void contents(FILE *fp);    //�ļ����ݴ�ӡ
void toupperfile(FILE *fp); //���ļ��е�����ȫ����д
int main()
{
   
    FILE *fa,*fs;   //faָ��Ŀ���ļ�,fsָ��Դ�ļ�
    int files=0;            //���ӵ��ļ�����    
    char file_app[SLEN];    //Ŀ���ļ���
    char file_src[SLEN];    //Դ�ļ���

    puts("Enter name of destination file:");
    s_gets(file_app,SLEN);
    if((fa=fopen(file_app,"w+"))==NULL) //�����ܴ�Ŀ���ļ�
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

        if((fs=fopen(file_src,"r"))==NULL)     //�����ܴ�Դ�ļ�
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

void contents(FILE *fp)
{
    int ch;
    rewind(fp);//�������ļ�ָ����û����ӡ��
    while((ch=getc(fp))!=EOF)
        putchar(toupper(ch));
    puts("\nDone displaying.\n");

}

void toupperfile(FILE *fp)
{
    

}









