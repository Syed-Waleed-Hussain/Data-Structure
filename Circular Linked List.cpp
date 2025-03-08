#include<iostream>
using namespace std;

class Node{
    public:
    int table;
    Node* next;
    Node(int t){
        table=t;
        next=NULL;
    }
};
class CircularLinkedList{
    public:
    Node* head;
    CircularLinkedList(){
        head=NULL;
        }
        void add(int t){
            Node* newNode = new Node(t);
            if(head==NULL){
                head=newNode;
                newNode->next=head;
            }
            else{
                    Node* temp=head;
                    while(temp->next!=head)
                    {
                        temp=temp->next;
                    }
                    temp->next=newNode;
                    newNode->next=head;
                }
        }
        void display(){
            if(head==NULL){
                cout<<"No Tables availabe, please go to another resturant..."<<endl;
           return;
            }
            Node* temp=head;
            while(true){
                cout<<" Table "<<temp->table<<" is availabe..."<<endl;
                temp=temp->next;
            if(temp==head){
                break;
            }
        }

     }
};
int main(){
        CircularLinkedList t1;
        t1.add(1);
        t1.add(2);
        t1.add(3);
        t1.add(4);
        t1.add(5);

        t1.display();

        return 0;
}