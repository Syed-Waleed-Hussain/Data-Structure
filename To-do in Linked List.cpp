#include<iostream>
#include<cstring>

using namespace std;

class Node{
    public:
    string task;
    Node* next;
    Node(string task){
        this->task = task;
        this->next = NULL;
        }
};
class todolist{
    Node* head;
    Node* tail;
    public:
    todolist(){
        head = NULL;
        tail = NULL;
        }
        void addtasktofront(string t){
            Node* newnode= new Node(t);
            if(head == NULL){
                head = newnode;
                tail = newnode;
                }
            else{
                    newnode->next = head;
                    head = newnode;
                }
        }
        void addtasktotail(string t){
            Node* newnode = new Node(t);
            if(head == NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                tail->next = newnode;
                tail = newnode;
            }
        }
        void deletetaskfromfront(){
            if(head!=NULL){
                Node* temp = head;
                head = head->next;
                delete temp;
                if(head==NULL){
                    tail = NULL;
                }
                cout<<"The Task from the front,Deleted..!"<<endl;
            }
                else{
                    cout<<"No Task to delete"<<endl;
                }
            }
        void deletefromthetail(){
            if(head==NULL){
                cout<<"No Task to delete"<<endl;
            }
            else if(head->next==NULL){
                delete head;
                head=NULL;
                tail==NULL;
                cout<<"Task deleted from the Tail"<<endl;
            }
            else{
            Node* temp = head;
            while(temp->next!= tail){
                temp = temp->next;
            }
           delete tail;
           tail = temp;
           tail->next =NULL;
           cout<<"Task at the tail,Deleted..!"<<endl;
            }
        }
        void deletetaskfromposition(int pos){
            if(pos==0){
                deletetaskfromfront();
            }
            Node* temp=head;
            Node* prev=NULL;
            int count=0;
            while(temp!=NULL && count!=pos){
                prev = temp;
                temp = temp->next;
                count++;
            }
            if(temp==NULL){
                cout<<"Nothing to delete"<<endl;
            }
            else{
                prev->next = temp->next;
                if(temp==tail){
                    tail = prev;
                }
                delete temp;
                cout<<" Task at Position "<<pos<<" ,Deleted..!"<<endl;
            }
        }
        void display(){
            Node* temp = head;
            while(temp!=NULL){
                cout<<temp->task<<endl;
                temp = temp->next;
            }
        }
};
int main(){

        todolist task;
        task.addtasktofront("Buy groceries");
        task.addtasktofront("Finish a report");
        task.addtasktofront("Go for run");
        
        cout<<"------------ Initial ToDo List ----------"<<endl;
        task.display();

        task.deletetaskfromfront();
        cout<<"------------ After deleting from front ----------"<<endl;
        task.display();

        task.addtasktotail("Call a friend");
        cout<<"------------ After adding to tail ----------"<<endl;
        task.display();

        task.deletefromthetail();
        cout<<"---------------After deleting from tail------------"<<endl;
        task.display();

        task.deletetaskfromposition(1);
        cout<<"---------------After deleting at position 1-------------"<<endl;
        task.display();

        return 0;
}