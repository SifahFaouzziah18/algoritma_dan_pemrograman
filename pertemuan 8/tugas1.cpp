#include <iostream>
using namespace std;

class Stack {
private:
    int top;
    int capacity;
    int *arr;

public:
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack penuh!\n";
            return;
        }
        arr[++top] = value;
        cout << "Data " << value << " berhasil di-push.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Data " << arr[top--] << " telah di-pop.\n";
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack kosong!\n";
            return;
        }
        cout << "Elemen paling atas: " << arr[top] << endl;
    }

    int size() {
        return top + 1;
    }
};

int main() {
    int kapasitas, pilihan, nilai;

    cout << "Masukkan kapasitas stack: ";
    cin >> kapasitas;

    Stack st(kapasitas);

    do {
        cout << "\n=== Menu Stack ===\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. IsEmpty\n5. Size\n6. Exit\n";
        cout << "Pilih menu: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            cout << "Masukkan data: ";
            cin >> nilai;
            st.push(nilai);
            break;
        case 2:
            st.pop();
            break;
        case 3:
            st.peek();
            break;
        case 4:
            cout << (st.isEmpty() ? "Stack kosong\n" : "Stack tidak kosong\n");
            break;
        case 5:
            cout << "Jumlah elemen: " << st.size() << endl;
            break;
        case 6:
            cout << "Keluar program.\n";
            break;
        default:
            cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 6);

    return 0;
}