#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    float nilai_akhir;
};

int main() {
    Mahasiswa mhs[5];
    float total = 0;
    float rata_rata;

    // Input data 5 mahasiswa
    for (int i = 0; i < 5; i++) {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama         : ";
        getline(cin, mhs[i].nama);
        cout << "Nilai Akhir  : ";
        cin >> mhs[i].nilai_akhir;
        cin.ignore(); // membersihkan buffer
        cout << endl;

        total += mhs[i].nilai_akhir; // tambahkan ke total
    }

    // Hitung rata-rata
    rata_rata = total / 5;

    // Tampilkan hasil
    cout << "=====================================\n";
    cout << "Data Nilai Mahasiswa\n";
    cout << "=====================================\n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << mhs[i].nama 
             << " - Nilai Akhir: " << mhs[i].nilai_akhir << endl;
    }
    cout << "=====================================\n";
    cout << "Rata-rata Nilai Kelas : " << rata_rata << endl;

    return 0;
}
