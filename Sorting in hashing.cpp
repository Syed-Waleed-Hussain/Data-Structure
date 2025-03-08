#include<iostream>
#include<string>

using namespace std;
int size = 20;
class Booknode{
    public:
    string name;
    Booknode* next;

    Booknode(string n):name(n),next(nullptr){}
};
class hashbookshelf{
    public:
    int size = 20;
    Booknode* shelves[20];

    hashbookshelf(){
    for(int i = 0 ; i< size; i++){
        shelves[i] = NULL;
      } 
    }

    int hashfunction(string key){
        int ascii = 0;
        for(int i =0;i< key.length() ; i++){
            ascii += key[i];
        }
        return ascii % 20;
    }
    int partition(string arr[],int l,int r){
        string pivot = arr[r];
        int i = l-1;
        for(int j =l ; j< r ; j++){
            if(arr[j] < pivot ){
                i++;
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i+1],arr[r]);
        return i+1;
    }
    void quicksort(string arr[],int l,int r){
        if(l<r){
            int pi = partition(arr,l,r);
            quicksort(arr,l,pi-1);
            quicksort(arr,pi+1,r);
        }
    }
    
    int linkedlisttoarray(Booknode* head, string array[]){
        if(head == NULL){
            return 0;
        }
        int count = 0;
        while(head != NULL){
            array[count++] = head->name;
            head = head->next;
        }
        return count;
    }

    Booknode* arraytolinkedlist(string array[],int count){
        if(count == 0)
        return NULL;

        Booknode* head = new Booknode(array[0]);
        Booknode* temp = head;
        for(int i =1 ; i<count ; i++){
            temp->next = new Booknode(array[i]);
            temp = temp->next;
        }
        return head;
    }

    void addbook(string name){
        int index = hashfunction(name);
        cout<<"Adding book : "<<name <<" at index :"<<index<<endl;

        Booknode* newNode = new Booknode(name);
        if(shelves[index] == NULL){
            shelves[index] = newNode;
        }
        else{
            Booknode* temp = shelves[index];
            while( temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
        sortshelf(index);
    }
    void sortshelf(int index){
        string books[20];
        int count = linkedlisttoarray(shelves[index],books);
        quicksort(books,0,count-1);
        shelves[index] = arraytolinkedlist(books,count);
    }

    void deletebook(string name){
        int index = hashfunction(name);
        cout<<"Deleting book : "<<name <<" at index : "<<index<<endl;

        Booknode* curr = shelves[index];
        Booknode* prev = NULL;

        while( curr != NULL && curr->name != name){
            prev = curr;
            curr = curr->next;
        }
        if(curr != NULL){
            if(prev == NULL){
                shelves[index] = curr->next;
            }else{
            prev->next = curr->next;
            }
        delete curr;
        }
    }

    void displayallbooks(){
        string allbooks[100];
        int count = 0;

        for(int i=0 ; i< 20 ;i++){
            Booknode* curr = shelves[i];
            while(curr != NULL){
                allbooks[count++] = curr->name;
                curr = curr->next;
            }
        }
        quicksort(allbooks,0,count-1);
        cout<<"All Books in Sorted Form :"<<endl;
        for(int i=0 ; i< count ; i++){
            cout<<allbooks[i]<<endl;
        }
    }
};
int main() {
    hashbookshelf bookshelf;

    bookshelf.addbook("AB");
    bookshelf.addbook("CD");
    bookshelf.addbook("EF");
    bookshelf.addbook("AC");
    bookshelf.addbook("AZ");

    bookshelf.displayallbooks();

    
    bookshelf.deletebook("AC");
    bookshelf.displayallbooks();

    return 0;
}