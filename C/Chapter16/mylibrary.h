#ifndef MYLIBRARY_H_
#define MYLIBRARY_H_
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
#endif