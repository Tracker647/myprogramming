#define _MYLIBRARY_H_
#ifndef _MYLIBRARY_H_
void swapStu(Stu *a,Stu *b)    //交换结构体数组的属性
{
    Stu temp;

    temp.order  =   a->order;
    temp.name   =   a->name ;
    temp.score  =   a->score;

    a->order     =   b->order;
    a->name      =   b->name ;
    a->score     =   b->score;

    b->order     =   temp.order;
    b->name      =   temp.name ;
    b->score     =   temp.score;
}

void SelectSort_Stu(Stu *p,int choose)   //用选择排序来排序结构体数组，指针操作
{
    Stu *min = p;
    Stu *head = p;
    while((head+1)->score!='\000')
    {
        while((p+1)->score!='\000')
        {
            if(choose == 0)
            {
                if(p->order < min->order)
                {
                    min = p;
                }
            }
           else if (choose == 1)
           {
               if(p->score < min->score)
                {
                    min = p;
                }
           }
           
            p++;
        }
        // printf("最小学号:%d\n",min->order);
        if(choose == 0)
        {
            if(head->order > min->order)
                swap(head,min);
        }
        else if(choose == 1)
        {
            if(head->score > min->score)
                swap(head,min);
        }
       
        head++;
        min = head;
        p = head;
    }
  
        
}


#endif