#include<iostream>
#include<cstring>
using namespace std;

class Task{
    public:
    char* desc;
    char* due;
    Task(){
        string des;
        string d;
        cout<<"Enter Dscription:";
        getline(cin,des);
        cout<<"Enter due date:";
        getline(cin,d);
        desc=new char[des.length()+1];
        d= new char[d.length()+1];
        strcpy(desc,des.c_str());
        strcpy(due,d.c_str());
        display();
    }
    void display(){
        cout<<" Description:"<<desc<<endl;
        cout<<"Due Date :"<<due<<endl;
    }
    ~Task(){
        delete[] desc;
        delete[] due;
    }

};
int main(){
    Task* tasks =new Task[3];
    return 0;
}