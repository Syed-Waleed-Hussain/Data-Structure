#include<iostream>
#include<string>

using namespace std;

class Node {
    public:
    string key;
    int frequency;
    bool isoccupied;

    Node() {
        key = " ";
        frequency = 0;
        isoccupied = false;
    }

    Node(string s): key(s), frequency(0), isoccupied(false) {}
};

class Hashtable {
    public:
    Node* hashtable;
    int tablesize;
    int itemcount;

    Hashtable() {
        tablesize = 10;
        itemcount = 0;
        hashtable = new Node[tablesize];
    }

    int function1(string key) {
        int hash = 0;
        for(int i = 0; i < key.length(); i++) {
            hash = (hash * 21 + key[i]) % tablesize;
        }
        return hash;
    }

    int function2(string key) {
        int hash = 0;
        for(int i = 0; i < key.length(); i++) {
            hash = (hash * 31 + key[i]) % tablesize;
        }
        return (hash == 0) ? 1 : (tablesize - 1 - hash) % tablesize;
    }

    void resize() {
        int oldsize = tablesize;
        tablesize *= 2;
        Node* oldtable = hashtable;
        hashtable = new Node[tablesize];
        for(int i = 0; i < oldsize; i++) {
            insert(oldtable[i].key, oldtable[i].frequency);
        }
        delete[] oldtable;
        oldtable = nullptr;
    }

    void insert(string key, int freq = 1) {
        if (itemcount > tablesize / 2) {
            resize();
        }
        int index = function1(key);
        int step = function2(key);

        while (hashtable[index].isoccupied && hashtable[index].key != key) {
            index = (index + step) % tablesize;
        }

        if (!hashtable[index].isoccupied) {
            hashtable[index].key = key;
            hashtable[index].frequency = freq;
            hashtable[index].isoccupied = true;
            itemcount++;
        } else {
            hashtable[index].frequency += freq;
        }
    }

    void display() {
        for(int i = 0; i < tablesize; i++) {
            if(hashtable[i].isoccupied) {
                cout << hashtable[i].key << " : " << hashtable[i].frequency << endl;
            }
        }
    }
};

int main() {
    Hashtable table;

    table.insert("hello");
    table.insert("world");
    table.insert("hello"); 
    table.insert("example");
    table.insert("frequency");
    table.insert("world");

    cout << "Word Frequencies:\n";
    table.display();

    return 0;
}
