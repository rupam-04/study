#include<stdio.h>
#include<string.h>


int main()
{

    char ch[100];
    FILE *fp;
    //int i=0;
    fp = fopen("e:\\rupam.txt","w");
    if(fp==NULL)
    {
        printf("Sorry...cant open file ");
    }
    else
    {
        printf("\nEnter lines : ");
        while(strlen(gets(ch))!=0)
        {
            fputs(ch,fp);
            fputc('\n',fp);
        }
        printf("\n......Write Successful...\n");
    }

   fclose(fp);
    printf("\n\n\n\n");
    return 0;
}