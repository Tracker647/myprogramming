#include <stdio.h>
#include <stdlib.h>
#define N 10
typedef struct{
	int order;
	float score;
}Stu,*pStu;



void Initlize(Stu *p)
{
    int i;
    for(i=0;i<N;i++)
    {
        (p+i)->order = '\000';
        (p+i)->score = '\000';
    }
}
void arrPrint(pStu student)
{
	int i;
	for(i=0;i<N;i++)
	{
		printf("%d %5.2f\n",student[i].order,student[i].score);
	}
}
int compare(const void* pleft,const void* pright)
{
	pStu p1=(pStu)pleft;
	pStu p2=(pStu)pright;
	if(p1->order>p2->order)
	{
		return 1;
	}else if(p1->order<p2->order)
	{
		return -1;
	}else{
		return 0;
	}
}
int mycompare(const void *a,const void *b)
{
    Stu *p1 = (Stu*)a;
    Stu *p2 = (Stu*)b;
    return p1->order > p2->order ? 1 : -1;
    
}

int structlen(Stu* p)
{
    int len;
    for (len = 0; (p->order)>0 ; len++, p++)
    {

    }
    return len;
}
int main()
{
	Stu student[N];
	int i,len;
    Initlize(student);  //初始化结构体数组的值

    student[0].order = 402; //  初始化
    student[0].score = 79;

    student[1].order = 403;
    student[1].score = 62;

    student[2].order = 401;
    student[2].score = 83;

    student[3].order = 400;
    student[3].score = 83;



    // student[4].order = 409; //n=4
    // student[4].score = 83;

    // student[5].order = -1; //n+1做空防止野指针
    // student[5].score = -1;
    len = structlen(student);
	printf("Index:\n");
	arrPrint(student);
	qsort(student,len,sizeof(Stu),mycompare);
	printf("Sorted:\n");
	arrPrint(student);

    return 0;
}