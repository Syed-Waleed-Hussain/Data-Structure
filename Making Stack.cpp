#include<iostream>
using namespace std;

class stack{
	public:
		int max=10;
		int top;
	    int n;
	    int *mystack;
		stack(int e){
			mystack = new int[e];
			n=e;
			top=-1;
		}
		bool push(int item){
			if(top>=(max-1)){
				cout<<"stack overflow..!!!!"<<endl;
				return false;
			}
			else{
				mystack[++top]=item;
				cout<<"Item pushed :"<<item<<endl;
				return true;
			}
		}
		int pop(){
			if(top<0){
				cout<<"stack underflow...!!"<<endl;
				return 0;
			}
			else{
				int item= mystack[top--];
				return item;
			}
		}
		bool isempty(){
			return(top<0);
		}
		int peek(){
			if(top<0){
				cout<<"stack is empty...!!!"<<endl;
				return 0;
			}
			else{
				int item = mystack[top];
				return item;
			}
		}
		int size(){
			return top+1;
		}
		int isfull(){
			if(top== n-1){
				cout<<"Stack is full"<<endl;
				return 0;
			}else{
				cout<<"stack has very space"<<endl;
				return 0;
			}
		}
};
int main(){
	stack s1(3);
	s1.push(10);
	s1.push(20);
	s1.pop();
	s1.peek();
	s1.size();
	s1.isfull();
	s1.isempty();
	return 0;
}