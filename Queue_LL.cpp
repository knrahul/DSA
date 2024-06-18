#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int data){
			this->data=data;
			this->next=NULL;
		}
};
class Queue{
	public:
		Node* front;
		Node* rear;
		Queue(){
			front=NULL;
			rear=NULL;
		}
		void enqueue(int val);
		int dequeue();
		bool isEmpty();
};
void Queue::enqueue(int val){
	Node* newNode=new Node(val);
	if(rear==NULL){
		rear=newNode;
		front=newNode;
	}
	rear->next=newNode;
	rear=newNode;
}
int Queue::dequeue(){
	if(front==NULL)return -1;
	Node* temp=front;
	int x=temp->data;
	front=front->next;
	if(front==NULL ){
		rear=NULL;
	}
	delete temp;
	return x;
}
bool Queue::isEmpty(){
	return front==NULL;
}
int main(){
	Queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.dequeue();
	q.enqueue(40);
	q.enqueue(50);
	while(!q.isEmpty()){
		cout<<q.dequeue()<<endl;
	}
	return 0;
}
