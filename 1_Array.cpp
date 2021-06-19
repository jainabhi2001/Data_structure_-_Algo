// Program:	Implement menu driven program for operations (traverse, insert , delete, linear search, selection sort ) on an  array.

#include<iostream>
#include<process.h>
#include<cstring>

using namespace std;
const int N=20;
int A[N];
int n=0;

void traverse()
{
    if(n==0)
        cout<<"\n Can't traverse the array because it is empty";
    else
    {
        for (int i=0;i<n;i++)
        cout<<A[i]<<"\t";
    }
}

void insertAtBeg(int value){
    for(int i=n;i>0;i--)
    A[i]=A[i-1];
    A[0]=value;
    n+=1;
}
void insertAtEnd(int value){ A[n]=value; n+=1;}
void insertAtPos(int value,int position){
    position=position-1;
    for(int i=n;i>position;i--)
    A[i]=A[i-1];
    A[position]=value;
    n+=1;
}

void deleteAtBeg(){
    for(int i=0;i<n;i++)
    A[i]=A[i+1];
    n-=1;
}
void deleteAtEnd(){ n-=1;}
void deleteAtPos(int position){
    position=position-1;
    for(int i=position;i<n;i++)
    A[i]=A[i+1];
    n-=1;
}

void LinearSearch(int value)
{
    int flag=0;
    int position=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]== value)
        {
            flag=1;
            position=i+1;break;
        }
    }
    if(flag==1)
    {cout<<"\n Value was found at "<<position<<" position"; }
    else
    cout<<"\n Sorry the value is not present in the array";
}

void SelectionSort()
{
    int j,k,small,pos,temp;
    for(j=0;j<n;j++)
    {
        small=A[j]; pos=j;
        for(k=j+1;k<n;k++)
        {
            if(small>A[k])
            {
                small=A[k];pos=k;
            }
        }
    temp=A[j];A[j]=A[pos];A[pos]=temp;
    }
    cout<<"\n Sorting completed";

}

int main()
{
    int ch;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    do
    {
        cout<<"\n Menu:";
        cout<<"\n 1. Transverse/search a value";
        cout<<"\n 2. Insert a value";  // 3 functions - 8:00 check video
        cout<<"\n 3. Delete a value";
        cout<<"\n 4. Linear search";
        cout<<"\n 5. Selection sort ";
        cout<<"\n 6. Exit";
        cout<<"\n Size of array : "<<n;
        cout<<"\n Enter the choice:";
        cin>>ch;
        switch(ch)
        {
            case 1: traverse();break;

            case 2: if(n==0)  // for first element
                    {
                        cout<<"\n Enter the first element:";
                        cin>>A[0]; n+=1;
                    }
                    else
                    {
                        char choice[10];
                      	int val=0,pos=0;
                        cout<<"\n Do you want to insert value at 'begin','end' or a 'position':";
                        cin>> choice;                        
                        cout<<"\n Enter the value to be inserted";
                        cin>> val;                        
                        if (strcmp(choice,"begin")==0) {insertAtBeg(val);}
                        else if (strcmp(choice,"end")==0) {insertAtEnd(val);}
                        else if (strcmp(choice,"position")==0) 
                        {
                            cout<<"\n Enter the position at which value is to be inserted:";
                            cin>> pos;
                            if (pos>n)
                            {
                                cout<<"\n Entered position is greater than available array";
                            }
                            else{
                            insertAtPos(val,pos); 
                            }
                        }                                                            
                    }
                    cout<<"\n";traverse();
                    break;
                    
            case 3: if(n==0)  // for first element
                    {
                        cout<<"\n Array is empty, deletion can't be performed:";
                    }
                    else
                    {
                        char choice[10];
                      	int pos=0;
                        cout<<"\n Do you want to delete value at 'begin','end' or a 'position':";
                        cin>> choice;
                        if (strcmp(choice,"begin")==0) {deleteAtBeg();}
                        else if (strcmp(choice,"end")==0) {deleteAtEnd();}
                        else if (strcmp(choice,"position")==0) 
                        {
                            cout<<"\n Enter the position which is to be deleted:";
                            cin>> pos;
                            if (pos>n)
                            {
                                cout<<"\n Entered position is greater than available array";
                            }
                            else{
                                deleteAtPos(pos); 
                            }
                        }                                                            
                    }
                    cout<<"\n";traverse();
                    break;
            case 4: {int val=0; 
                    cout<<"\n Enter the value that you want to search";
                    cin>>val;
                    if (n==0)
                        {
                            cout<<"\n Array is empty";
                        }
                    else{
                            LinearSearch(val);
                        }
                    break;}

            case 5:{
                    if (n==0) {  cout<<"\n Array is empty";   }
                    else
                    {   SelectionSort();    }
                    cout<<"\n";traverse();
                    break;}
            case 6: exit(0);
        }
    } while (ch<=6);
    return 0;
}
