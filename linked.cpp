#include <iostream>
#include<stdlib.h>
#define StackEntry int
using namespace std;
typedef struct stacknode
{
    StackEntry entry;
    struct stacknode *next;
}StackNode;
typedef struct Stack
{
    StackNode *top;
    int Size;
}Stack;
void CreateStack(Stack *ps)
{
    ps->top=NULL;
    ps->Size=0;
}
void push(StackEntry e,Stack *ps)
{
    StackNode *pn=(StackNode*)malloc(sizeof(StackNode));
    pn->entry=e;
    pn->next=ps->top;
    ps->top=pn;
    ps->Size++;

}
void pop(StackEntry *pe,Stack *ps)
{
    StackNode *pn;
    *pe =ps->top->entry;
    pn=ps->top;
    ps->top=ps->top->next;
    free(pn);
    ps->Size--;
}
int StackEmpty(Stack *ps)
{
    return ps->top==NULL;
}
int StackFull(Stack *ps)
{
    return 0;
}
void ClearStack(Stack *ps)
{
    StackNode *pn=ps->top;
    StackNode *qn=ps->top;
    while(pn)
    {
        pn=pn->next;
        free(qn);
        qn=pn;
    }
    ps->top=NULL;
     ps->Size=0;
}
int StackSize(Stack *ps)
{
    return ps->Size;
}
int main()
{
   Stack s;
   CreateStack(&s);
   StackEntry e;
   if (!StackFull(&s))
        push(e,&s);
   if (!StackEmpty(&s))
        pop(&e,&s);
    ClearStack(&s);
    StackSize(&s);
}
