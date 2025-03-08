#include <iostream>
using namespace std;

int main() {
    int num[10000];
    int count = 0;

    cout << "Enter the integer numbers," << endl << "To stop entering numbers, press 0" << endl;

    for (int i = 0; ; i++) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        num[count++] = n;
    }

    cout << "You entered the following numbers: " << endl;
    for (int i = 0; i < count; i++) {
        cout << num[i] << endl;
    }

    cout << "Total number of input numbers: " << count << endl;

    for (int i = 0; i < count; i++) {
        if (num[i] % 2 == 0) {
            cout << num[i] << " is Even" << endl;
        } else {
            cout << num[i] << " is Odd" << endl;
        }
    }

    return 0;
}
