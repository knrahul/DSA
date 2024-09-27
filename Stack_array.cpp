#include<bits/stdc++.h>
using namespace std;
class Stack{
    private:
    int top;
    int *arr;
    int size;
    public:
    Stack(int n){
        top=-1;
        arr=new int[n];
        size=n;
    }
    bool isEmpty(){
        return top==-1;
    }
    bool isFull(){
        return top==size-1;
    }
    void push(int val){
        if(isFull()){
            cout<<"Stack is full"<<endl;
            return;
        }
        top++;
        arr[top]=val;
        return ;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        int x=arr[top];
        top--;
        return x;
    }
    int peek(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return arr[top];
    }
};
int main(){
    Stack s(10); 
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(100);
    return 0;
}
