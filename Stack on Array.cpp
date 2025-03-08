#include<iostream>
using namespace std;

#define n 5

class stack{
	public:
		int* arr;
		int top;
	stack(){
		 arr=new int[n];
		top=-1;
	}
	void push(int item){
		if(top == n-1){
			cout<<" Stack overflow can not add"<<endl;
			return;
		}
		arr[++top]=item;
	}
	void pop(){
		if(top == -1){
			cout<<"Stack is empty"<<endl;
			return;
		}
		top--;
	}
	int Top(){
		if(top == -1){
			cout<<"Stack is empty"<<endl;
			return -1;
		}
		return arr[top];
	}
	bool isempty(){
		return top ==-1;
	}
};

int main(){
	stack stk; 

    stk.push(1);
    stk.push(2);
    stk.push(3);
    cout << stk.Top() << endl;
    stk.pop();
    cout << stk.Top() << endl;

    return 0;
}