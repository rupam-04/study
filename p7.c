//FILE COPY PROGRAM USING COMMAND LINE ARGUMENT


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char *argv[])
{
  FILE *fp,*ft;

   if(argc!=3)
   {
       printf("\nWrong argument passing....");
       exit(0);
   }

   fp = fopen(argv[1],"r");
   ft = fopen(argv[2],"w");


   struct stud
   {
       char name[20];
       int age;
   };

   struct stud s;

    fread(&s,sizeof(struct stud),1,fp);
    fwrite(&s,1,sizeof(struct stud),ft);

    fread(&s,sizeof(struct stud),1,fp);
    fwrite(&s,1,sizeof(struct stud),ft);

   fclose(fp);
   fclose(ft);

   printf("\n\n File copied successfully......");

    return 0;
}