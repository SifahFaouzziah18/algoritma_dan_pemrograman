#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    Mahasiswa mhs[3];

    // Input data mahasiswa
    for (int i = 0; i < 3; i++) {
        cout << "\nMasukkan data mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin, mhs[i].nama);
        cout << "NIM  : ";
        getline(cin, mhs[i].nim);
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cin.ignore(); // membersihkan buffer
    }

    // Output data dalam bentuk tabel
    cout << "\n==============================================\n";
    cout << left << setw(5) << "No"
         << setw(20) << "Nama"
         << setw(15) << "NIM"
         << "IPK" << endl;
    cout << "==============================================\n";

    for (int i = 0; i < 3; i++) {
        cout << left << setw(5) << i + 1
             << setw(20) << mhs[i].nama
             << setw(15) << mhs[i].nim
             << mhs[i].ipk << endl;
    }

    cout << "==============================================\n";

    return 0;
}