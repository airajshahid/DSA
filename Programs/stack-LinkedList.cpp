#include<iostream>
using namespace std; 


/* The Node class */

class Node
{
public:
int get() 
{ 
return data; 
};
void set(int data)
 { 
 this->data = data;
  };
Node * getNext()
{ 
return nextNode; 
};
void setNext(Node * nextNode) 
{
 this->nextNode = nextNode; 
 };
private:
int data;
Node * nextNode;
};
//Node Class Ends


class stack
{
              Node* head;
           
	public:
	stack()
	{
			head = NULL;
	} 
	
	//PUSH Operation 
    
	void push(int x)
	{
	Node * newNode = new Node();
	newNode->set(x);
	newNode->setNext(head);  //
	head = newNode;
	}
	
	
	//POP Operation 
	int pop()
    {
    int x = head->get();    
    Node * p = head;        
    head = head->getNext();  
    delete 	p;   
    return x;
    }
    

	//Top Operation 
	
	int top()
	{
	return head->get();

	}
	
	bool isEmpty()
	{
     if(head == NULL)
     return true;
     else
     return false;
	}
	
	//Display Function to Display the Stack 
	
	void display()
	{
     Node* temp = head;
     
     if( isEmpty() == true )
     	{
             cout << "The Stack is Empty!\n\n";
             return;
     	}
	else
     	{
         while(temp != NULL)
         {
             cout << temp->get();
             cout<< " --> ";
             temp = temp->getNext();
         }
         
         cout << "Stack End\n\n";
     	}	
	}
};


int main()
{
	stack test ;
	test.push(10);
	test.push(20);
	test.push(30);
	test.push(40);
	test.push(50);
	test.display();
	test.pop();
	test.pop();
	test.display();
	
}
