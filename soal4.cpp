#include <iostream>
using namespace std;

const int MAX = 10;

struct Customer {
    int nomor;
    int lamaPelayanan;
};

struct Queue {
    Customer data[MAX];
    int front;
    int rear;
};

void init(Queue &q) {
    q.front = q.rear = -1;
}

bool isEmpty(Queue q) {
    return q.front == -1;
}

bool isFull(Queue q) {
    return q.rear == MAX - 1;
}

void enqueue(Queue &q, int nomor, int waktu) {
    if (isFull(q)) {
        cout << "Antrian penuh!\n";
        return;
    }

    if (isEmpty(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }

    q.data[q.rear].nomor = nomor;
    q.data[q.rear].lamaPelayanan = waktu;

    cout << "Pelanggan " << nomor << " ditambahkan.\n";
}

void dequeue(Queue &q) {
    if (isEmpty(q)) {
        cout << "Tidak ada pelanggan!\n";
        return;
    }

    cout << "Melayani pelanggan " 
         << q.data[q.front].nomor 
         << " (" << q.data[q.front].lamaPelayanan 
         << " detik)\n";

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
}

void display(Queue q) {
    if (isEmpty(q)) {
        cout << "Tidak ada pelanggan menunggu.\n";
        return;
    }

    cout << "Pelanggan yang menunggu:\n";
    for (int i = q.front; i <= q.rear; i++) {
        cout << "- No " << q.data[i].nomor
             << " (waktu: " << q.data[i].lamaPelayanan << " detik)\n";
    }
}

int main() {
    Queue q;
    init(q);

    int pilih, nomor, waktu;
    while (true) {
        cout << "\n=== Menu Kasir ===\n";
        cout << "1. Tambah pelanggan\n";
        cout << "2. Layani pelanggan\n";
        cout << "3. Tampilkan pelanggan menunggu\n";
        cout << "4. Jumlah pelanggan\n";
        cout << "5. Keluar\n";
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih) {
        case 1:
            cout << "Nomor pelanggan: ";
            cin >> nomor;
            cout << "Waktu pelayanan: ";
            cin >> waktu;
            enqueue(q, nomor, waktu);
            break;

        case 2:
            dequeue(q);
            break;

        case 3:
            display(q);
            break;

        case 4:
            if (isEmpty(q)) cout << "0 pelanggan.\n";
            else cout << "Jumlah pelanggan: " << (q.rear - q.front + 1) << endl;
            break;

        case 5:
            return 0;

        default:
            cout << "Pilihan tidak valid!\n";
        }
    }
}