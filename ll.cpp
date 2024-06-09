#include<bits/stdc++.h>
using namespace std;
class Node{ 
public:
	int data;
	Node* next;
	Node(int data){
		this->data=data;
		next=NULL;
	}
};
void insert1(Node*& head,int val){
	Node* newnode=new Node(val);
	newnode->next=head;
	head=newnode;
	return;
}
void insert2(Node*& head,int val){
	Node* newnode=new Node(val);
	if(head==NULL){
		head=newnode;
		return;
	}
	Node* temp=head;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=newnode;
}
void insertpos(Node*& head,int val,int pos){
	Node* newnode=new Node(val);
	if(pos==1){
		newnode->next=head;
		head=newnode;
		return;
	}
	Node* temp=head;
	for(int i=1;i<pos-1;i++){
		if(temp==NULL){
			cout<<"position out of bounds"<<endl;
			delete newnode;
			return;
		}
		temp=temp->next;
	}
	if(temp==NULL){
		cout<<"Position out of bounds"<<endl;
		delete newnode;
		return;
	}
	newnode->next=temp->next;
	temp->next=newnode;
}
void printll(Node* head){
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
void printList(vector<int> list){
	for(int i=0;i<list.size();i++){
		cout<<list[i]<<" ";
	}
	cout<<endl;
}
int main(){
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	cout<<"Enter the elements:";
	vector<int> list;
	for(int i=0;i<n;i++){
		int data;
		cin>>data;
		list.push_back(data);
	}
	Node* head=NULL;
	for(int i=0;i<n;i++){
		insert2(head,list[i]);
	}
	printll(head);
	printList(list);
	cout<<endl;
	insertpos(head,100,10);
	printll(head);
	return 0;
}
