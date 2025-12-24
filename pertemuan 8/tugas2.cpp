#include <iostream>
#include <stack>
using namespace std;

int main() {
    string kalimat;
    stack<char> st;

    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    for (char c : kalimat) {
        st.push(c);
    }

    cout << "Kalimat terbalik: ";
    
    while (!st.empty()) {
        cout << st.top();
        st.pop();
    }

    cout << endl;
    return 0;
}