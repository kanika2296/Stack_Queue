#include <iostream>
using namespace std;
#include "Stack.hpp"
#include "Queue.hpp"
int main()
{
cout << "Making ABS \n";
ABS <int> s1;
s1.push(7);
int *ar = s1.getData();
cout << "Stack is : \n";
for(int i=0;i<s1.count;i++)
{
	cout << ar[i] <<"\t";
}
cout << endl;
s1.push(9);
s1.pop();
cout << "Capacity : "<<s1.getMaxCapacity() <<endl;
cout << "Peek : "<< s1.peek() <<endl;
cout << "Size : "<<s1.getSize() <<endl;
cout<<"Number of resize : s1.resize"<<endl;


cout <<"Making ABQ \n";
ABQ <float> q1;
q1.dequeue(); //exception 
q1.enqueue(2.0);
q1.enqueue(4.0);
q1.enqueue(8.0);
q1.dequeue();
q1.dequeue();
q1.enqueue(9.0);
q1.dequeue();
cout << "Capacity : "<<q1.getMaxCapacity() <<endl;
cout << "Peek : "<< q1.peek() <<endl;
cout << "Size : "<< q1.getSize() <<endl;
cout<<"Number of resize : s1.resize"<<endl;
	
float *arr = q1.getData();
cout << "Queue is : \n";
for(int i=q1.front;i<q1.rear;i++)
{
	cout << arr[i] <<"\t";
}
cout <<endl;
cout << "Resize : "<<q1.resize<<endl;
ABQ <float> q2;
q2 = q1;
cout << "Peek of copied = : " << q2.peek() <<endl;
	return 0;

}
