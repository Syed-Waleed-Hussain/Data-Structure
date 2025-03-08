#include<iostream>
#include<cstring>

using namespace std;
class Node{
    public:
        string title;
        string author;
        Node* next;

    Node(string t,string a){
        title=t;
        author=a;
        next = NULL;
    }
};
class catalog{
    public:
    Node* head;
    Node* tail;
    catalog(){
        head = NULL;
        tail = NULL;
    }
    void addbooktotail(string t,string a){
        Node* newnode = new Node(t,a);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
    }
    void deletebookfromfront(){
       
        if(head!=NULL){
            Node* temp = head;
            head = head->next;
            delete temp;
            if (head == NULL){
                tail = NULL;
            }
            cout<<"catalog from front,deleted..!"<<endl;
        }
        else{
            cout<<"catalog from front,empty"<<endl;
        }
    }
    void searchbookbytitle(string t){
        Node* temp = head;
        while(temp!=NULL){
            if(temp->title==t){
                cout<<"book found"<<endl;
                cout<<"Book title: "<<temp->title<<"     ";
                cout<<"Book author: "<<temp->author<<endl;
                return;
            }
            else{
                temp = temp->next;
            }
    }
     cout<<"The Book didn't found..!"<<endl;
    }
     void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<"Book title: "<<temp->title<<"     ";
            cout<<"Book author: "<<temp->author<<endl;
            temp=temp->next;
        }
    }
    void searchbookbyposition(int pos){
        Node* temp = head;
        int count = 0;
        while(temp!=NULL){
            if(count==pos){
               
                cout<<"Book title: "<<temp->title<<"     ";
                cout<<"Book author: "<<temp->author<<endl;
                return;
              }   
                  temp=temp->next;
                  count++;
        }
               cout<<" No Book found at Position "<<pos<<endl;
    }
   
};

int main(){
    catalog cat;

    cat.addbooktotail("Getting over you","Najmian");
    cat.addbooktotail("Hujum-e-sittamgaran","Syed Waleed");
    cat.addbooktotail("Devaan-e-ghalib","Mirza Ghalib");
    cat.addbooktotail("SST","TCF");

    cout<<"---------------Catalog Content --------------"<<endl;
    cat.display();

    cat.searchbookbytitle("Hujum-e-sittamgaran");
    cat.searchbookbyposition(1);
    cat.deletebookfromfront();

    cout<<"Catalog after delete from front..."<<endl;
    cat.display();

}