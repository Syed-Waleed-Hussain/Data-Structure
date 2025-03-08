#include <iostream>
#include <string>
using namespace std;

class Assignment {
public:
    string name;
    string dueDate; // Format: "DD-MM"

    Assignment(string n, string d) : name(n), dueDate(d) {}
};

// Function to perform selection sort on assignments
void sortAssignments(Assignment assignments[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (assignments[j].dueDate < assignments[maxIdx].dueDate) {
                maxIdx = j;
            }
        }
        // Swap
        Assignment temp = assignments[i];
        assignments[i] = assignments[maxIdx];
        assignments[maxIdx] = temp;
    }
}

// Function to perform binary search
int binarySearch(Assignment assignments[], int n, const string &assignmentName) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (assignments[mid].name == assignmentName) {
            return mid; // Found the assignment
        } else if (assignments[mid].name < assignmentName) {
            right = mid - 1; // Search left
        } else {
            left = mid + 1; // Search right
        }
    }
    return -1; // Not found
}

int main() {
    Assignment assignments[] = {
        Assignment("Assignment A", "09-10"),
        Assignment("Assignment B", "07-10"),
        Assignment("Assignment C", "05-10"),
        Assignment("Assignment D", "15-10"),
        Assignment("Assignment E", "02-10")
    };
    int n = sizeof(assignments) / sizeof(assignments[0]);

    // Sort assignments
    sortAssignments(assignments, n);

    // Output sorted assignments
    cout << "Sorted assignments (due dates in accending order):" << endl;
    for (int i = 0; i < n; i++) {
        cout << assignments[i].name << " (due on " << assignments[i].dueDate << ")" << endl;
    }

    // Search for a specific assignment
    string searchAssignment = "Assignment B";
    int position = binarySearch(assignments, n, searchAssignment);
    if (position != -1) {
        cout << searchAssignment << " is in the drawer at position: " << position << endl;
    } else {
        cout << searchAssignment << " is not found in the drawer." << endl;
    }

    return 0;
}
