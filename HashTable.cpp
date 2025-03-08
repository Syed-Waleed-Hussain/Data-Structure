#include <iostream>
#include <string>
using namespace std;

const int SIZE = 10;

class Node {
    public:
        string data;
        Node* next;
};

class HashTable {
    private:
        Node* table[SIZE];
    public:
        HashTable() {
            for (int i = 0; i < SIZE; i++) {
                table[i] = NULL;
            }
        }

       int hashFunction(string word) {
            int asciiSum = 0;
            for (int i = 0; i < word.length(); i++) {
                asciiSum += word[i]; // Sum of ASCII values
            }
            return asciiSum % SIZE; 
        }

        void insert(string key) {
            int index = hashFunction(key);
            Node* newNode = new Node;
            newNode->data = key;
            newNode->next = NULL;

            if (table[index] == NULL) {
                table[index] = newNode;
            } else {
                Node* temp = table[index];
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void display() {
            for (int i = 0; i < SIZE; i++) {
                cout << i << ": ";
                Node* temp = table[i];
                while (temp != NULL) {
                    cout << temp->data << " -> ";
                    temp = temp->next;
                }
                cout << "NULL" << endl;
            }
        }
};

int main() {
    HashTable ht;

    ht.insert("Waleed");
    ht.insert("Asif");
    ht.insert("Ahsan");
    ht.insert("Musawwir");
    ht.insert("Zeeshan");
    ht.insert("Atif");
    ht.insert("Kawish");
    ht.display();

    return 0;
}
