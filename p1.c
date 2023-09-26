#include<stdio.h>
#include<string.h>

struct stud
{
    char name[20];
    int roll;
};
int main()
{
    struct stud s = {"Rahul Das",25};
    struct stud ss = {"Sumit Singh",10};
    struct stud s1;
    FILE *fp;

    fp = fopen("rupam.txt","w");
    if(fp==NULL)
    {
        printf("Sorry...cant open file ");
    }
    else
    {
        fwrite(&s,sizeof(struct stud),1,fp);

        fwrite(&ss,sizeof(struct stud),1,fp);
        printf("\n......Write Successful...\n");
    }
    /*else
    {
        printf("Thank you.....file opened successfully\n\n\n");
        count = fread(&s,sizeof(char),19,fp);
        printf("The file contents are:\n");
        printf("===============================\n\n");

        printf("\n   %s",s);
        printf("\n Total = %d",count);
    }*/
    fclose(fp);

    fp = fopen("e:\\rupam.txt","r");
    if(fp==NULL)
    {
        printf("Sorry...cant open file ");
    }
    else
    {
        fread(&s1,sizeof(struct stud),1,fp);
        printf("\n\n The data read from file....\n----------------------\n\n");
        printf("   Name = %s\n   Roll = %d",s1.name,s1.roll);
        fread(&s1,sizeof(struct stud),1,fp);
        printf("\n\n\n");
        printf("   Name = %s\n   Roll = %d\n\n",s1.name,s1.roll);
    }
    printf("\n\n\n\n");
    return 0;
}