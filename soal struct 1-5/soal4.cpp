#include <iostream>
#include <string>
using namespace std;

struct Alamat {
    string kota;
    string provinsi;
};

struct Mahasiswa {
    string nama;
    string nim;
    Alamat alamat;
};

// Fungsi untuk menampilkan data mahasiswa
void tampilData(Mahasiswa mhs) {
    cout << "\n=== Data Mahasiswa ===" << endl;
    cout << "Nama     : " << mhs.nama << endl;
    cout << "NIM      : " << mhs.nim << endl;
    cout << "Kota     : " << mhs.alamat.kota << endl;
    cout << "Provinsi : " << mhs.alamat.provinsi << endl;
}

int main() {
    Mahasiswa mhs;

    // Input data mahasiswa
    cout << "Masukkan Nama       : ";
    getline(cin, mhs.nama);
    cout << "Masukkan NIM        : ";
    getline(cin, mhs.nim);
    cout << "Masukkan Kota       : ";
    getline(cin, mhs.alamat.kota);
    cout << "Masukkan Provinsi   : ";
    getline(cin, mhs.alamat.provinsi);

    // Panggil fungsi tampilData
    tampilData(mhs);

    return 0;
}