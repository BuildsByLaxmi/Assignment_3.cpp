#include <iostream>
#include <stack>
using namespace std;

int main() {
    string postfix;
    cout << "Enter postfix expression (e.g. 23*4+): ";
    cin >> postfix;

    stack<int> st;

    for (int i = 0; i < postfix.length(); i++) {
        char ch = postfix[i];

        // If it's a digit, push it to stack (convert char to int)
        if (ch >= '0' && ch <= '9') {
            st.push(ch - '0');
        }
        // If it's an operator, pop two numbers and calculate
        else {
            int val2 = st.top();
            st.pop();
            int val1 = st.top();
            st.pop();

            if (ch == '+') {
                st.push(val1 + val2);
            }
            else if (ch == '-') {
                st.push(val1 - val2);
            }
            else if (ch == '*') {
                st.push(val1 * val2);
            }
            else if (ch == '/') {
                st.push(val1 / val2);
            }
        }
    }

    // The final result will be on top of the stack
    cout << "Result: " << st.top() << endl;

    return 0;
}
