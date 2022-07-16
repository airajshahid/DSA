#include<iostream>
#include<string>
using namespace std;

class Queue                    // class queue
{
public:
    int A[5];                   // array of size 5                
    int front = -1;
    int rear = -1;

Queue()                         //constructor
{
	bool isempty();
	void enqueue();
	void dequeue();
	void showfront();
	void displayQueue();
	}	

//Function to check if queue is empty or not
bool isempty()
{
 if(front == -1 && rear == -1)
 return true;
 else
 return false;
}

//function to enter elements in queue
void enqueue ( int value )
{
 //queue is full
 if ((rear + 1)%5 == front)
    cout<<"Queue is full \n";
 else
 {
  //first element inserted
  if( front == -1)
     front = 0;
 //insert element at rear
 rear = (rear+1)%5;
   A[rear] = value;
 }
}

//function to delete/remove element from queue
void dequeue ( )
{
 if( isempty() )
  cout<<"Queue is empty\n";
 else
 //only one element
 if( front == rear )
  front = rear = -1;
 else
  front = (front + 1)%5;
}

//function to show the element at front
void showfront( )
{
 if( isempty())
 cout<<"Queue is empty\n";
 else
 cout<<"element at front is:"<<A[front];
}

//function to display queue
void displayQueue()
{
 if(isempty())
  cout<<"Queue is empty\n";
 else
 {
  int i;
  if( front <= rear )
  {
   for( i=front ; i<= rear ; i++)
   cout<<A[i]<<" ";
  }
  else
  {
   i=front;
   while( i < 5)
   {
   cout<<A[i]<<" ";
   i++;
   }
   i=0;
   while( i <= rear)
   {
   cout<<A[i]<<" ";
   i++;
   }
  }
 }
}	
};

main()
{
	Queue q;
	int choice, counter=1 , value;
	while (counter==1)
	{
		cout<<"Enter 1 to enqueue \n 2 to dequeue \n 3 to see the front \n 4 to see the front whole queue \n 5 to exit";
		cin>>choice;
		   if (choice==1)
		   {
		   	q.enqueue(value);
		   }
		   else if (choice==2)
		   {
		   	q.dequeue();
		   }
		   else if (choice==3)
		   {
		   	q.showfront();
		   }
		   else if (choice==4)
		   {
		   	q.displayQueue();
		   }
		   else if (choice==5) 
		   {
		   	counter==0;
		   }
		   else 
		   {
		   	"you have chosen an invalid option";
		   }
	}
    return 0;
}
