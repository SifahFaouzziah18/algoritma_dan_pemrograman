#include <iostream>
using namespace std;

#define MAX 5   
int q[MAX];
int front = 0;
int rear = 0;
int countData = 0;


bool isFull() {
    return countData == MAX;
}


bool isEmpty() {
    return countData == 0;
}


void enqueue(int data) {
    if (isFull()) {
        cout << "Queue penuh!\n";
        return;
    }
    q[rear] = data;
    rear = (rear + 1) % MAX;
    countData++;
}


int dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong!\n";
        return -1;
    }
    int data = q[front];
    front = (front + 1) % MAX;
    countData--;
    return data;
}


void display() {
    cout << "Isi queue : ";
    for (int i = 0; i < countData; i++) {
        int index = (front + i) % MAX;
        cout << q[index] << " ";
    }
    cout << endl;
}

int main() {

    
    for (int i = 1; i <= MAX; i++) {
        enqueue(i * 10);  
    }

    
    dequeue();
    dequeue();
    dequeue();

    
    enqueue(99);
    enqueue(88);

    
    cout << "Posisi front : " << front << endl;
    cout << "Posisi rear  : " << rear << endl;

    
    display();

    return 0;
}