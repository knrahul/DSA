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
void push(Node*& head,int val){
	Node* newNode=new Node(val);
	newNode->next=head;
	head=newNode;
}
int pop(Node*& head){
	if(head==NULL)return -1;
	Node* temp=head;
	head=head->next;
	int x=temp->data;
	delete temp;
	return x;
}
int peek(Node*& head){
	if(head==NULL)return -1;
	return head->data;
}
bool isEmpty(Node*& head){
return (head==NULL);	
}
int main(){
	Node* head=NULL;
	push(head,10);
	push(head,20);
	push(head,30);
	pop(head);
	push(head,40);
	push(head,50);
	while(!isEmpty(head)){
		cout<<peek(head)<<endl;
		pop(head);
	}
	return 0;
}
