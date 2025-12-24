#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
using namespace std;


void merge(vector<int> &arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    
    for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}


void mergeSort(vector<int> &arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    const int n = 10;
    vector<int> arr(n);

    
    srand(static_cast<unsigned int>(time(nullptr)));

    
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100 + 1;
    }

    
    cout << "Data sebelum diurutkan:\n";
    for (int x : arr) cout << x << " ";
    cout << "\n\n";

   
    mergeSort(arr, 0, n - 1);

    
    cout << "Data setelah diurutkan (ascending):\n";
    for (int x : arr) cout << x << " ";
    cout << "\n";

    return 0;
}