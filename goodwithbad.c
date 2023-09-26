#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *fp, *ofp;
    char ch, s1[100];
    fp = fopen("C:\\Users\\rpmde\\OneDrive\\Desktop\\CSE\\goodbad.txt","r");
    ofp = fopen("C:\\Users\\rpmde\\OneDrive\\Desktop\\CSE\\ans.txt","w");
    if(fp==NULL || ofp==NULL)
    {
        printf("Sorry...cant open file ");
    }
    else
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s", s1);
            if (strcmp(s1, "good")==0)
            {
                strcpy(s1, "bad");
            }
            fprintf(ofp, "%s", s1);
        }
        fclose(fp);
        fclose(ofp);
    }
    return 0;
}