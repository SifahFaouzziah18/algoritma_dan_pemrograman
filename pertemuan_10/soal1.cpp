#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int AT, BT;
    int remaining;
    int CT, TAT, WT, RT;
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
        cout << "Arrival Time : ";
        cin >> p[i].AT;
        cout << "Burst Time : ";
        cin >> p[i].BT;
        p[i].remaining = p[i].BT;
    }

    int complete = 0, time = 0;
    int prev = -1; // untuk cek pergantian proses (preemption)
    int preemption = 0;

    vector<string> gantt;  // menyimpan urutan proses untuk Gantt Chart

    while (complete < n) {
        int idx = -1;
        int mn = 1e9;

        // cari proses dengan remaining time terkecil yang sudah datang
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].remaining > 0) {
                if (p[i].remaining < mn) {
                    mn = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            gantt.push_back("idle");
            time++;
            continue;
        }

        // jika proses berubah → preemption terjadi
        if (prev != -1 && prev != idx)
            preemption++;

        prev = idx;
        gantt.push_back(p[idx].name);

        // response time
        if (!p[idx].started) {
            p[idx].RT = time - p[idx].AT;
            p[idx].started = true;
        }

        p[idx].remaining--;
        time++;

        if (p[idx].remaining == 0) {
            p[idx].CT = time;
            complete++;
        }
    }

    // hitung TAT & WT
    for (int i = 0; i < n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }

    // -------------------------
    // OUTPUT HASIL
    // -------------------------

    cout << "\n=== Gantt Chart ===\n";
    for (int i = 0; i < gantt.size(); i++) {
        cout << gantt[i] << " ";
    }
    cout << "\n";

    cout << "\n=== Tabel Hasil ===\n";
    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.AT << "\t" << x.BT << "\t"
             << x.CT << "\t" << x.TAT << "\t" << x.WT << "\t" << x.RT << "\n";
    }

    cout << "\nJumlah preemption: " << preemption << endl;

    return 0;
}