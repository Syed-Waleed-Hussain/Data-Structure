#include<iostream>
using namespace std;

struct Node {
    string name;
    int score;
    Node* next;
};

void insert(Node*& head, string name, int score) {
    Node* newNode = new Node;
    newNode->name = name;
    newNode->score = score;
    newNode->next = head;
    head = newNode;
}

int getMax(Node* head) {
    int max = head->score;
    Node* current = head;
    while (current != nullptr) {
        if (current->score > max) {
            max = current->score;
        }
        current = current->next;
    }
    return max;
}

Node* countingSort(Node* head, int exp, int n) {
    Node** output = new Node*[n];
    int count[10] = {0};
    Node* current = head;

    while (current != nullptr) {
        int digit = (current->score / exp) % 10;
        count[digit]++;
        current = current->next;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    current = head;
    while (current != nullptr) {
        int digit = (current->score / exp) % 10;
        output[count[digit] - 1] = current;
        count[digit]--;
        current = current->next;
    }

    Node* sortedHead = nullptr;
    for (int i = n - 1; i >= 0; i--) {
        output[i]->next = sortedHead;
        sortedHead = output[i];
    }

    delete[] output;
    return sortedHead;
}

void radixSort(Node*& head, int n) {
    int maxScore = getMax(head);
    for (int exp = 1; maxScore / exp > 0; exp *= 10) {
        head = countingSort(head, exp, n);
    }
}

void display(Node* head) {
    while (head != nullptr) {
        cout << head->name << " scored: " << head->score << endl;
        head = head->next;
    }
}

int main() {
    Node* head = nullptr;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int score;
        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter score of student " << i + 1 << ": ";
        cin >> score;
        insert(head, name, score);
    }

    radixSort(head, n);

    cout << "\nSorted list of students by scores:\n";
    display(head);

    return 0;
}
