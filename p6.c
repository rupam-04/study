#include<stdio.h>
#include<string.h>


int main()
{
   FILE *fp;
   fp = fopen("e:\\rupam.txt","w");
   struct stud
   {
       char name[20];
       int age;
   };
   struct stud s1 = {"Rahul Das",20};
   struct stud s2 = {"Priya Das",19};

   fwrite(&s1,1,sizeof(struct stud),fp);
   fwrite(&s2,1,sizeof(struct stud),fp);

   fclose(fp);
   fp = fopen("e:\\rupam.txt","r");

   struct stud s3,s4;

   fread(&s3,sizeof(struct stud),1,fp);
   fread(&s4,sizeof(struct stud),1,fp);

   printf("\n\n   Name = %s     Name = %s",s3.name,s4.name);
   printf("\n\n   Age = %d     Age = %d",s3.age,s4.age);

   fclose(fp);
    return 0;
}