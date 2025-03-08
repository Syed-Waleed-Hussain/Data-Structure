#include<iostream>
using namespace std;
class City{
	public:
		int distance;
		int litres;
		City* nextcity;
		double ratio;
		bool status;
		City(int d,int l){
			distance = d;
			litres = l;
			nextcity = NULL;
			status = false;
			ratio=(l*(1.0))/d;
		}
};
class Circular{
	public:
		City* head;
		City* tail;
		Circular(){
			head = NULL;
			tail = NULL;
		}
	void insertAtEnd(int dist,int lit){
		City* nayecity = new City(dist,lit);
		if(head == NULL)
		{
			head = nayecity;
			tail = nayecity;
			tail->nextcity = head;
		}
		else{
		tail->nextcity = nayecity;
		tail = tail->nextcity;
		tail->nextcity = head;
		}
	}
	void displayCities(){
		City* temp = head;
		cout<<"City Distance : "<<temp->distance<<"   City Demand : "<<temp->litres<<endl;
		temp = head->nextcity;
		while(temp!= tail->nextcity)
		{
			cout<<"City Distance : "<<temp->distance<<"  City Demand : "<<temp->litres<<endl;
			temp = temp->nextcity;
		}
	}
	void neglectWorstCase(){
//		City* temp = head;
//		while(temp!=tail)
//		{
//			if(temp->distance<temp->litres)
//			temp->status = true;
//		}
//		if(temp)
		
	}
	
};
int main(){
	Circular C1;
	C1.insertAtEnd(15,400);
	C1.insertAtEnd(100,20);
	C1.insertAtEnd(500,50);
	C1.insertAtEnd(50,600);
	
	C1.displayCities();
}