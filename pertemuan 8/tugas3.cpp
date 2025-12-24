#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool checkValid(string s) {
    stack<char> st;

    for (char c : s) {
        
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        }
        
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) return false; 

            char top = st.top();
            st.pop();

            if (!isMatching(top, c)) return false; 
        }
    }

    return st.empty(); 
}

int main() {
    string input;
    cout << "Input : ";
    getline(cin, input);

    if (checkValid(input))
        cout << "Output : Valid\n";
    else
        cout << "Output : Tidak Valid\n";

    return 0;
}