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
    
    
     void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<"Book title: "<<temp->title<<"     ";
            cout<<"Book author: "<<temp->author<<endl;
            temp=temp->next;
        }
    }
    void reverse(){
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        tail=head;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            }
            head=prev;
    }
};

int main(){
    catalog cat;

    cat.addbooktotail("Getting over you","Najmian");
    cat.addbooktotail("Hujum-e-sittamgaran","Syed Waleed");
    cat.addbooktotail("Devaan-e-ghalib","Mirza Ghalib");
    cat.addbooktotail("SST","TCF");
    cat.display();
    cat.reverse();
    cat.display();

}