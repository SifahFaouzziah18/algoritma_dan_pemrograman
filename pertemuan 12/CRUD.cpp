#include <iostream>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    string jurusan;
    string matkul;
    int nilai;
};

Mahasiswa mhs[100];
int total = 0;

// CREATE
void tambahData() {
    cout << "\nJumlah mahasiswa: ";
    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cout << "\nMahasiswa ke-" << total + 1 << endl;
        cout << "NIM     : ";
        cin >> mhs[total].nim;
        cout << "Nama    : ";
        cin.ignore();
        getline(cin, mhs[total].nama);
        cout << "Jurusan : ";
        getline(cin, mhs[total].jurusan);
        cout << "Matkul  : ";
        getline(cin, mhs[total].matkul);
        cout << "Nilai   : ";
        cin >> mhs[total].nilai;
        total++;
    }
}

// READ (HANYA 1 DATA BERDASARKAN NIM)
void tampilData() {
    if(total == 0) {
        cout << "\nData kosong\n";
        return;
    }

    string cari;
    cout << "\nMasukkan NIM yang ingin ditampilkan: ";
    cin >> cari;

    for(int i = 0; i < total; i++) {
        if(mhs[i].nim == cari) {
            cout << "\n=== DATA MAHASISWA ===\n";
            cout << "NIM     : " << mhs[i].nim << endl;
            cout << "Nama    : " << mhs[i].nama << endl;
            cout << "Jurusan : " << mhs[i].jurusan << endl;
            cout << "Matkul  : " << mhs[i].matkul << endl;
            cout << "Nilai   : " << mhs[i].nilai << endl;
            return;
        }
    }

    cout << "\nData tidak ditemukan\n";
}

// UPDATE
void updateData() {
    string cari;
    cout << "\nMasukkan NIM yang ingin diupdate: ";
    cin >> cari;

    for(int i = 0; i < total; i++) {
        if(mhs[i].nim == cari) {
            cout << "Nama baru    : ";
            cin.ignore();
            getline(cin, mhs[i].nama);
            cout << "Jurusan baru : ";
            getline(cin, mhs[i].jurusan);
            cout << "Matkul baru  : ";
            getline(cin, mhs[i].matkul);
            cout << "Nilai baru   : ";
            cin >> mhs[i].nilai;

            cout << "\nData berhasil diupdate\n";
            return;
        }
    }
    cout << "\nData tidak ditemukan\n";
}

// DELETE
void hapusData() {
    string cari;
    cout << "\nMasukkan NIM yang ingin dihapus: ";
    cin >> cari;

    for(int i = 0; i < total; i++) {
        if(mhs[i].nim == cari) {
            for(int j = i; j < total - 1; j++) {
                mhs[j] = mhs[j + 1];
            }
            total--;
            cout << "\nData berhasil dihapus\n";
            return;
        }
    }
    cout << "\nData tidak ditemukan\n";
}

// MAIN
int main() {
    int pilihan;

    do {
        cout << "\n=== SISTEM PERKULIAHAN ===\n";
        cout << "1. Tambah Data\n";
        cout << "2. Tampilkan Data (1 Mahasiswa)\n";
        cout << "3. Update Data\n";
        cout << "4. Hapus Data\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                tambahData();
                break;
            case 2:
                tampilData();
                break;
            case 3:
                updateData();
                break;
            case 4:
                hapusData();
                break;
            case 5:
                cout << "Program selesai\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while(pilihan != 5);

    return 0;
}