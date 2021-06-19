// Program: Implement stacks and queues using linked list - use single linked list

#include<iostream>
#include<process.h>

using namespace std;
struct node
{
    int info;
    node *next;
    node(int val)
    {
        info=val;
        next=NULL;
    }
};

void traverse(node * &topofstack)
{
    if(topofstack==NULL)
        cout<<"\n Can't print because stack is Empty/Underflow";
    else
    {
        cout<<"\n STACK : "; 
        node * list=topofstack;
        while(list!=NULL)
        {
            cout<<list->info<<"<-";
            list=list->next;
        }
        cout<<"NULL";
    }
}

void push(node * &topofstack){
    int value=0;
    cout<<"\n Enter the value to be entered into stack:";
    cin>>value;
    node *ptr = new node(value);
    if(topofstack==NULL)
    {
        topofstack=ptr;
    }
    else
    {
        ptr->next=topofstack;
        topofstack=ptr;
    }   
}

void pop(node * &topofstack){
    int value=0;
    if (topofstack==NULL)
    {
        cout<<"\n Can't Pop from Stack, because stack is empty/underflow";
    }
    else
    {
        value = topofstack->info;
        topofstack=topofstack->next;
        cout<<"\n The deleted value is : "<<value;
    }
}

void Qtraverse(node * &front,node * &rear)
{
    if(front==NULL && rear==NULL)
        cout<<"\n Can't print because Queue is Empty/Underflow";
    else
    {
        node * list=front;
        cout<<"\n QUEUE : "; 
        while(list!=NULL)           // By NULL I refer to ptr next to 'rear'
        {
            cout<<list->info<<"<-";
            list=list->next;
        }
        cout<<"NULL";
    }
}

void enqueue(node * &front,node * &rear)
{
    int value=0;
    cout<<"\n Enter the value to be entered into queue:";
    cin>>value;
    node *ptr = new node(value);
    if(front==NULL && rear==NULL)
    {
        front=ptr;
        rear=ptr;
    }
    else
    {
        rear->next=ptr;
        rear=ptr;
    }
}

void dequeue(node * &front,node * &rear)
{
    int value=0;
    if (front==NULL && rear==NULL) 
    {
        cout<<"\n Can't delete from Queue, because queue is underflow";
    }
    else if(front==rear)
    {
        value = front->info;
        front=NULL;rear=NULL;
        cout<<"\n The deleted value is : "<<value;

    }
    else
    {
        value = front->info;
        front=front->next;
        cout<<"\n The Deleted value is : "<<value;
    }
}

int main()
{
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    int DSAchoice;
    cout<<"\n Menu ";
    cout<<"\n 1. Stack using Linked List";
    cout<<"\n 2. Queue using Linked List";
    cout<<"\n Enter the choice:";
    cin>>DSAchoice;
    if(DSAchoice==1) 
        {
            int ch, value;
            node * tos=NULL;  
            do
            {
                cout<<"\n Stack Linked List Menu ";
                cout<<"\n 1. Transverse/Print through Stack";
                cout<<"\n 2. Push into stack";
                cout<<"\n 3. Pop from stack";
                cout<<"\n 4. Exit";
                cout<<"\n Enter the choice:";
                cin>>ch;
                switch(ch)
                {
                    case 1:traverse(tos);break;
                    case 2:push(tos);traverse(tos);break; 
                    case 3:pop(tos);traverse(tos);break;
                    case 4:exit(0);
                }
            } while (ch<=4);
        }
    else if(DSAchoice==2) 
        {
            int ch,value;   
            node * front=NULL;
            node * rear=NULL; 
            do
            {
                cout<<"\n Queue Linked List Menu:";
                cout<<"\n 1. Transverse/Print through Queue";
                cout<<"\n 2. Enter into queue";
                cout<<"\n 3. Delete from queue";
                cout<<"\n 4. Exit";
                cout<<"\n Enter the choice:";
                cin>>ch;
                switch(ch)
                {
                    case 1:Qtraverse(front,rear);break;
                    case 2:enqueue(front,rear);Qtraverse(front,rear);break; 
                    case 3:dequeue(front,rear);Qtraverse(front,rear);break;
                    case 4:exit(0);
                }
            } while (ch<=4);
        }
    else
    {
        cout<<"\n Wrong choice";
    }
    return 0;
}
