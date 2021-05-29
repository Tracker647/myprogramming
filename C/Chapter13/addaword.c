#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 41

int main()
{
    FILE *fp;
    char words[MAX];

    if((fp=fopen("wordy","w+")) == NULL)
    {
        fprintf(stdout,"Can't open \"wordy\" file.\n");
        exit(EXIT_FAILURE);
    }

    puts("Enter words to add to file;press the #");
    puts("key at the beginning of a line terminate.");

    while((fscanf(stdin,"%40s",words)==1)&&(words[0]!='#'))
        fprintf(fp,"%s",words);   //把words数组的词打印在文件上存储起来

    puts("File contents:");
    rewind(fp); //返回到文件开始处

    while(fscanf(fp,"%s",words)==1) //从文件开头读取内容赋给字符数组
        puts(words);

    puts("Done!");
    
    if(fclose(fp)!=0)
        fprintf(stderr,"Error closing file.\n");

    return 0;

}

















