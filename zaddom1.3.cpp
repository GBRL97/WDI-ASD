/*
Gabriel Nowak, 06.03.2019

heap - kopiec binarny
numer lewego syna = 2k + 1
numer prawego syna = 2k + 2

numer ojca = [(k - 1) / 2], dla k > 0

lewy syn istnieje, jeœli 2k + 1 < n

prawy syn istnieje, jeœli 2k + 2 < n

wêze³ k jest liœciem, jeœli 2k + 2 > n

zasada dzialania:
dwa kopce - max i min

jeœli nowy element x mniejszy od korzenia maxa - wstawiam do maxa
w przeciwnym wstawiam do mina
jeœli po wstawieniu d³ugoœæMax - d³ugoœæMin>1 usuwamy z Maxa korzeñ i wrzucamy go do Mina
jeœli po wstawieniu d³ugoœæMin-d³ugoœæMin>0 usuwamy z Min korzeñ i wrzucamy do Maxa
mediana to w przypadku parzystej liczby œrednia z korzeni, w przypadku nieparzystej korzeñ maxa
*/
#include<iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;
//n - do sprawdzania czy nie przekraczamy max. pojemnosci heap
void pushMax(int t[],int v, int n, int &length){
    int i=length;//indeks gdzie wstawiamy
    length++;
    int j=(i-1)/2;//indeks rodzica
    while (i>0 and t[j]<v)
    {
        t[i]=t[j];
        i=j;
        j=(i-1)/2;
    }
    t[i]=v;
}

void pushMin(int t[],int v, int n, int &length){
    int i=length;//indeks gdzie wstawiamy
    length++;
    int j=(i-1)/2;//indeks rodzica
    while (i>0 and t[j]>v)
    {
        t[i]=t[j];
        i=j;
        j=(i-1)/2;
    }
    t[i]=v;
}

void extractMax(int t1[], int t2[], int &length1, int &length2,int n)
{
    pushMin(t2,t1[0],n,length2);//przerzucamy roota z t1 do t2
    int v=t1[length1-1];//wyrzucamy roota, zmniejszamy tablice
    length1--;
    int i=0;
    int j=1;
    while(j<length1)//naprawiamy kopiec
    {
        if(j+1<length1 and t1[j+1]>t1[j])j++;
        if(v>=t1[j]) break;
        t1[i]=t1[j];
        i=j;
        j=2*j+1;
    }
    t1[i]=v;
}
void extractMin(int t1[], int t2[], int &length1, int &length2,int n)
{
    pushMax(t2,t1[0],n,length2);
    int v=t1[length1-1];
    length1--;
    int i=0;
    int j=1;
    while(j<length1)
    {
        if(j+1<length1 and t1[j+1]<t1[j])j++;
        if(v<=t1[j]) break;
        t1[i]=t1[j];
        i=j;
        j=2*j+1;
    }
    t1[i]=v;
}

int main()
{
    srand(time(NULL));
    double median;
    int N=1000;
    int leftLength=0;
    int rightLength=0;
    int Left[N];
    int Right[N];
    int bufor=0;
    Left[0]=32767;
    while(bufor!=-1)
    {
        cin>>bufor;
        if(bufor<Left[0]) pushMax(Left,bufor,N,leftLength);
        else pushMin(Right,bufor,N,rightLength);
        if(leftLength-rightLength>1) extractMax(Left,Right,leftLength,rightLength,N);
        else if(rightLength-leftLength>0) extractMin(Right,Left,rightLength,leftLength,N);
        //sortowanie przez kopcowanie!!!, wypisanie i wypisanie mediany
        for(int i=0;i<leftLength;i++)
    {
        cout<<Left[i]<<" ";
    }
    cout<<endl;
        for(int i=0;i<rightLength;i++)
    {
        cout<<Right[i]<<" ";
    }
    cout<<endl;
    if((leftLength+rightLength)%2==1){
            median=Left[0];
        cout<<"Median: "<<median<<endl;
    }
        else {median=(Left[0]+Right[0])/2.0;cout<<"Median: "<<median<<endl;}
    }



    return 0;
}
