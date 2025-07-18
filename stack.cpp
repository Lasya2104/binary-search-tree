#include"STACK.h"
int main() 
{
    Stack* s = createStack(5);
    push(s,10);
    push(s,1);
    push(s,15);
    display(s); 
    cout <<"Top element in the stack: "<< top(s) << endl;
    pop(s);
    display(s); 
    cout <<"Stack size: "<< size(s) << endl;
}