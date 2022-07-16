/*Stack implementation using array */
#include <iostream>
using namespace std;
/* The Stack class */
class Stack
{
public:
Stack()
 { 
 size = 10; current = -1;
 } 				//constructor


int pop()
{ 
return A[current--];
} 				// The pop function



void push(int x)
{
A[++current] = x;
} 				// The push function


int top()
{
 return A[current];
 } 				// The top function


int isEmpty()
{
return ( current == -1 );
} 				// Will return true when stack is empty


int isFull()
{
 return ( current == size-1);
 } 				// Will return true when stack is full
 
 
private:
int object; 	// The data element
int current; 	// Index of the array
int size; 		// max size of the array
int A[10];		 // Array of 10 elements
};


int main()
{
Stack stack; 		// creating a stack object

// pushing the 10 elements to the stack
for(int i = 0; i < 11; i++)
{
if(!stack.isFull()) 			// checking stack is full or not
stack.push(i); 					// push the element at the top
else
cout <<"\n Stack is full, can't insert new element";
}

// pop the elements at the stack
for (int i = 0; i < 11; i++)
{
if(!stack.isEmpty()) 			// checking stack is empty or not
cout << "\n The popped element = " << stack.pop();
else
cout <<"\n Stack is empty, can't pop";
}

}
