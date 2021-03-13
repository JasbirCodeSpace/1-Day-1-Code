#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#define SIZE 50 /* Size of Stack */
 
int postfix_stack[SIZE];
int infix_stack[SIZE];
int infix_top=-1; 
int postfix_top=-1; 
int flag=0;

int postfix_pop();
void postfix_push(int elem);
char infix_pop();
void infix_push(char item);
int precedence(char x);
int isOperator(char symbol);
void infixToPostfix(char infix[], char postfix[]);
int postfixEvaluate(char postfix[]);

FILE* fptr = NULL;
int main(){
  char infix[50], postfix[50];

  printf("\nInfix Expression:");
  fptr = fopen("infix.txt", "r");
  fgets(infix,100,fptr);
  printf("%s", infix);
  fclose(fptr);

  infixToPostfix(infix, postfix);
  printf("\nPostfix Expression: %s", postfix);
  fptr = fopen("postfix.txt", "w");
  fprintf(fptr, "%s", postfix);
  fclose(fptr);

  int result = postfixEvaluate(postfix);
  printf("\nResult: %d",result);
  fptr = fopen("result.txt", "w");
  fprintf(fptr, "Result: %d", result);
  fclose(fptr);

  return 0;

}

int postfix_pop()
{                      /*  POP operation */
  return(postfix_stack[postfix_top--]);
}
 
void postfix_push(int elem)
{                     /*  PUSH operation */
  if(flag==1){
    int num;
    num=postfix_pop();
    postfix_stack[++postfix_top]=elem+10*num;
  }
  else if(flag==0){
    postfix_stack[++postfix_top]=elem;
    flag=1;
  }
}


void infix_push(char item)
{
	if(infix_top >= SIZE-1)
	{
		printf("\nStack Overflow.");
	}
	else
	{
		infix_top++;
		infix_stack[infix_top] = item;
	}
}

char infix_pop()
{
	char item ;

	if(infix_top <0)
	{
		printf("stack under flow: invalid infix expression");
		exit(1);
	}
	else
	{
		item = infix_stack[infix_top];
		infix_top = infix_top-1;
		return(item);
	}
}


int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
        return 3;
    return 0;
}

int isOperator(char symbol)
{
	if(symbol == '^' || symbol == '*' || symbol == '/' || symbol == '+' || symbol =='-')
	{
		return 1;
	}
	else
	{
	return 0;
	}
}

void infixToPostfix(char infix[], char postfix[]){
    int i, j;
    char item;
    char x;

    infix_push('(');                               /* push '(' onto stack */
    strcat(infix,")");                  /* add ')' to infix expression */

    i=0;
    j=0;
    item=infix[i];         /* initialize before loop*/

   
    while(item != '\0')        /* run loop till end of infix expression */
    {
      if(item == ' '){
        // do nothing
      }
      else if(item == '(')
      {
        infix_push(item);
      }
      else if( isdigit(item) || isalpha(item))
      {
        postfix[j] = item;              /* add operand symbol to postfix expr */
        j++;
        postfix[j++] = ' ';
      }
      else if(isOperator(item) == 1)        /* means symbol is operator */
      {
        x=infix_pop();
        while(isOperator(x) == 1 && precedence(x)>= precedence(item))
        {
          postfix[j] = x;                  /* so pop all higher precendence operator and */
          j++;
          postfix[j++] = ' ';
          x = infix_pop();                       /* add them to postfix expresion */
        }
        infix_push(x);
        /* because just above while loop will terminate we have
        oppped one extra item
        for which condition fails and loop terminates, so that one*/

        infix_push(item);                 /* push current oprerator symbol onto stack */
      }
      else if(item == ')')         /* if current symbol is ')' then */
      {
        x = infix_pop();                   /* pop and keep popping until */
        while(x != '(')                /* '(' encounterd */
        {
          postfix[j] = x;
          j++;
          postfix[j++] = ' ';
          x = infix_pop();
        }
      }
      else
      { 
        printf("\nInvalid infix Expression.\n");
        exit(1);
      }
      i++;
      item = infix[i]; 
    }
    if(infix_top>0)
    {
      printf("\nInvalid infix Expression.\n"); 
      exit(1);
    }

    postfix[j] = '\0'; 
}

int postfixEvaluate(char postfix[]){

  char ch;
  int i=0, op1, op2;
  while( (ch=postfix[i++]) != '\0')
  {
    if(isdigit(ch)) postfix_push(ch-'0'); /* Push the operand */
    else if(ch==' ')
      flag=0;
    else
    { 
      flag=0;
      op2=postfix_pop();
      op1=postfix_pop();
      switch(ch)                            /* performing corresponding operation */
      {
        case '+':postfix_push(op1+op2);break;
        case '-':postfix_push(op1-op2);break;
        case '*':postfix_push(op1*op2);break;
        case '/':postfix_push(op1/op2);break;
        case '^':postfix_push(pow(op1, op2)); break;
        default:
                 printf("Input invalid ... give proper input\n");
                 exit(0);
      }
    }
  }
  return postfix_stack[postfix_top];          // returing result present on top of stack
}