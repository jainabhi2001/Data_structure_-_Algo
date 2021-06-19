/* Program :Implement menu driven program for operations (enqueue,dequeue) on a queue using arrays. Check the status of the stack whether there is underflow or overflow. 
   Max size of Stack = 5    
   
   // Using approach that circular queue of size N takes N-1 entries, so we take N from user and perform on N+1                                                                */

#include<iostream>
#include<process.h>

using namespace std;

const int N=5;   // Took N=N+1 = 5+ 1 because our algo takes N entries for N+1 array 
int Q[5];
int front=-1; // Front- Intially it is 0, because no value in array stack.
int rear=-1; //  Rear- Intially it is 0, because no value in array stack.
void traverse()
{
    if(front==-1 && front==-1)
        cout<<"\n Can't print because Queue is Empty/Underflow";
    else if (front<=rear)
    {
        cout<<"\n QUEUE : "; 
        for (int i=front;i<=rear;i++)
        {cout<<Q[i]<<"<-";}
    }
    else if(front >rear )
    {
        cout<<"\n QUEUE : "; 
        for (int i=front;i<N;i++)
        {cout<<Q[i]<<"<-";}
        for (int i=0;i<=rear;i++)
        {cout<<Q[i]<<"<-";}
    }
}

void enqueue(){
    int value=0;
    if ((rear+1)%N==front)
    {
        cout<<"\n Can't enter into Queue, because queue is overflow";
    }
    else
    {
        cout<<"\n Enter the value to be entered into Queue:";
        cin>>value;
        if(front==-1 && rear==-1)
        {
            front=rear=0;
            Q[rear] = value;
        }
        else
        {
            rear=(rear+1)%N;
            Q[rear] = value;

        }
    }
}

void dequeue()
{
    int value=0;
    if (front==-1) 
    {
        cout<<"\n Can't delete from Queue, because queue is underflow";
    }
    else
    {
        value=Q[front];
        if(front==rear)
        {front=-1;rear=-1;}
        else
        front=(front+1)%N;
        cout<<"\n The popped value is : "<<value;
    }
}

void ele(){
    if(front==-1 && rear==-1)
    {
        cout<<"\n No value, because queue is underflow";
    }
    else if (front==rear)
    {
        cout<<"\n In Queue, front and last element is '"<<Q[front]<<"'"<<endl;
    }
    else
    cout<<"\n In Queue, front element is '"<<Q[front]<<"' and last element is '"<<Q[rear]<<"'"<<endl;
}

int main()
{
    int ch;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    do
    {
        cout<<"\n Menu:";
        cout<<"\n 1. Transverse/Print through Queue";
        cout<<"\n 2. Enter into queue";
        cout<<"\n 3. Delete from queue";
        cout<<"\n 4. Front and Rear elements of queue";
        cout<<"\n 5. Exit";
        cout<<"\n Size of Queue : ";
        {
            if((front==-1) && (rear==-1)) cout<<"0";
            else if(front<=rear) cout<<rear-front+1;
            else cout<<(N-front)+(rear-0+1);
        }
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:traverse();break;
            case 2:enqueue();traverse();break; 
            case 3:dequeue();traverse();break;
            case 4:ele();break;
            case 5:exit(0);
        }
    } while (ch<=5);
    return 0;
}
