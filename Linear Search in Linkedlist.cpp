#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};

bool searchinlist(Node* head, int key){
        if(head == NULL){
            return false;
        }
        if(head->data == key){
            return true;
        }
        return searchinlist(head->next,key);
}

int main(){
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    head->next = second;
    second->next = third;
    third->next = fourth;

    cout<<"Enter the number you want to find in LinkedList :"<<endl;
    int key;
    cin>>key;
    cout<<"Is "<<key<<" present in the LinkedList ?"<<endl;
    if(searchinlist(head,key)){
        cout<<"Yes"<<endl;
        }
    else{
            cout<<"No"<<endl;
        }
   
}