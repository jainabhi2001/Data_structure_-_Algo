/* Program 3. Implement menu driven program for operations (push, pop) on a stack using arrays. 
   Check the status of the stack whether there is underflow or overflow. 
   Max size of Stack = 5                                                                    */

#include<iostream>
#include<process.h>

using namespace std;

const int N=5;
int ST[5];
int tos=-1; // Top of stack- Intially it is -1, because no value in array stack.

void traverse()
{
    if(tos==-1)
        cout<<"\n Can't print because stack is Empty/Underflow";
    else
    {
        cout<<"\n STACK : "; 
        for (int i=0;i<=tos;i++)
        cout<<ST[i]<<"\t";
    }
}

void push(){
    int value=0;
    if (tos==N-1)
    {
        cout<<"\n Can't Push into Stack, because stack is overflow";
    }
    else
    {
        tos++;
        cout<<"\n Enter the value to be entered into stack:";
        cin>>value;
        ST[tos] = value;
    }
}

void pop(){
    int value=0;
    if (tos==-1)
    {
        cout<<"\n Can't Pop from Stack, because stack is underflow";
    }
    else
    {
        value = ST[tos];
        cout<<"\n The popped value is : "<<value;
        tos--;
    }
}
void top(){
    if(tos==-1)
    {
        cout<<"\n No value";
    }
    else
    cout<<"\n The topmost element in Stack is :"<<ST[tos];
}

int main()
{
    int ch;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    do
    {
        cout<<"\n Menu:";
        cout<<"\n 1. Transverse/Print through Stack";
        cout<<"\n 2. Push into stack";
        cout<<"\n 3. Pop from stack";
        cout<<"\n 4. Top element from stack";
        cout<<"\n 5. Check overflow";
        cout<<"\n 6. Check underflow";
        cout<<"\n 7. Exit";
        cout<<"\n Size of stack : "<<tos+1;
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:traverse();break;
            case 2:push();traverse();break; 
            case 3:pop();traverse();break;
            case 4:top();break;
            case 5:{
                if (tos==N-1) 
                    cout<<"\n Stack is overflow";
                else
                    cout<<"\n Stack is not overflow";
            }break;
            
            case 6:{
                if (tos==-1) 
                    cout<<"\n Stack is underflow";
                else
                    cout<<"\n Stack is not underflow";
            }break;
            case 7:exit(0);
        }
    } while (ch<=7);
    return 0;
}