// WAP that will count the number of line, 
// characters and words
// from a file and write the result into another
// file. 



#include<stdio.h>
#include<string.h>


int main()
{
   FILE *fp,*ft;
int line=0,che=0,word=0;
char ch;
fp = fopen("e://rupam.txt","r");
ft = fopen("e://result.txt","w");

if(fp==NULL || ft==NULL)
{
	printf("Unsuccessful operation.....\n");
	exit(0);
}
ch=fgetc(fp);
while(ch!=EOF)
{
	if(ch==' ' || ch=='\n')
	{
		word++;
		if(ch=='\n')
			line++;
	}
	che++;
	ch=fgetc(fp);
}
fprintf(ft, "No of Lines = %d\n",line);
fprintf(ft, "No of Words = %d\n",word);
fprintf(ft, "No of Characters = %d\n",che);
fclose(fp);
fclose(ft);
printf("Operation successful....");
    printf("\n\n\n\n");
    return 0;
}