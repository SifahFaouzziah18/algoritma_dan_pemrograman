#include <bits/stdc++.h>
using namespace std;

struct Process {
    string name;
    int AT, BT;
    int priority;
    int remaining;
    int CT, TAT, WT, RT;
    bool started = false;

    int lastWaitStart; // kapan mulai menunggu (untuk aging)
};

int main() {

    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "\nNama proses : ";
        cin >> p[i].name;
        cout << "Arrival Time : ";
        cin >> p[i].AT;
        cout << "Burst Time : ";
        cin >> p[i].BT;
        cout << "Priority (lebih kecil = lebih tinggi): ";
        cin >> p[i].priority;

        p[i].remaining = p[i].BT;
        p[i].lastWaitStart = p[i].AT;
    }

    vector<string> gantt;

    int time = 0;
    int complete = 0;
    int prev = -1;
    int preemptions = 0;
    int priorityChanges = 0;

    while (complete < n) {

        int idx = -1;
        int bestPriority = 9999;

        // cari proses prioritas tertinggi yg sudah datang
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].remaining > 0) {
                if (p[i].priority < bestPriority) {
                    bestPriority = p[i].priority;
                    idx = i;
                }
            }
        }

        // idle jika tidak ada proses
        if (idx == -1) {
            gantt.push_back("idle");
            time++;
            continue;
        }

        // cek preemption
        if (prev != -1 && prev != idx) {
            preemptions++;
        }
        prev = idx;

        // response time
        if (!p[idx].started) {
            p[idx].RT = time - p[idx].AT;
            p[idx].started = true;
        }

        // proses ini berjalan → berarti dia tidak lagi menunggu
        p[idx].lastWaitStart = time;

        // jalankan 1 satuan waktu
        p[idx].remaining--;
        gantt.push_back(p[idx].name);
        time++;

        // aging untuk proses lain
        for (int i = 0; i < n; i++) {
            if (i == idx) continue; // yang sedang running tidak di-age

            if (p[i].remaining > 0 && p[i].AT <= time) {
                int waited = time - p[i].lastWaitStart;

                if (waited > 5) {
                    p[i].priority--; // naik prioritas
                    priorityChanges++;
                    p[i].lastWaitStart = time; // reset aging timer
                }
            }
        }

        // cek apakah proses selesai
        if (p[idx].remaining == 0) {
            p[idx].CT = time;
            complete++;
        }
    }

    // hitung TAT dan WT
    for (int i = 0; i < n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }

    // OUTPUT
    cout << "\n=== GANTT CHART ===\n";
    for (auto &g : gantt) {
        cout << g << " ";
    }
    cout << "\n";

    cout << "\n=== TABEL HASIL ===\n";
    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.AT << "\t" << x.BT << "\t"
             << x.CT << "\t" << x.TAT << "\t" << x.WT << "\t" << x.RT << "\n";
    }

    cout << "\nJumlah preemption: " << preemptions << endl;
    cout << "Jumlah perubahan priority (aging): " << priorityChanges << endl;

    return 0;
}