#include <iostream>
using namespace std;

const int MAX = 10;

struct Queue {
    int data[MAX];
    int front;
    int rear;
};

void init(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue q) {
    return (q.front == -1);
}

bool isFull(Queue q) {
    return (q.rear == MAX - 1);
}

void enqueue(Queue &q, int value) {
    if (isFull(q)) {
        cout << "Queue penuh!\n";
    } else {
        if (isEmpty(q)) {
            q.front = q.rear = 0;
        } else {
            q.rear++;
        }
        q.data[q.rear] = value;
        cout << "Data " << value << " ditambahkan.\n";
    }
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Data " << q.data[q.front] << " dihapus.\n";
        if (q.front == q.rear) {
            q.front = q.rear = -1;
        } else {
            q.front++;
        }
    }
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Queue kosong!\n";
    } else {
        cout << "Isi queue: ";
        for (int i = q.front; i <= q.rear; i++) {
            cout << q.data[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    Queue q;
    init(q);

    int choice, value;

    do {
        cout << "\nMenu Queue:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Tampilkan\n";
        cout << "4. Keluar\n";
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan nilai: ";
            cin >> value;
            enqueue(q, value);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
            break;
        case 4:
            cout << "Program selesai.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }

    } while (choice != 4);

    return 0;
}