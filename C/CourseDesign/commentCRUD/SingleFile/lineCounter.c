//���ܣ�ͳ���ļ�������,�ַ���,������,�����д�ӡ�ļ�
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_SIZE 100
void counter(char*);
int main()
{
    char fileName[MAX_SIZE];
    printf("�����ļ���:\n");
    gets(fileName);
    counter(fileName);

}
void counter(char* str)
{
    int line = 1,word = 0,charNum = 0;
    int num = 1,datalen = 0;
    char fileName[MAX_SIZE];
    char buf[MAX_SIZE]; //���ַ������ȡһ������
    char c;
    bool inword = false;
    strcpy(fileName,str);

    FILE* fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("�޴��ļ�!\n");
        return main();
    }
    printf("%s �򿪳ɹ�!\n",fileName);

 
    printf("�ļ�����:\n");
    while((c = fgetc(fp)) != EOF)
    {
    
        if(c == '\n')
        {
            line++;
            continue;
        } 
            charNum++;
        if(isalpha(c) && inword == false)  //���ʿ�����ĸ�����,�����ȡ���ַ�����a-z��A-Z��˵���ѵ�����ĩβ
        {
            inword = true;
            word++;
        }
        if(!isalpha(c) && inword == true)
        {
            inword = false;
        }

        fputc(c,stdout);
    }
    printf("\n����  |�ַ���  |������  |\n");
    printf("   %d      %d      %d\n",line,charNum,word);  

    rewind(fp);
 
    printf("�������(˳��):\n");
    while(fgets(buf,MAX_SIZE,fp)!=NULL)
    {
        printf("No.%d:%s\n",num,buf);
        num++;
    }
    
    fprintf(fp,"%d",line);

    fclose(fp);
}