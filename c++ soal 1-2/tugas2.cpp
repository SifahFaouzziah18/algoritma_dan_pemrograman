#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 10, 15, 20, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int cari;
    bool ketemu = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    for (int i = 0; i < n; i++) {
        if (arr[i] == cari) {
            cout << "Data ditemukan pada indeks ke-" << i << endl;
            ketemu = true;
            break;
        } else if (arr[i] > cari) { 
            
            break;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}