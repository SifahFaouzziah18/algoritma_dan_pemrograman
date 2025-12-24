#include <iostream>
using namespace std;

int main() {
    const int MAX = 100;
    string nama[MAX], jenisLaundry[MAX], status[MAX];
    float berat[MAX], harga[MAX];
    int jumlahData = 0;
    int pilihan;

    do {
        cout << "\n=== APLIKASI PENGELOLAAN LAUNDRY ===\n";
        cout << "1. Tambah Data Laundry\n";
        cout << "2. Tampilkan Data Laundry\n";
        cout << "3. Ubah Status Laundry\n";
        cout << "4. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        if (pilihan == 1) {
            if (jumlahData >= MAX) {
                cout << "Data sudah penuh!\n";
            } else {
                cout << "\nNama Pelanggan : ";
                cin.ignore();
                getline(cin, nama[jumlahData]);

                cout << "Berat Laundry (kg) : ";
                cin >> berat[jumlahData];

                cout << "Jenis Laundry (1. Cuci / 2. Cuci + Setrika) : ";
                int jenis;
                cin >> jenis;

                if (jenis == 1) {
                    jenisLaundry[jumlahData] = "Cuci";
                    harga[jumlahData] = berat[jumlahData] * 5000;
                } else {
                    jenisLaundry[jumlahData] = "Cuci + Setrika";
                    harga[jumlahData] = berat[jumlahData] * 8000;
                }

                status[jumlahData] = "Proses";
                jumlahData++;

                cout << "Data laundry berhasil ditambahkan!\n";
            }
        } 
        else if (pilihan == 2) {
            if (jumlahData == 0) {
                cout << "Belum ada data laundry.\n";
            } else {
                cout << "\n=== DAFTAR DATA LAUNDRY ===\n";
                for (int i = 0; i < jumlahData; i++) {
                    cout << "\nData ke-" << i + 1 << endl;
                    cout << "Nama          : " << nama[i] << endl;
                    cout << "Berat         : " << berat[i] << " kg\n";
                    cout << "Jenis Laundry : " << jenisLaundry[i] << endl;
                    cout << "Total Harga   : Rp " << harga[i] << endl;
                    cout << "Status        : " << status[i] << endl;
                }
            }
        } 
        else if (pilihan == 3) {
            int index;
            cout << "Masukkan nomor data yang ingin diubah statusnya: ";
            cin >> index;

            if (index > 0 && index <= jumlahData) {
                status[index - 1] = "Selesai";
                cout << "Status laundry berhasil diubah menjadi SELESAI.\n";
            } else {
                cout << "Nomor data tidak valid.\n";
            }
        } 
        else if (pilihan == 4) {
            cout << "Terima kasih telah menggunakan aplikasi laundry.\n";
        } 
        else {
            cout << "Pilihan tidak valid!\n";
        }

    } while (pilihan != 4);

    return 0;
}