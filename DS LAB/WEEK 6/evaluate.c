#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 50 /* Size of Stack */
 
int s[SIZE];
int top=-1; 
int flag=0;
int pop()
{                      /*  POP operation */
  return(s[top--]);
}
 
int push(int elem)
{ /*PUSH operation */
  if(flag==1){
    int num;
    num=pop();
    s[++top]=elem+10*num;
  }
  else if(flag==0){
    s[++top]=elem;
    flag=1;
  }
}
 
FILE* fptr = NULL;
int main()
{         
  char pofx[50],ch;
  int i=0,op1,op2;
  printf("Enter the Postfix Expression:");
  fptr = fopen("input.txt", "r");
  fgets(pofx,100,fptr);
  printf("%s", pofx);
  fclose(fptr);
  while( (ch=pofx[i++]) != '\0')
  {
    if(isdigit(ch)) push(ch-'0'); /* Push the operand */
    else if(ch==' ')
      flag=0;
    else
    {        /* Operator,pop two  operands */
      flag=0;
      op2=pop();
      op1=pop();
      switch(ch)
      {
        case '+':push(op1+op2);break;
        case '-':push(op1-op2);break;
        case '*':push(op1*op2);break;
        case '/':push(op1/op2);break;
        case '^': push(pow(op1, op2)); break;
        default:
                 printf("Input invalid ... give proper input\n");
                 return 0;
      }
    }
  }
  printf("\nResult: %d\n",s[top]);
  fptr = fopen("output.txt", "w");
  fprintf(fptr, "Result: %d\n", s[top]);
  fclose(fptr);
  return 0;
}