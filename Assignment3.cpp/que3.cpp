#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string expr) {
    stack<char> st;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        // If it's an opening bracket, push it
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        // If it's a closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {
            // If stack is empty, no matching opening bracket
            if (st.empty()) {
                return false;
            }
            char top = st.top();
            st.pop();

            // Check if top matches the closing bracket
            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false;
            }
        }
    }

    // If stack is empty, all brackets matched
    return st.empty();
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression)) {
        cout << "Balanced parentheses!" << endl;
    } else {
        cout << "Not balanced parentheses!" << endl;
    }

    return 0;
}
