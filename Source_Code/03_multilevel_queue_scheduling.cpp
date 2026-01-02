#include <iostream>
using namespace std;

int main() {
    int n1, n2, tq;

    cout << "Enter number of System processes (Queue 1): ";
    cin >> n1;

    int bt1[n1];
    for(int i = 0; i < n1; i++) {
        cout << "Burst Time of System Process P" << i+1 << ": ";
        cin >> bt1[i];
    }

    cout << "Enter Time Quantum for Queue 1: ";
    cin >> tq;

    cout << "\nEnter number of User processes (Queue 2): ";
    cin >> n2;

    int bt2[n2];
    for(int i = 0; i < n2; i++) {
        cout << "Burst Time of User Process P" << i+1 << ": ";
        cin >> bt2[i];
    }

    cout << "\n--- Executing Queue 1 (Round Robin) ---\n";
    for(int i = 0; i < n1; i++) {
        while(bt1[i] > 0) {
            if(bt1[i] > tq) {
                cout << "P" << i+1 << " executed for " << tq << " units\n";
                bt1[i] -= tq;
            } else {
                cout << "P" << i+1 << " executed for " << bt1[i] << " units\n";
                bt1[i] = 0;
            }
        }
    }

    cout << "\n--- Executing Queue 2 (FCFS) ---\n";
    for(int i = 0; i < n2; i++) {
        cout << "User Process P" << i+1 << " executed for "
             << bt2[i] << " units\n";
    }

    return 0;
}
