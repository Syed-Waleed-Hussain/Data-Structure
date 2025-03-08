#include<iostream>
using namespace std;

class student{
  public:
    string studentname;
    string examdate;
    int score;
  
    student();
    student(string sn,string ed,int s):studentname(sn),examdate(ed),score(s){}
    student(const student &s2){
        this->studentname=s2.studentname;
        this-> examdate= s2.examdate;
        this-> score=s2.score;
    }
    student operator =(const student&obj){
        if(this!=&obj){
            studentname = obj.studentname;
            examdate = obj.examdate;
            score = obj.score;
        }
        else {
            return *this;
        }
    }
    ~student(){
        cout<<"Destructor called"<<endl;
    }
    void display(){
        cout<<studentname<<endl<<examdate<<endl<<score<<endl;
    }
};
int main(){
    student s1("Waleed","5Sep2024",80);
    student s2=s1;
    s1.display();
    s2.display();
    s2.studentname="Atif";
    s2.score=79;
    s1.display();
    s2.display();

    return 0;
}