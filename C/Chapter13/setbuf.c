#include <stdio.h>

int main()
{

   char buff[1024];

   memset( buff, '\0', sizeof( buff ));

   fprintf(stdout, "����ȫ����\n");
   setvbuf(stdout, buff, _IOFBF, 1024);

   fprintf(stdout, "������ runoob.com\n");
   fprintf(stdout, "����������浽 buff\n");
   fflush( stdout );

   fprintf(stdout, "�⽫�ڱ��ʱ����\n");
   fprintf(stdout, "�������������\n");

   sleep(5);

   return(0);
}