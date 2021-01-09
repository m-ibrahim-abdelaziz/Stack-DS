#include <iostream>
#define MAXSTACK 100
#define StackEntry int
using namespace std;
typedef struct stack
{
    int top;
    StackEntry entry[MAXSTACK];
}Stack;
void CreatStack(Stack* ps)
{
    ps->top = 0;
}
void push(StackEntry e, stack* ps)
{
    ps->entry[ps->top] = e;
    ps->top++;
}
int StackFull(Stack* ps)
{
    if (ps->top == MAXSTACK)
        return 1;
    else

        return 0;
}
void pop(StackEntry *pe,Stack *ps)
{
      ps->top--;
      *pe=ps->entry[ps->top];
}
int StackEmpty(Stack *ps)
{
    if (ps->top==0)
        return 1;
    else
        return 0;
}
void StackTop(StackEntry *pe,Stack *ps)
{
    *pe=ps->entry[ps->top-1];
}
int StackSize(Stack *ps)
{
    return ps->top;
}
void ClearStack(Stack *ps)
{
    ps->top=0;
}
void TraverseStack(Stack *ps,void(*pf) (StackEntry))
{
    for (int i=ps->top;i>0;i--)
        (*pf)(ps->entry[i-1]);
}
int main()
{
    StackEntry e;
    Stack s;
    CreatStack(&s);
    if (!StackFull(&s))
    {
        push(e, &s);
    }
    if(!StackEmpty(&s))
    {
        pop(&e,&s);
    }
    StackTop(&e,&s);
    int x=StackSize(&s);
    ClearStack(&s);
}
