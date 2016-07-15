#include<ctype.h>
#include<stdio.h>
#define max 50
struct stack
{
char data [max];
int top;
}s;
int precedence(char);
void init (struct stack *);
int empty(struct stack *);
int full (struct stack *);
char pop (struct stack *);
void push (struct stack *,char);
char gettop(struct stack *);
void main()
{

char x;
char token;
init (&s);
printf("enter infix exp.");
while((token=getchar())!='\n')
{
if(isalnum(token))
printf("%c",token);
else if(token=='(')
	push(&s,'(');
else if (token==')')
	while((x=pop(&s))!='(')
		printf("%c",x);
else
{
while(precedence(token) <= precedence(gettop(&s)) && !empty(&s))
{
x=pop(&s);
printf("%c",x);
}
push(&s,token);
}
}
while(!empty(&s))
{
x=pop(&s);
printf("%c",x);
}}
int precedence (char x)
{
if (x=='(')
return (0);
else if(x=='+' || x=='-')
return(1);
else if(x=='*' || x=='%')
return (2);
else
return (3);
}

void init(struct stack *s)
{
s->top=-1;
}
int empty(struct stack * s)
{
if (s->top == -1)
	return(1);
return(0);
//return(s->top==-1);
}
int full(struct stack *s)
{
return(s->top==max-1);
}
void push(struct stack *s,char x)
{
if(!full(s))
{
s->top=s->top+1;
s->data[s->top]=x;
}
else
printf("stack is full");
}

char  pop(struct stack *s)
{
char x;
x=s->data[s->top];
s->top=s->top-1;
return(x);
}

char gettop(struct stack *s)
{
	return(s->data[s->top]);
}
