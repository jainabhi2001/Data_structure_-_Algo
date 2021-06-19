// Program 5. Implement binary search using recursion

#include<iostream>
#include<process.h>

using namespace std;
const int N=10;     //max size of array
int ARR[N];

void check_valid(int size)
{
    for (int i=1;i<size;i++) //starts checking from 2nd element means index=1
    {
        if(ARR[i]<ARR[i-1])
        {
            cout<<"\n Sorry the array is not sorted therefore can't perform Binary search";
            exit(1);
        }
    }
    cout<<"\n The input array is a sorted array therefore you can perform Binary Search";
}

void  binary_ser(int start,int end,int val)
{
    int mid=(start+end)/2;
    if ((start==end) && (ARR[mid]!=val))                // Base condition 1
    {
        cout<<"\n Sorry value not found";
    }
    else if (start==end || val==ARR[mid])               // Base condition 2 + General condition 1
    {
        cout<<"\n Value found at '"<<mid+1<<"' position";
    }

    else if (val<ARR[mid])                              // General condition 2
    {
        binary_ser(start,mid-1,val);
    }
    else if(val>ARR[mid])                             // General condition 3
    {
        binary_ser(mid+1,end,val);
    }

}

int main()
{
    int value=0;
    int size;
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    while(true)
    {
        cout<<"\n Enter the size of array (max size is 10): ";
        cin>>size;

        cout<<"Enter the values into the array: ";
        for(int i=0;i<size;i++)
        {      cin>>ARR[i];    }
        check_valid(size);
        cout<<"\n Enter the value that you want to search:";
        cin>>value;
        binary_ser(0,size-1,value);
    }

    return 0;
}