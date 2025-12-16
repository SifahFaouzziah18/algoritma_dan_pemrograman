#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int at, bt, remaining;
    int qlevel;
    int ct, tat, wt, rt;
    bool started = false;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "Nama proses : ";
        cin >> p[i].name;
        cout << "Arrival Time: ";
        cin >> p[i].at;
        cout << "Burst Time  : ";
        cin >> p[i].bt;
        cout << "Queue Level (1=RR, 2=FCFS): ";
        cin >> p[i].qlevel;

        p[i].remaining = p[i].bt;
        p[i].started = false;
        cout << endl;
    }

    queue<int> q1; // RR
    queue<int> q2; // FCFS

    int time = 0, completed = 0;
    int quantum = 2;

    vector<pair<int,string>> gantt; // (time, label)

    // untuk memudahkan proses arrival
    vector<bool> added(n, false);

    while (completed < n) {

        // Tambahkan proses yang datang ke queue sesuai level
        for (int i = 0; i < n; i++) {
            if (!added[i] && p[i].at <= time) {
                if (p[i].qlevel == 1) q1.push(i);
                else q2.push(i);
                added[i] = true;
            }
        }

        int idx = -1;
        bool fromQ1 = false;

        // Eksekusi queue level 1 (RR) lebih dulu
        if (!q1.empty()) {
            idx = q1.front();
            q1.pop();
            fromQ1 = true;
        }
        else if (!q2.empty()) {
            idx = q2.front();
            q2.pop();
            fromQ1 = false;
        }

        if (idx != -1) {
            // Gantt chart label
            string label = (fromQ1 ? "L1-" : "L2-") + p[idx].name;
            if (gantt.empty() || gantt.back().second != label)
                gantt.push_back({time, label});

            // Response time
            if (!p[idx].started) {
                p[idx].rt = time - p[idx].at;
                p[idx].started = true;
            }

            if (fromQ1) {
                // Round Robin (quantum = 2)
                int run = min(quantum, p[idx].remaining);
                for (int t = 0; t < run; t++) {
                    p[idx].remaining--;
                    time++;

                    // check arrival selama eksekusi
                    for (int j = 0; j < n; j++) {
                        if (!added[j] && p[j].at <= time) {
                            if (p[j].qlevel == 1) q1.push(j);
                            else q2.push(j);
                            added[j] = true;
                        }
                    }
                }

                if (p[idx].remaining > 0)
                    q1.push(idx); // masukkan kembali ke RR
                else {
                    p[idx].ct = time;
                    p[idx].tat = p[idx].ct - p[idx].at;
                    p[idx].wt = p[idx].tat - p[idx].bt;
                    completed++;
                }

            } else {
                // FCFS berjalan sampai selesai
                p[idx].remaining--;
                time++;

                if (p[idx].remaining == 0) {
                    p[idx].ct = time;
                    p[idx].tat = p[idx].ct - p[idx].at;
                    p[idx].wt = p[idx].tat - p[idx].bt;
                    completed++;
                } else {
                    q2.push(idx); // FCFS diputar balik
                }
            }

        } else {
            // Idle
            time++;
        }
    }

    // OUTPUT
    cout << "\n===== GANTT CHART =====\n";
    for (auto &g : gantt)
        cout << "|" << g.first << " " << g.second << " ";
    cout << "|" << time << endl;

    cout << "\n===== TABEL HASIL =====\n";
    cout << left << setw(10) << "Proses"
         << setw(10) << "AT"
         << setw(10) << "BT"
         << setw(10) << "QL"
         << setw(10) << "CT"
         << setw(10) << "TAT"
         << setw(10) << "WT"
         << setw(10) << "RT"
         << endl;

    double wt_q1=0, tat_q1=0, c1=0;
    double wt_q2=0, tat_q2=0, c2=0;

    for (auto &x : p) {
        cout << left << setw(10) << x.name
             << setw(10) << x.at
             << setw(10) << x.bt
             << setw(10) << x.qlevel
             << setw(10) << x.ct
             << setw(10) << x.tat
             << setw(10) << x.wt
             << setw(10) << x.rt
             << endl;

        if (x.qlevel == 1) {
            wt_q1 += x.wt; tat_q1 += x.tat; c1++;
        } else {
            wt_q2 += x.wt; tat_q2 += x.tat; c2++;
        }
    }

    cout << "\n===== PERBANDINGAN (Queue 1 vs Queue 2) =====\n";
    cout << "Average WT Queue 1: " << (wt_q1 / c1) << endl;
    cout << "Average WT Queue 2: " << (wt_q2 / c2) << endl;
    cout << "Average TAT Queue 1: " << (tat_q1 / c1) << endl;
    cout << "Average TAT Queue 2: " << (tat_q2 / c2) << endl;

    cout << "\n===== ANALISIS MLQ =====\n";
    cout << "Kelebihan:\n";
    cout << "- Proses penting (Queue 1) mendapat prioritas tinggi.\n";
    cout << "- Respons cepat untuk tugas kecil pada level tinggi.\n";
    cout << "- Mudah diimplementasikan dan dipahami.\n\n";

    cout << "Kelemahan:\n";
    cout << "- Queue 2 berpotensi mengalami starvation jika Queue 1 sangat sibuk.\n";
    cout << "- Proses tidak bisa naik atau turun level (fixed class).\n";
    cout << "- Fairness kurang baik dibanding MLFQ.\n";

    return 0;
}