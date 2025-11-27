#include <iostream>
using namespace std;

const int MAX = 5;

int q[MAX];
int frontIdx = 0;
int rearIdx = -1;
int countQ = 0;

bool isFull() {
    return countQ == MAX;
}

bool isEmpty() {
    return countQ == 0;
}

void enqueue(int x) {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }
    rearIdx = (rearIdx + 1) % MAX;
    q[rearIdx] = x;
    countQ++;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Menghapus: " << q[frontIdx] << endl;
    frontIdx = (frontIdx + 1) % MAX;
    countQ--;
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return;
    }
    cout << "Isi queue: ";
    int idx = frontIdx;
    for (int i = 0; i < countQ; i++) {
        cout << q[idx] << " ";
        idx = (idx + 1) % MAX;
    }
    cout << endl;
}

int main() {
    
    cout << "Mengisi queue sampai penuh...\n";
    for (int i = 1; i <= MAX; i++) {
        enqueue(i * 10);
    }
    display();

    
    cout << "\nMenghapus 3 elemen...\n";
    dequeue();
    dequeue();
    dequeue();
    display();

    
    cout << "\nMenambah 2 elemen baru...\n";
    enqueue(88);
    enqueue(66);
    display();

    
    cout << "\nPosisi front = " << frontIdx << endl;
    cout << "Posisi rear = " << rearIdx << endl;

    return 0;
}