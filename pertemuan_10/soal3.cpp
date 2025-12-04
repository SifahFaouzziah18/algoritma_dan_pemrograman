#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, ct, tat, wt, rt;
    int bt_remain;
    int q; // 1=RR, 2=FCFS
    bool started;
};

int main() {
    int n;
    cout << "Jumlah proses: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Nama proses: ";
        cin >> p[i].name;
        cout << "Arrival Time: ";
        cin >> p[i].at;
        cout << "Burst Time: ";
        cin >> p[i].bt;
        cout << "Queue (1=RR, 2=FCFS): ";
        cin >> p[i].q;

        p[i].bt_remain = p[i].bt;
        p[i].started = false;
        cout << endl;
    }

    int time = 0, done = 0;
    queue<int> q1; // RR
    queue<int> q2; // FCFS
    string gantt = "";

    while (done < n) {

        // Masukkan proses yang tiba ke queue
        for (int i = 0; i < n; i++) {
            if (p[i].at == time) {
                if (p[i].q == 1) q1.push(i);
                else q2.push(i);
            }
        }

        // Eksekusi LEVEL 1 (RR)
        if (!q1.empty()) {
            int idx = q1.front();
            q1.pop();

            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            int quantum = 2;
            while (quantum-- && p[idx].bt_remain > 0) {
                gantt += p[idx].name + " ";
                time++;
                p[idx].bt_remain--;

                for (int i = 0; i < n; i++)
                    if (p[i].at == time)
                        (p[i].q == 1 ? q1 : q2).push(i);
            }

            if (p[idx].bt_remain == 0) {
                p[idx].ct = time;
                done++;
            } else {
                q1.push(idx);
            }
        }
        // Eksekusi LEVEL 2 (FCFS)
        else if (!q2.empty()) {
            int idx = q2.front();
            q2.pop();

            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            while (p[idx].bt_remain > 0) {
                gantt += p[idx].name + " ";
                time++;
                p[idx].bt_remain--;

                for (int i = 0; i < n; i++)
                    if (p[i].at == time)
                        (p[i].q == 1 ? q1 : q2).push(i);

                if (!q1.empty()) break;
            }

            if (p[idx].bt_remain == 0) {
                p[idx].ct = time;
                done++;
            } else {
                q2.push(idx);
            }
        } else {
            // CPU idle
            gantt += "- ";
            time++;
        }
    }

    // Hitung TAT, WT
    for (int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt  = p[i].tat - p[i].bt;
    }

    // Output
    cout << "\n=== Gantt Chart ===\n" << gantt << endl;

    cout << "\n=== Tabel Proses ===\n";
    cout << left << setw(6) << "P"
         << setw(6) << "AT"
         << setw(6) << "BT"
         << setw(6) << "Q"
         << setw(6) << "CT"
         << setw(6) << "TAT"
         << setw(6) << "WT"
         << setw(6) << "RT"
         << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(6) << p[i].name
             << setw(6) << p[i].at
             << setw(6) << p[i].bt
             << setw(6) << p[i].q
             << setw(6) << p[i].ct
             << setw(6) << p[i].tat
             << setw(6) << p[i].wt
             << setw(6) << p[i].rt
             << endl;
    }

    return 0;
}