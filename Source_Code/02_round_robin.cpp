#include <iostream>
using namespace std;

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;

    int bt[n], rt[n], wt[n], tat[n];
    for(int i = 0; i < n; i++) {
        cout << "Burst Time of P" << i+1 << ": ";
        cin >> bt[i];
        rt[i] = bt[i];
        wt[i] = 0;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0;
    bool done;

    do {
        done = true;
        for(int i = 0; i < n; i++) {
            if(rt[i] > 0) {
                done = false;
                if(rt[i] > tq) {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
    }

    cout << "\nPID\tBT\tWT\tTAT";
    for(int i = 0; i < n; i++) {
        cout << "\nP" << i+1 << "\t" << bt[i] << "\t" << wt[i] << "\t" << tat[i];
    }

    return 0;
}
