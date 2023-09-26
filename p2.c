#include<stdio.h>
#include<string.h>


int main()
{

    char ch[] = "Hello This is an Example\nGood Bye";
    FILE *fp;
    int i=0;
    fp = fopen("e:\\rupam.txt","w");
    if(fp==NULL)
    {
        printf("Sorry...cant open file ");
    }
    else
    {
        while(ch[i]!='\0')
        {
            fputc(ch[i],fp);
            i++;
        }
        printf("\n......Write Successful...\n");
    }

   fclose(fp);
    printf("\n\n\n\n");
    return 0;
}