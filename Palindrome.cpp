#include<iostream>
#include<string>
using namespace std;
bool check_palindrome(string word,int start,int end) {
	
	if (start >= end) {
		return true;
	}
	
	if (word[start] != word[end]) {
		return false;
	}
	
	return check_palindrome(word,start+1,end-1);
}
void palindrome(char arr[5][5]){
	
	string newarr;
	for(int i=0;i<5;i++){
		newarr="";
		for(int j=0;j<5;j++){
			newarr+=arr[i][j];
			
	  		}
	  			if (check_palindrome(newarr,0,newarr.length() - 1)) {
  				cout<<"this is palindrome "<<newarr;
		}
		
  	}
  	
  	
  	for(int i=0;i<5;i++){
		newarr="";
		for(int j=0;j<5;j++){
			newarr+=arr[j][i];
			
	  		}
	  			if (check_palindrome(newarr,0,newarr.length() - 1)) {
  				cout<<"this is palindrome "<<newarr;
		}
		
  	}
}
int main(){
   		char arr[5][5]={
		   				{'G','R','O','O','T'},
		   				{'B','A','R','R','O'},
		   				{'W','R','D','B','S'},
		   				{'R','A','D','A','R'},
		   				{'G','E','S','T','G'},		
		    			};	
			palindrome(arr);
	
	
}