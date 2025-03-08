#include<iostream>

// Linear Probing

using namespace std;

class Hashtable{
    public:
	int * hashtable;
	Hashtable(){
		hashtable = new int[10];
		for(int i=0;i<100 ;i++){
			hashtable[i] = -1;
		}
	}
	
	void insert(int key){
		int index = key % 10;
		while(hashtable[index] != -1){
		
			index = (index +1) % 10;
		}
		hashtable[index] = key;
	}
	void remove(int key){
		for(int i=0;i< 100 ;i++){
			if(hashtable [ i ] == key){
				hashtable[i] = -1;
			}
		}
	}
	void search(int key){
		for(int i=0;i< 100;i++){
			if(hashtable[i] == key){
				cout<< key <<" Found at "<< i<<endl;
				return;
			}
		}
		cout<<key <<" is not Found"<<endl;
	}
	void display(){
		for(int i=0;i< 100;i++){
			if(hashtable[i] != -1){
				cout<<hashtable[i]<< " -- ";
			}
		}
	}
};
int main(){
	
	Hashtable table;
	table.insert(1);
	table.insert(3);
	table.insert(4);
	table.insert(5);
	table.insert(7);
	table.display();
	cout<< endl;
	cout<<" Remove 4 :"<<endl;
	table.remove(4);
	table.display();
	cout<< endl;
	table.search(5);
	table.search(6);
	
}
