#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* np;
	Node(int val){
		data = val;
		np = NULL;
	}	
};
class LinkList{
	public:
	Node* head;
	int count;
	LinkList(){
		head = NULL;
		count = 0;
	}
	void addtoHead(int val)
	{
		Node *n = new Node(val);
		if(head == NULL)
		{
			head =n;
			count++;
			return;
		}
		n->np = head;
		head = n;
		count++;
		
	}
	void addtoTail(int val){
		Node* n = new Node(val);
		if(head == NULL)
		{
			head = n;
			count++;
			return;
		}
		Node* temp = head;
		while(temp->np != NULL)
		{
			temp = temp->np;
		}
		temp->np = n;
		count++;
	}
	void disp(){
		Node* temp = head;
		while(temp != NULL)
		{
			cout<<temp->data<<"  ";
			temp = temp->np;
		}
		cout<<endl;
	}
};
LinkList add(LinkList &l1,LinkList &l2)
{
	if(l1.count < l2.count)
	{
	while(l1.count < l2.count)
	{
		l1.addtoHead(0);
	}
	}
	else if(l1.count > l2.count)
	{
	while(l2.count < l1.count)
	{
		l2.addtoHead(0);
	}
	}
	Node *tmp1 = l1.head;
	Node *tmp2 = l2.head;
	LinkList add;
	while(tmp1 != NULL || tmp2 != NULL )
	{
		int val1=0,val2=0;
		if(tmp1 != NULL)
		val1 =tmp1->data; 
		if(tmp2 != NULL)
		val2 =tmp2->data;

        int sum = val1 + val2;
        if(sum>=10)
        {
        add.addtoTail(sum / 10);
        add.addtoTail(sum % 10);
    	}
    	else
		add.addtoTail(sum);
		if(tmp1 != NULL)
		tmp1 = tmp1->np;
		
		if(tmp2 != NULL)
		tmp2 = tmp2->np;
		}
	return add;
}
int main(){
	LinkList l1;
	l1.addtoTail(1);
	l1.addtoTail(9);
	l1.addtoTail(9);
	l1.addtoTail(6);
	
	LinkList l2;
	l2.addtoTail(1);
	l2.addtoTail(2);
	l2.addtoTail(1);
	l2.addtoTail(9);
	l2.addtoTail(4);
	cout<<"Link List 1 : ";
	l1.disp();
	cout<<"Link List 2 : ";
	l2.disp();
	cout<<"Link List 3 : ";
	LinkList l3 = add(l1,l2);
	l3.disp();
}