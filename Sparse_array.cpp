// Program 2.	Implement sparse matrix

#include <iostream>

using namespace std;

int main()
{
    cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    int arr[10][10];
    int n=0, m=0;
    int row=0,column=3;
    cout<<"\n Enter the size of sparse matrix (row,column): ";
    cin>>n>>m;
    cout<<"\n Enter the values into sparse matrix : ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!=0)
            {
                row=row+1;
            }
        }
    }
    if(row>(m*n/4))                 // Assumed 25% criteria
    cout<<"\n Sorry but the entered matrix is not a sparse matrix ";
    else
    {
        cout<<"\n Congrats! the entered matrix is a sparse matrix ";
        row=row+1;
        int res[row][column];int k=0;
        res[k][0]=n; res[k][1]= m; res[k][2]= row-1; k=k+1;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(arr[i][j]!=0)
                {
                    res[k][0]=i;
                    res[k][1]=j;
                    res[k][2]=arr[i][j];
                    k=k+1;
                }
            }
        } 
        cout<<"\n The calculated triplet matrix is as follows:"<<endl;  
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<column;j++)
            {
                cout<<res[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}
