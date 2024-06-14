#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* prev;
	Node* next;
	Node(int data){
		this->data=data;
		next=NULL;
		prev=NULL;
	}
};
void insertEnd(Node*& head,Node* &tail,int val){
	Node* newNode=new Node(val);
	if(head==NULL){
		head=newNode;
		tail=newNode;
		return;
	}
	tail->next=newNode;
	newNode->prev=tail;
	tail=newNode;
}
/*void insertPos(Node*& head,Node*& tail,int pos,int val){
	Node* newNode=new Node(val);
	if(head==NULL){
		head=newNode;
		tail=newNode;
		return;
	}
	if(pos==1){
		newNode->next=head;
		head->prev=newNode;
		head=newNode;
		return;
	}
	
}*/
void deleteBegin(Node*& head){
	if(head==NULL)return;
	if(head->next==NULL){
		delete head;
		head=NULL;
		return;
	}
	Node* prev=head;
	head=head->next;
	head->prev=NULL;
	prev->next=NULL;
	delete prev;
}
void deleteEnd(Node*& head,Node*&tail){
	if(head==NULL)return;
	if(head->next==NULL){
		delete head;
		head=NULL;
		return;
	}
	Node* temp=head;
	while(temp->next->next!=NULL){
		temp=temp->next;
	}
	Node* deleteNode=temp->next;
	temp->next=NULL;
	tail=temp;
	delete deleteNode;
	return;
}
void insertBegin(Node*& head,Node*& tail,int data){
	Node* newNode=new Node(data);
	if(head==NULL){
		head=newNode;
		tail=newNode;
		return;
	}
	newNode->next=head;
	head->prev=newNode;
	head=newNode;
	return;
}
void printDLL(Node* head){
	Node* temp=head;
	while(temp!=NULL){
		cout<<temp->data;
		if(temp->next!=NULL){
			cout<<"<->";
		}
		temp=temp->next;
	}
	cout<<endl;
}
void deletePos(Node*& head,int pos){
	Node* temp=head;
	while(temp!=NULL && pos-1>0){
		pos--;
		temp=temp->next;
	}
	Node* front=temp->next;
	Node* back=temp->prev;
	if(front==NULL && back==NULL){
		return;
	}
	else if(front==NULL){
		temp->prev->next=NULL;
		delete temp;
		return;
	}
	else if(back==NULL){
		head=head->next;
		head->prev=NULL;
		return;
	}
	else{
		temp->next->prev=temp->prev;
		temp->prev->next=temp->next;
		delete temp;
		return;
	}
}
int main(){
	Node* head=NULL;
	Node* tail=NULL;
	int n;
	cout<<"Enter number of elements:";
	cin>>n;
	vector<int> list;
	for(int  i=0;i<n;i++){
		int data;
		cin>>data;
		list.push_back(data);
	}
	for(int i=0;i<n;i++){
		insertBegin(head,tail,list[i]);
	}
	printDLL(head);
	deletePos(head,3);
	printDLL(head);
	return 0;
}
