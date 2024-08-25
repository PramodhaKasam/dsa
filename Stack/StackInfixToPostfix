// Conversion of Infix to Postfix
#include <bits/stdc++.h>
using namespace std;

class Stack {
public:
    char data;
    Stack* next;
    Stack(char val) {
        data = val;
        next = nullptr;
    }
};

void push(Stack*& s1, char x) {
    Stack* newnode = new Stack(x);
    if (s1 == NULL) {
        s1 = newnode;
    } else {
        newnode->next = s1;
        s1 = newnode;
    }
}

void pop(Stack*& s1) {
    if (s1 != NULL) {
        cout << s1->data;
        Stack* temp = s1;
        s1 = s1->next;
        delete temp;
    } else {
        cout << "ERROR!!!\n";
    }
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '^')
        return 3;
    return 0;
}

int associativity(char ch)
{
    if(ch != '^')
    {
        return 0;
    }
    else{
        return 1;
    }
}

void ConvertToPostfix(Stack*& s1, string str) {
    for (int i = 0; i < str.size(); i++) {
        if (isalpha(str[i])) {
            cout << str[i];
        } else if (str[i] == '(') {
            push(s1, str[i]);
        } else if (str[i] == ')') {
            while (s1 != NULL && s1->data != '(') {
                pop(s1);
            }
            if (s1 != NULL) { 
                Stack* temp = s1;
                s1 = s1->next;
                delete temp;
            }
        } else { 
            while (s1 != NULL && ((precedence(s1->data) > precedence(str[i])) || (precedence(s1->data) == precedence(str[i]) && associativity(s1->data) == 0))) {
                pop(s1);
            }
            push(s1, str[i]);
        }
    }
    while (s1 != NULL) {
        pop(s1);
    }
}

int main() {
    Stack* s1 = NULL;
    string str;
    cin >> str;
    ConvertToPostfix(s1, str);
    return 0;
}
