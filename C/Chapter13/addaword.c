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
        fprintf(fp,"%s",words);   //��words����Ĵʴ�ӡ���ļ��ϴ洢����

    puts("File contents:");
    rewind(fp); //���ص��ļ���ʼ��

    while(fscanf(fp,"%s",words)==1) //���ļ���ͷ��ȡ���ݸ����ַ�����
        puts(words);

    puts("Done!");
    
    if(fclose(fp)!=0)
        fprintf(stderr,"Error closing file.\n");

    return 0;

}

















