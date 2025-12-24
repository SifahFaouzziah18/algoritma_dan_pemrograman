#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int cari;
    bool ketemu = false;

    cout << "Masukkan angka yang ingin dicari: ";
    cin >> cari;

    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (arr[mid] == cari) {
            cout << "Data ditemukan pada indeks ke-" << mid << endl;
            ketemu = true;
            break;
        } else if (arr[mid] < cari) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan" << endl;
    }

    return 0;
}