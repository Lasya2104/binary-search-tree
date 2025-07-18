#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
struct Stack 
{
    int top;
    int maxSize;
    int* arr;
};
Stack* createStack(int size) 
{
    Stack* stack =new Stack;
    stack->maxSize= size;
    stack->top=-1;
    stack->arr=new int[size];
    return stack;
}
bool isEmpty(Stack* stack) 
{
    return stack->top == -1;
}
bool isFull(Stack* stack)
{
    return stack->top == stack->maxSize - 1;
}
void push(Stack* stack, int value) 
{
    if (isFull(stack)) {
        cout << "Stack Overflow!" << endl;
        return;
    }
    stack->arr[++stack->top] = value;
}
void pop(Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        cout <<"Stack Underflow!"<< endl;
        return;
    }
    stack->top--;
}
int top(Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        cout <<"Stack is empty!"<< endl;
        return -1;
    }
    return stack->arr[stack->top];
}
int size(Stack* stack) 
{
    return stack->top + 1;
}
void display(Stack* stack) 
{
    if (isEmpty(stack)) 
	{
        cout <<"Stack is empty!"<< endl;
        return;
    }
    cout <<"Stack(Top to Bottom): ";
    for (int i = stack->top; i >= 0; i--) 
	{
        cout << stack->arr[i] << " ";
    }
    cout << endl;
}
#endif