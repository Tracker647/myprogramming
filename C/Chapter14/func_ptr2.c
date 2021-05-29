#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define LEN 81
char* s_gets(char *st,int n);
int showmenu(void);
void eatline(void); 

void ToUpper(char *);
void ToLower(char *);
void Transpose(char *);
void Dummy(char *);

typedef void (*V_FP_CHARP)(char*);
V_FP_CHARP pfun;
void show(V_FP_CHARP fp,char *);
V_FP_CHARP arpf[4] = {ToUpper,ToLower,Transpose,Dummy};

int main()
{
    char line[LEN];
    char copy[LEN];
    int index;
    void(*pfun)(char*);

    puts("Enter a string(empty line to quit):");
    while(s_gets(line,LEN)!=NULL && line[0]!='\0')
    {
        index=showmenu();
        while(index>=0 && index<=3)
        {
            strcpy(copy,line);
            show(arpf[index],copy);
            index=showmenu();
        }
    }
    puts("Bye!");

    return 0;
}

int showmenu(void)
{
    char ans;
    char anss[5]={'u','l','t','o','n'};
    int i;
    puts("Enter menu choice:");
    puts("u.uppercase   l.lowercase");
    puts("t.transposed case o.oringal case");
    puts("n.next string");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while(strchr("ulton",ans)==NULL)
    {
        puts("Please enter a u,l,t,o,or n:");
        ans = tolower(getchar());
        eatline();
    }

    for(i=0;i<5;i++)
    {
        if(anss[i]==ans) //不能用strcmp来比较，因为strcmp的参数是两个字符串，而anss[i]不是字符，是指针
        {   
            //printf("ans is %d\n",i);
            break;
        }
    }
    return i;
}

void eatline()
{
    while (getchar()!='\n')
        continue;
}

void ToUpper(char *str)
{
    while(*str)
    {
        *str = toupper(*str);
        str++;
    }
}

void ToLower(char *str)
{
    while(*str)
    {
        *str = tolower(*str);
        str++;
    }
}

void Transpose(char* str)
{
    while(*str)
    {
        if(islower(*str))
            *str = toupper(*str);
        else if(isupper(*str))
            *str = tolower(*str);
        str++;
    }
}

void Dummy(char * str)
{
    //不改变字符串
}

void show(void(*fp)(char*),char* str)
{
    (*fp)(str);
    puts(str);
}

char* s_gets(char* st,int n)
{
    char * ret_val;
    char * find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find=strchr(st,'\n');
        if(find)
            *find ='\0';
        else
        {
            while(getchar()!='\n')
                continue;
        }       
    }

    return ret_val;
}