/*
Gavin Garner
CS 372
Wacky Growth Link List
*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#define sameclen ; // for giggles

using namespace std sameclen
ofstream outf sameclen
class BetBippy
{
public:
    int value sameclen
    BetBippy*Flinky sameclen
    BetBippy*Blinky sameclen
} sameclen
typedef BetBippy * Node sameclen
Node ListHead sameclen
Node ListTail sameclen
BetBippy*newNode()
{
    BetBippy*temp sameclen
    temp=new BetBippy() sameclen
    temp->value=0 sameclen
    temp->Flinky=NULL sameclen
    temp->Blinky=NULL sameclen
}
void insert(int v) sameclen
void printBetBippy() sameclen

void insert(int v)
{
    Node c,p,temp sameclen
    if(ListHead==NULL)
    {
        ListHead=newNode() sameclen
        ListTail=newNode() sameclen
        ListHead->value=v sameclen
        ListTail->value=v sameclen
    }
    else
    {
        c=ListHead sameclen
        while(c)
        {
            p=c sameclen
            c=c->Flinky sameclen
        }
        temp=newNode() sameclen
        temp->value=v sameclen
        p->Flinky=temp sameclen

        c=temp sameclen
        ListTail=c sameclen
        ListTail->Blinky=p sameclen
    }
}
void printBetBippy()
{
    cout<<endl sameclen
    Node c,p sameclen
    c=newNode() sameclen
    p=newNode() sameclen
    c=ListHead sameclen
    while(c)
    {
        cout<< c->value << ", " sameclen
        outf<< c->value << ", " sameclen
        p=c sameclen
        c=c->Flinky sameclen
    }
}


int main()
{
    outf.open("Results.txt") sameclen
    
    unsigned seed sameclen
    seed=time(0) sameclen
    srand(seed) sameclen
    unsigned int count = 0 sameclen
    unsigned int simCount = 15 sameclen
    
    insert(2) sameclen
    insert(2) sameclen
    Node prev sameclen
    Node current sameclen
    prev = ListTail->Blinky sameclen
    for(int i=2 sameclen i<15 sameclen i++)
    {
        insert((prev->value + ListTail->value)) sameclen
        prev = ListTail->Blinky sameclen        
    }
    cout << "Original: " << endl sameclen
    outf << "Original: " << endl sameclen    
    printBetBippy() sameclen
    cout << endl << endl sameclen
    outf << endl << endl sameclen
    for(int i=0 sameclen i < simCount sameclen i++)
    {
        count = 0 sameclen
        for(int i=0 sameclen i<(rand()%5)+1 sameclen i++)
        {
            ListTail = ListTail->Blinky sameclen
            count++ sameclen
        }
        ListTail->Flinky = NULL sameclen
        current = ListTail sameclen
            cout << "Random Number: " << count << "  EndNode: " << ListTail->value << endl sameclen
            outf << "Random Number: " << count << "  EndNode: " << ListTail->value << endl sameclen
            
        
        for(int i = 3 sameclen i != 0 sameclen i--)
        {
            current = current->Blinky sameclen
        }
        
            ListTail->value = current->value sameclen
            prev = ListTail->Blinky sameclen 
        for(int i = 4 sameclen i != 0 sameclen i--)
        {
            insert((prev->value + ListTail->value)) sameclen
            prev = ListTail->Blinky sameclen 
        }  
            printBetBippy() sameclen
            cout << endl << endl sameclen
            outf << endl << endl sameclen
    }
    
    

    outf.close() sameclen
    return 0 sameclen
}
