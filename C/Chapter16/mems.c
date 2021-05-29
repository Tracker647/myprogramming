#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 10

void show_array(const int ar[],int n);

int main()
{
    int values[SIZE]={1,2,3,4,5,6,7,8,9,10};
    double target[SIZE];
    double curious[SIZE/2]={2.0,2.0e5,2,2.0e20,5};

    puts("memcpy( used:");
    puts("values (oringal data):");
    show_array(values,SIZE);
    memcpy(target,values,SIZE*sizeof(int));
    puts("target (copy of values):");
    show_array(target,SIZE);

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target,curious,(SIZE/2)*sizeof(double));
    puts("target--5 doubles into 10 int positions:");
    show_array(target,SIZE/2);
    show_array(target+5,SIZE/2);

    return 0;

}

void show_array(const int ar[],int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%d ",ar[i]);
    putchar('\n');
}