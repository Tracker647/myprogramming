#ifndef MYLIBRARY_H_
#define MYLIBRARY_H_
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
#endif