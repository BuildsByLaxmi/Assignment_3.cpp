#include <iostream>
#include <stack>
using namespace std;

string reverseStringUsingStack(const string& str) {
    stack<char> st;

    // Push all characters onto the stack
    for (char ch : str) {
        st.push(ch);
    }

    string reversedStr;
    // Pop characters from the stack to get the reversed string
    while (!st.empty()) {
        reversedStr += st.top();
        st.pop();
    }

    return reversedStr;
}

int main() {
    string input = "DataStructure";
    string output = reverseStringUsingStack(input);

    cout << output << endl;  // Output: erutcurtSataD

    return 0;
}
