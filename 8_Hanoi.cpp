// Program : Implement Tower of Hanoi problem

#include<iostream>
using namespace std;
/*
int step=0;
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
{
    if (n == 1)
    {
        step+=1;
        cout << "Move disk 1 from rod " << from_rod <<" to rod " << to_rod<<"\t - Step:"<<step<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, to_rod, aux_rod); // Now here to_rod acts as a auxilary
    step+=1;
    cout << "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod <<"\t - Step:"<<step<< endl;
    towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
}

int main()
{
    int n = 3; // Number of disks
    towerOfHanoi(n, 'S', 'A', 'D'); // Source, Auxilary and Destination are the rods.
    return 0;
}
*/

int step=0;
void towerOfHanoi(int n, char from_rod, char aux_rod, char to_rod)
{
    if (n == 1)
    {
        step+=1;
        cout << "Move disk 1 from rod " << from_rod <<" to rod " << to_rod<<"\t - Step:"<<step<<endl;
        return;
    }
    towerOfHanoi(n - 1, from_rod, to_rod, aux_rod); // Now here to_rod acts as a auxilary
    step+=1;
    cout << "Move disk " << n << " from rod " << from_rod <<" to rod " << to_rod <<"\t - Step:"<<step<< endl;
    towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
}

int main()
{
	cout<<"******02216412819*******"<<endl;
	cout<<"*****Abhishek Jain*****"<<endl;
    int n=0; // Number of disks
    cout<<"\n Enter the number of disks present in Source Rod: ";
    cin>>n;
    towerOfHanoi(n, 'S', 'A', 'D'); // Source, Auxilary and Destination are the rods.
    return 0;
}
