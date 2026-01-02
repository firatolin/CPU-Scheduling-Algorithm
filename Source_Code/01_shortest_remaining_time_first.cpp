#include <iostream>
using namespace std;

int main() {
    int n, time = 0, completed = 0;
    cout << "Enter number of processes: ";
    cin >> n;

    int at[n], bt[n], rt[n], ct[n], tat[n], wt[n];

    for(int i = 0; i < n; i++) {
        cout << "\nProcess " << i+1 << " Arrival Time: ";
        cin >> at[i];
        cout << "Process " << i+1 << " Burst Time: ";
        cin >> bt[i];
        rt[i] = bt[i];
    }

    int min_rt, shortest;
    bool found;

    while(completed != n) {
        min_rt = 9999;
        found = false;

        for(int i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min_rt) {
                min_rt = rt[i];
                shortest = i;
                found = true;
            }
        }

        if(!found) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0) {
            completed++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    cout << "\nPID\tAT\tBT\tWT\tTAT";
    for(int i = 0; i < n; i++) {
        cout << "\nP" << i+1 << "\t" << at[i] << "\t" << bt[i]
             << "\t" << wt[i] << "\t" << tat[i];
    }

    return 0;
}
