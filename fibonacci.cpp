/*
Gabriel Nowak, 13.01.2023

Napisz funkcję, która jako argument będzie przyjmować liczbę całkowitą i która
będzie zwracać n, gdzie n jest indeksem pierwszego pojawienia się danej liczby w
ciągu Fibonacciego lub 0, jeśli argument nie będzie elementem ciągu Fibonacciego.
Przykładowo dla argumentu 3 funkcja powinna zwrócić 4, ponieważ 3 pojawia się w
ciągu na 4-tym miejscu

*/
#include<iostream>
using namespace std;

int fibonacci(int x)
{
    
    int a, b , c;
    a=1;//a1
    b=1;//a2
    if(x==1)
        return 1;
    for(int i=3;c <= x;i++)//18 2,3,5,8,13,21,34,55
    {
        c=a+b;//2
        a=b;//1
        b=c;//2
        if(c==x)
            return i;

    }    
    return 0;
}

int main()
{
    
    cout<<fibonacci(-3)<<endl;//0
    cout<<fibonacci(21)<<endl;//8
    cout<<fibonacci(55)<<endl;//10
    cout<<fibonacci(18)<<endl;//0
    return 0;
}
