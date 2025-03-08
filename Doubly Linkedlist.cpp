#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int d){
        data = d;
        next= NULL;
        prev = NULL;
    }
};
class DoublylinkedList{
        public:
        Node* head;
        Node* tail;
        DoublylinkedList(){
            head = NULL;
            tail = NULL;
            }
        void insertatend(int d){
            Node* newnode = new Node(d);
            if(head == NULL){
                head = newnode;
                tail = newnode;
            } else{
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
            }
        }
        void deleteatfront(){
            if(head == NULL){
                cout<<"List is empty"<<endl;
                return;
                }
            Node* temp=head;
            head = head->next;
            if(head !=NULL){
                head->prev=NULL;
                }
                else{
                    tail = NULL;
                }
                delete temp;
            }
        void search(int val){
            Node* temp = head;
            while(temp !=NULL){
                if(temp->data == val){
                    cout<<"Element found"<<endl;
                return;
            } else{
                temp = temp->next;
            }
         }
            cout<<"Element did not found.."<<endl;
    }
        void display(){
            Node* temp = head;
           
            while(temp != NULL){
                cout<<temp->data<<endl;
                temp = temp->next;
             }
        }
};
int main(){
        DoublylinkedList l1;
        l1.insertatend(400);
        l1.insertatend(500);
        l1.insertatend(200);

        cout<<"List before changing :"<<endl;
        l1.display();

        l1.search(500);

        l1.deleteatfront();
        cout<<"After delete from front :"<<endl;
        l1.display();

    return 0;
}