#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
		int data;
		Node* next;
		Node(int val){
			data=val;
			next=NULL;
		}
};
void printLL(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		if(temp->next!=NULL){
			cout<<"->";
		}
		temp=temp->next;
	}
	cout<<endl;
}
void insertBegin(Node*& head,int val){
	Node* newNode=new Node(val);
	newNode->next=head;
	head=newNode;
	return;
}
void insertEnd(Node*& head,int val){
	Node* newNode=new Node(val);
	if(head==NULL){
		head=newNode;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newNode;
	return;
}
void insertPos(Node*& head,int val,int pos){
	Node* newNode=new Node(val);
	if(pos==1){
		newNode->next=head;
		head=newNode;
		return;
	}
	Node* temp=head;
	while(temp!=NULL && pos-2>0){
		pos--;
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"Position is out of bounds";
		return;
	}
	newNode->next=temp->next;
	temp->next=newNode;
	return;
}
void deleteLast(Node*& head){
	if(head==NULL)return;
	if(head->next==NULL){
		head=NULL;
	}
	Node* temp=head;
	Node* prev=NULL;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;
	}
	prev->next=NULL;
}
void deleteBegin(Node*& head){
	if(head==NULL)head=NULL;
	if(head->next==NULL)head=NULL;
	head=head->next;
}
Node* reverseLL(Node* head){
	Node* temp=head;
	Node* prev=NULL;
	Node* front=NULL;
	while(temp!=NULL){
		front=temp->next;
		temp->next=prev;
		prev=temp;
		temp=front;
	}
	return prev;
}
int main(){
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	vector<int> list;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		list.push_back(data);
	}
	Node* head=NULL;
	for(int i=0;i<n;i++){
		insertBegin(head,list[i]);
	}
	printLL(head);
	insertPos(head,100,3);
	printLL(head);
	deleteBegin(head);
	printLL(head);
	Node* newHead=reverseLL(head);
	printLL(newHead);
	return 0;
}
