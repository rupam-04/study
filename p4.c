#include<stdio.h>
#include<string.h>


int main()
{
    FILE *fp;
    int i,a;
    fp = fopen("e:\\rupam.txt","w");
    if(fp==NULL)
    {
        printf("Sorry...cant open file ");
    }
    else
    {
        for(i=0;i<5;i++)
        {
            printf("\nEnter number : ");
            scanf("%d",&a);
            fprintf(fp,"%d",a);
            fputc('\n',fp);
        }

        printf("\n......Write Successful...\n");
    }

   fclose(fp);
   fp = fopen("e:\\rupam.txt","r");
    for(i=0;i<5;i++)
        {

            fscanf(fp,"%d",&a);
            printf("   %d ",a);
        }
    fclose(fp);
    printf("\n\n\n\n");
    return 0;
}