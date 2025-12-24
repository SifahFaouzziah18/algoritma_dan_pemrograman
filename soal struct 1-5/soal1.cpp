#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float nilai;
};

int main() {
    Mahasiswa mhs1;

    
    cout << "Masukkan Nama  : ";
    getline(cin, mhs1.nama);
    cout << "Masukkan NIM   : ";
    getline(cin, mhs1.nim);
    cout << "Masukkan Nilai : ";
    cin >> mhs1.nilai;

    
    cout << "\n=== Data Mahasiswa ===\n";
    cout << "Nama  : " << mhs1.nama << endl;
    cout << "NIM   : " << mhs1.nim << endl;
    cout << "Nilai : " << mhs1.nilai << endl;

    return 0;
}