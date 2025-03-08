#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string url;
    Node* next;

    Node(string url) {
        this->url=url;
        next=nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(string url) {
        Node* newNode = new Node(url);
        newNode->next = top;
        top = newNode;
        cout << "Visited: " << url << endl;
    }

    string pop() {
        if (top == nullptr) {
            cout << "Stack is empty...!!!" << endl;
            return "";
        }
        Node* temp = top;
        string url = temp->url;
        top = top->next;
        delete temp; 
        return url;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    void addFront(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    void removeFront() {
        if (head == nullptr) {
            cout << "No pages to remove...!!!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp; 
    }

    void printHistory() {
        Node* current = head;
        cout << "Browsing History: ";
        while (current != nullptr) {
            cout << current->url << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack backStack;
    LinkedList browsingHistory;

    backStack.push("Google");
    browsingHistory.addFront("Google");

    backStack.push("Facebook");
    browsingHistory.addFront("Facebook");

    backStack.push("Twitter");
    browsingHistory.addFront("Twitter");

    backStack.push("LinkedIn");
    browsingHistory.addFront("LinkedIn");

    backStack.push("Instagram");
    browsingHistory.addFront("Instagram");

    browsingHistory.printHistory();

    // User clicks "back" twice
    cout << "Going back..." << endl;
    if (!backStack.isEmpty()) {
        backStack.pop(); // Go back from Instagram to LinkedIn
        browsingHistory.removeFront(); // Remove Instagram from history
    }
    if (!backStack.isEmpty()) {
        backStack.pop(); // Go back from LinkedIn to Twitter
        browsingHistory.removeFront(); // Remove LinkedIn from history
    }

    browsingHistory.printHistory();

    return 0;
}
