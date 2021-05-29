//功能：统计文件的行数,字符数,单词数,并逐行打印文件
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>
#define MAX_SIZE 100
void counter(char*);
int main()
{
    char fileName[MAX_SIZE];
    printf("输入文件名:\n");
    gets(fileName);
    counter(fileName);

}
void counter(char* str)
{
    int line = 1,word = 0,charNum = 0;
    int num = 1,datalen = 0;
    char fileName[MAX_SIZE];
    char buf[MAX_SIZE]; //用字符数组读取一行输入
    char c;
    bool inword = false;
    strcpy(fileName,str);

    FILE* fp = fopen(fileName,"r");
    if(fp == NULL)
    {
        printf("无此文件!\n");
        return main();
    }
    printf("%s 打开成功!\n",fileName);

 
    printf("文件内容:\n");
    while((c = fgetc(fp)) != EOF)
    {
    
        if(c == '\n')
        {
            line++;
            continue;
        } 
            charNum++;
        if(isalpha(c) && inword == false)  //单词看作字母的组合,如果获取的字符不在a-z或A-Z内说明已到单词末尾
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
    printf("\n行数  |字符数  |单词数  |\n");
    printf("   %d      %d      %d\n",line,charNum,word);  

    rewind(fp);
 
    printf("逐行输出(顺序):\n");
    while(fgets(buf,MAX_SIZE,fp)!=NULL)
    {
        printf("No.%d:%s\n",num,buf);
        num++;
    }
    
    fprintf(fp,"%d",line);

    fclose(fp);
}