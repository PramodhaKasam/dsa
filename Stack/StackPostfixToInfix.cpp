// Conversion of Postfix to Infix
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    string data;
    Stack* next;
    Stack(string x) {
        data = x;
        next = nullptr;
    }
};

void push(Stack* &s1, string ch) {
    Stack* newnode = new Stack(ch);
    newnode->next = s1;
    s1 = newnode;
}

void pop(Stack* &s1) {
    if (s1 != NULL) {
        Stack* temp = s1;
        s1 = s1->next;
        delete temp;
    }
}

string ConvertToInfix(Stack* &s1, string str) {
    string ans;
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            string x(1, str[i]); // Convert char to string
            push(s1, x);
        } else {
            string A = s1->data;
            pop(s1);
            string B = s1->data;
            pop(s1);
            ans = '(' + B + str[i] + A + ')';
            push(s1, ans);
        }
    }
    ans = s1->data;
    pop(s1);
    return ans;
}

int main() {
    Stack* s1 = NULL;
    string str;
    cin >> str;
    cout << ConvertToInfix(s1, str);
    return 0;
}
