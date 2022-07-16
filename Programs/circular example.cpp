/* 
NAME:         AIRAJ SHAHID
CLASS & SEC:  BSCS-5A
REG NO :      F1F18BSCS0009
*/

//CIRCULAR LINKED-LIST IMPLEMENTATION

#include<iostream>
using namespace std;
class Node{
 public:
    int a;
    Node *next;       //pointer for next node
    Node *previous;   // pointer for previous node
}
*first, *last;
int c=-1;

class Circular_Linked_List
{
    public:
        Node *newNode(int);
        void insert();               //Q#1 different operations of a circular linked list
        void remove();
        void search();
        void display();
        void size();               //Q#2  extra operation
        Circular_Linked_List()      // constructor
        {
            first=NULL;
            last=NULL;   
        }
};

Node* newNode(int val)
{
    c++;
  Node *temp;
    temp = (new Node);
    temp->a=val;
    temp->next=NULL;
    temp->previous=NULL;
    return temp;
}
insert(int newV)
{
     Node *temp;
    temp= newNode(newV);
    if (first==last && first== NULL)
    { 
        cout<<"-----------New element is inserted in empty list---------\n";
        first=last=temp;
        first->next=last->next=NULL;
        first->previous=last->previous=NULL;
    }
    else
    {
        temp->next=first;
        first->previous=temp;
        first=temp;
        first->previous=last;
        last->next=first;
        cout<<"-----------New element is inserted in empty list---------\n";
    }
}

void Circular_Linked_List::remove()
{ 
    int index;
    Node *ptr, *sample;
    if (first==last && first==NULL)
    {
        cout<<"------------------List is empty---------------\n";
    }
    cout<<"\n Enter the index of element you want to delete: ";
    cin>>index;
    if (c<index)
    {
        cout<<"------------Index not found------\n";
    }
    sample=first;
    if(index==0)
    {
        c--;
        last->next= sample->next;
        sample->next->previous = last;
        first= sample->next;
        free(sample);
        cout<<"-----------Item from the list is removed-----------\n new list is : ";
        display();  
    }
    for (int i=0; i<index-1; i++ )
    {
        sample= sample->next;
        ptr=sample->previous;     
    } 
    ptr->next = sample->next;
    sample->next->previous=ptr;
    if (index==c)
    {
        last=ptr;   
    }
    c--;
    free(sample);
    cout<<"Item is removed fom index: "<<index<<" New list is :\n";
    display();
}

void Circular_Linked_List::search()
{
    int index= 0, value;
    bool option = false;
     Node *sample;
    if (first==last && first==NULL)
    {
        cout<<"----------------The List is empty----------------------\n";
    }
    cout<<endl<<"Enter the value you want to search : ";
    cin>>value;
    sample=first;
    for (int i=0; i<c; i++)
    {
        index++;
        if (sample->a == value)
        {
            cout<<"Item you entered is at index : "<<index<<"\n";
            option = true;
        } 
        sample=sample->next;
    }
    if (!option)
        cout<<"-----------Element is not available in the list---------\n"; 
}

void Circular_Linked_List::display()
{
    struct Node *sample;
    if (first==last && first==NULL)
    {
        cout<<"-------------The List is empty-----------\n";
    }
    sample=first;
    for (int i=0; i<c-1; i++)
    { 
        cout<<sample->a<<"---->";
        sample=sample->next;
    }
    cout<<sample->a<<"\n";
}

void Circular_Linked_List::size(){
 cout<<"Size of List is : "<<c<<"\n\n\n\n";
}

int main()
{
    int menu,value,newval;
    Circular_Linked_List obj;

        cout<<"\nEnter the number of values you want to insert in the  List ? ";
        cin>>value;
        for(int j=1; j<=value; j++){
        cout<<"Enter the item you want to set it as a new node: ";
        cin>>newval;
        insert(newval);
        cout<<endl;
     obj.display(); 
 }
        cout<<"\n\n";
        cout<<"enter 1 to remove, 2 to search, 3 to check the size :";
        cin>>menu;
 
        if (menu==1)
            obj.remove();
        else if (menu==2)
            obj.search();
        else if (menu==3)
            obj.size();
        else 
            cout<<"------------Invalid menu chosen------------"; 

    return 0;
}
