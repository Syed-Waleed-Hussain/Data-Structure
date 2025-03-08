#include<iostream>
#include<cstring>
using namespace std;

class swing{
	public:
		int number;
		string name;
	
		swing(int nm,string n){
			number=nm;
			name=n;
		}
	
};
int main(){
	int n=4;
	swing* s1[n];
	s1[0]= new swing(9," belt seats");
	s1[1]= new swing(5," bucket seats");
	s1[2]= new swing(4," tire seats");
	s1[3]= new swing(1," wheelchair platforms");
	
	cout<<"Before Sorting :"<<endl;
     cout<<"-----Display-------"<<endl;
    for(int i=0;i<4;i++){
    cout<<" Number :  "<<s1[i]->number<<"    Name :  "<<s1[i]->name<<endl;
}
	//Insertion sort
	for(int i=1;i<n;i++){
	    swing* key=s1[i];
		int j=i-1;
		
		while(j>=0 && s1[j]->number > key->number){
			s1[j+1]=s1[j];
			j--;
		}
		 s1[j+1]=key;
	}
	cout<<"After Sorting :"<<endl;
    cout<<"-----Display-------"<<endl;
    for(int i=0;i<4;i++){
    cout<<" Number :  "<<s1[i]->number<<"    Name :  "<<s1[i]->name<<endl;
}
 
	return 0;
}