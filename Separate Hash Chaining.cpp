#include<iostream>
#include<string.h>

// SEPERATE CHAIN HASHING

using namespace std;

class Node{
	public:
		string data;
		Node* next;
		Node(string d):data(d){
			next = NULL;
		}
};
int ascii(string word){
	int as = 0;
	for(int i=0; i< word.length();i++){
		as += word[i];
	}
	return as;
}
class Hashtable{
	public:
	Node* hashtable[100];
	Hashtable(){
	for(int i = 0; i< 100;i++){
		hashtable[i] = NULL; 
	}
  }
	
	void insert (string key, string sdata){
		int index = ascii(key) % 100;
		Node* newnode = new Node(sdata);
		
		if(hashtable[index] == NULL){
			hashtable[index] = newnode;
		}else{
			Node* temp = hashtable[index];
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newnode;
		}
	}
		
	void display(){
		for(int i= 0; i<100 ; i++){
			if(hashtable[i] != NULL){
				cout<< i << " : ";
				Node* temp = hashtable[i];
				while(temp != NULL){
					cout<<temp->data<<" -> ";
					temp = temp->next;
				}
				cout<<" NULL"<<endl;
			}
		}
	}
	void search(string key){
		for(int i= 0; i< 100; i++){
			Node * temp = hashtable[i];
			if(hashtable[i] != NULL){
			while(temp != NULL){
				if(key == temp->data){
					cout<< key <<" Found "<< "at :"<< i <<endl;
					return;
				}
				temp = temp->next;				
			}	
		}
	}
		cout<<key <<" is Not Found"<<endl;
}
};
int main(){
	
	Hashtable table;
	
	table.insert("AB","FASTUNI");
	table.insert("AB","DHASUFFA");
	table.insert("AC","IBA");
	table.insert("AD","GIKI");
	table.insert("AE","IQRA");
	table.insert("AG","SZABIST");
	table.insert("AZ","PIAS");
	table.display();
	table.search("IBA");
	table.search("PIAS");
	return 0;
	
}
