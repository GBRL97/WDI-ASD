/* Gabriel Nowak, 29.01.2018
A few functions for one-way lists
*/
#include<iostream>
using namespace std;

struct node
{
    node *next;
    int v;
};
void printList(node *p)
{
    if(p==NULL)
    {
        cout<<"Empty list!"<<endl;
    }
    else
    {
        cout<<p->v<<"->";
        while(p->next!=NULL)
        {
            cout<<p->next->v<<"->";
            p=p->next;
        }
        cout<<"NULL\n";
    }
}
void addFirstElement(node *&first,int v)//by the refference because first pointer is changing
{
    node *p=new node;
    p->next=first;
    first=p;
    p->v=v;
}
node *addFirstElement1(node *first, int v) //the same but without refference
{
    node *p = new node;
    p->next=first;
    first=p;
    p->v=v;
    return first;
}

void addLastElement(node *first, int v)
{
    node *p=new node;
    while(first->next)
    {
        first=first->next;
    }
    p->next=first->next;
    first->next=p;
    p->v=v;
}
int getSize(node *p)
{
    int sizeL=0;
    while(p)
    {
        p=p->next;
        sizeL++;
    }
    return sizeL;
}
void deleteFirstElement(node *&first)//by the refference because first pointer is changing
{
    node *p=first;
    first=first->next;
    delete p;

}
void deleteLastElement(node *p)
{
    node *p1=p;
    while(p1->next)
    {
        p=p1;
        p1=p1->next;
    }
    p->next=p1->next;
    delete p1;
}
bool findElement(node *p, int v)
{
    while(p)
    {
        if(p->v==v)return true;
            p=p->next;
    }
    return false;
}
void deleteAllElements(node *&first, int v)//by the refference because first pointer may be changed
{
    if(getSize(first)>1)
    {
    if(first->v==v)deleteFirstElement(first);
    node *p=first;
    node *p1=p->next;
    while(p1)
    {
        if(p1->v==v)
        {
            p->next=p1->next;
            delete p1;
            p1=p->next;
        }
        else
        {
            p=p1;
            p1=p1->next;
        }
    }
    }
    else
    {
        if(first->v==v)
        deleteFirstElement(first);
    }
}

int main()
{
    int choose=-1;
    int v;
    node *first;
    first=new node;
    first=NULL;
    while(choose)
    {
        cout<<"[0] - exit program\n[1] - print list\n[2] - add new element at the beginning of list"<<endl;
        cout<<"[3] - add new element at the end of list\n[4] - find element\n[5] - delete first element"<<endl;
        cout<<"[6] - delete last element\n[7] - delete all elements with a given value\n[8] - check size of list\n[9] - add new element at the beginning of list\n"<<endl;
        cin>>choose;
        switch(choose)
        {
        case 0:
            cout<<"EXIT";
            break;
        case 1:
            printList(first);
            break;
        case 2:
            cout<<"Value: ";
            cin>>v;
            addFirstElement(first,v);
            cout<<"DONE\n";
            break;
        case 3:
            cout<<"Value: ";
            cin>>v;
            if(getSize(first)>0)
            addLastElement(first,v);
            else addFirstElement(first,v);
            cout<<"DONE\n";
            break;
        case 4:
            cout<<"Give value: ";
            cin>>v;
            if(findElement(first,v))cout<<"This value exists in the list\n";
            else cout<<"This value doesn't exist in this list\n";
            break;
        case 5:
            if(getSize(first)>0)
            {
                deleteFirstElement(first);
                cout<<"DONE"<<endl;
            }
            else cout<<"Empty list!\n";
            break;
        case 6:
            if(getSize(first)>1){
                deleteLastElement(first);
                cout<<"DONE"<<endl;
            }
            else if(getSize(first)==0)cout<<"Empty list!\n";
                else
                    {
                        deleteFirstElement(first);
                        cout<<"DONE"<<endl;
                    }
            break;
        case 7:
            if(getSize(first)>0)
            {
                cout<<"Give value: ";
                cin>>v;
                deleteAllElements(first,v);
                cout<<"DONE"<<endl;
            }
            else cout<<"Empty list!"<<endl;
            break;
        case 8:
            cout<<"List size: "<<getSize(first)<<endl;
            break;
            default:
                cout<<"Wrong input!\n";
                break;
        case 9:
            cin>>v;
            first=addFirstElement1(first,v);
        }
    }

    return 0;
}
