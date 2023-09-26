//INFIX TO POSTFIX CONVERSION
#include<stdio.h>
#include<string.h>

int main()
{
    char s[50],s1[50],s2[50];
    int top=-1,i=0,l,n=0;

    printf("Enter an Infix expression : :");
	gets(s);


    top++;
    s1[top]='(';

    l=strlen(s);
    s[l] = ')';
    s[l+1]='\0';

    while(s[i]!='\0')
    {
        //if the element is (
        if(s[i]=='(')
        {
            top++;
            s1[top]=s[i];
        }
        else if(s[i]!='^'&&s[i]!='*'&&s[i]!='/'&&s[i]!='+'&&s[i]!='-'&&s[i]!=')')
        {
            // the element is an operand
            s2[n]=s[i];
            n++;
        }
        else
        {
            // the element is an operator
            if(s[i]=='+'||s[i]=='-')
            {
                while(s1[top]=='+'||s1[top]=='-'||s1[top]=='*'||s1[top]=='/'||s1[top]=='^')
                {
                    s2[n]=s1[top];
                    n++;
                    top--;
                }
                top++;
                s1[top]=s[i];
            }
            else if(s[i]=='*'||s[i]=='/')
            {
                while(s1[top]=='*'||s1[top]=='/'||s1[top]=='^')
                {
                    s2[n]=s1[top];
                    n++;
                    top--;
                }
                top++;
                s1[top]=s[i];
            }
            else if(s[i]=='^')
            {
                while(s1[top]=='^')
                {
                    s2[n]=s1[top];
                    n++;
                    top--;
                }
                top++;
                s1[top]=s[i];
            }
            else{
                while(s1[top]!='(')
                {
                    s2[n] = s1[top];
                    n++;
                    top--;
                }
                top--;
            }
        }
        i++;
    }

	s2[n]='\0';

	printf("\n\nThe Equivalent Postfix expression is :\n");
	printf("===============================================\n");
	printf("\t");

	puts(s2);

	printf("\n\n");
	return 0;
}