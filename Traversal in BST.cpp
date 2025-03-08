#include<iostream>
#include<cstring>

using namespace std;

class marathon{

	public:
		string name;
		int time;
};
void display(marathon arr[]){
	for(int i=0;i<4;i++){
	cout<<"Runner "<< i+1 <<" name :"<<arr[i].name<< endl;
	cout<<"Runner "<<i+1 << " Time :"<<arr[i].time<<endl;
}
}
void merge(marathon myarr[],int l,int m,int r){
	int i = l;
	int j = m+1;
	int k = l;
	marathon temp[4];
	while(i<=m && j<=r){ 
		if(myarr[i].time<myarr[j].time){
			temp[k]=myarr[i];
			i++;
			k++;
		}
		else{
			temp[k]= myarr[j];
			j++;
			k++;
		}
	}
	while(i<=m){
		temp[k]= myarr[i];
		i++;
		k++;
	}
	while(j<=r){
		temp[k]= myarr[j];
		j++;
		k++;
	}
	for (int s = l;s<=r; s++){
		myarr[s]= temp[s];
	}
}
void mergesort(marathon arr[],int l,int r){
		if(l<r)
		{
		int mid = (r+l)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
		
	}
}
int main(){
	marathon arr[4];
	for(int i=0;i<4;i++){
		cout<<"Enter name of Runner "<<i+1<<" : ";
		cin>>arr[i].name;
		cout<<"Enter time of Runner "<<i+1<<" : ";
		cin>>arr[i].time;
		
	}
	mergesort(arr,0,3);
	for (int i=0;i<4;i++){
	    cout<<"Runner "<< i+1 <<" name :"<<arr[i].name<< endl;
	    cout<<"Runner "<<i+1 << " Time :"<<arr[i].time<<endl;
	}
	return 0;
	
}