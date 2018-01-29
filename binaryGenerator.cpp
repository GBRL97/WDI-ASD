/* Gabriel Nowak,2701.2018
Generator of binary words (n bits)
*/
#include<iostream>
#include<cmath>
using namespace std;
void resetArray(int t[], int n)
{
    for(int i=0;i<n;i++)t[i]=0;
}
void printArray(int t[],int n)
{
    for(int i=0;i<n;i++)cout<<t[i];
    cout<<"\n";
}
void generateBin(int t[],int n)
{
    resetArray(t,n);
    double two=2.0;
    double exp=n;
    double power=pow(two,exp);
    printArray(t,n);
    int counter,tmp;
    for(int i=1;i<power;i++)
    {
        tmp=i;
        counter=n-1;
        resetArray(t,n);
        while(tmp>0)
        {
            t[counter]=tmp%2;
            tmp=tmp/2;
            counter--;
        }
        printArray(t,n);
    }
}

int main()
{
    int n;
    cin>>n;
    int *t=new int[n];
    generateBin(t,n);


    return 0;
}
