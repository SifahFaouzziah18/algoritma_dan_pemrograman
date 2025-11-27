#include <iostream>
using namespace std;

const int MAX = 10;

struct QueueChar {
    char data[MAX];
    int front;
    int rear;
};

void init(QueueChar &q) {
    q.front = q.rear = -1;
}

bool kosong(QueueChar q) {
    return (q.front == -1);
}

bool penuh(QueueChar q) {
    return (q.rear == MAX - 1);
}

void insert(QueueChar &q, char c) {
    if (penuh(q)) {
        cout << "Queue penuh!\n";
        return;
    }

    if (kosong(q)) {
        q.front = q.rear = 0;
    } else {
        q.rear++;
    }

    q.data[q.rear] = c;
}

void hapus(QueueChar &q) {
    if (kosong(q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Menghapus: " << q.data[q.front] << endl;

    if (q.front == q.rear) {
        q.front = q.rear = -1;
    } else {
        q.front++;
    }
}

void display(QueueChar q) {
    if (kosong(q)) {
        cout << "Queue kosong!\n";
        return;
    }

    cout << "Isi queue: ";
    for (int i = q.front; i <= q.rear; i++) {
        cout << q.data[i] << " ";
    }
    cout << endl;
}

int main() {
    QueueChar q;
    init(q);

    
    insert(q, 'A');
    insert(q, 'R');
    insert(q, 'I');
    insert(q, 'F');

    
    hapus(q);
    hapus(q);
    display(q);

    return 0;
}