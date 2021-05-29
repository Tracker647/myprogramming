#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 45 //根据题目ASL要求计算出表长为45
#define NAMELEN 30
#define SUCCESS 1
#define UNSUCCESS 0

typedef int Status;
typedef struct 
{
    int addrs[HASHSIZE];
    int count;
}HashTable;


void InitlizeHash(HashTable* H)
{
    int i;
    // for(i=0;i<HASHSIZE;i++)
    // {
    //      H->addrs[i]=(int*)malloc(sizeof(int));
    // }
    H->count = HASHSIZE;
    for(i=0;i<HASHSIZE;i++)
    {
        H->addrs[i]=NULL;
    }
}
int Hash(int key)   //散列函数
{
    return key % HASHSIZE;
}
void InsertHash(HashTable* H,int key)
{
    int addr = Hash(key);
    while(H->addrs[addr]!=NULL)
        addr = (addr + 1) % HASHSIZE;
    H->addrs[addr] = key;
}

Status SearchHash(HashTable* H,int key)
{
    int addr = Hash(key); //搜索方法：再把值通过哈希函数获得对应的地址
    int count=1;
    while(H->addrs[addr]!=key)     //地址若冲突用线性探测再散列法解决
    {
        addr = (addr + 1) % HASHSIZE;
        if(addr == Hash(key) || H->addrs[addr] == NULL) //如果绕了一圈回到原点(a=1)或者发现这是新值（a<1）,则查找失败
            return UNSUCCESS;
        count++;
    }

    printf("查找成功，查找次数:%d\n",count);
    return addr;
}

int main()
{
    char *NameList[NAMELEN] = { };
    int addr;
    HashTable H;

    NameList[0]="chenghongxiu"; //30个学生的姓名
    NameList[1]="yuanhao";
    NameList[2]="yangyang";
    NameList[3]="zhanghen";
    NameList[4]="chenghongxiu";
    NameList[5]="xiaokai";
    NameList[6]="liupeng";
    NameList[7]="shenyonghai";
    NameList[8]="chengdaoquan";
    NameList[9]="ludaoqing";
    NameList[10]="gongyunxiang";
    NameList[11]="sunzhenxing";
    NameList[12]="sunrongfei";
    NameList[13]="sunminglong";
    NameList[14]="zhanghao";
    NameList[15]="tianmiao";
    NameList[16]="yaojianzhong";
    NameList[17]="yaojianqing";
    NameList[18]="yaojianhua";
    NameList[19]="yaohaifeng";
    NameList[20]="chengyanhao";
    NameList[21]="yaoqiufeng";
    NameList[22]="qianpengcheng";
    NameList[23]="yaohaifeng";
    NameList[24]="bianyan";
    NameList[25]="linglei";
    NameList[26]="fuzhonghui";
    NameList[27]="huanhaiyan";
    NameList[28]="liudianqin";
    NameList[29]="wangbinnian";     

    // for(int i=0;i<NAMELEN;i++)
    // {ddyyy8
    //     printf("%s\n",NameList[i]);
    // }
    InitlizeHash(&H);
    for(int i=0;i<NAMELEN;i++)
    {
        InsertHash(&H,i);
    }
    for(int i=0;i<NAMELEN;i++)
    {
        addr = SearchHash(&H,i);
        printf("%d号学生：%s ,位于表中%d位\n",i,NameList[i],addr);
    }
   

    
}