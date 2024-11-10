//Conversion of prefix to infix
#include <bits/stdc++.h>
using namespace std;

struct node {
    string data;
    node* next;
};

node* newNode(string str) {
    node* temp = new node;
    temp->data = str;
    temp->next = NULL;
    return temp;
}

void push(node*& s1, string str) {
    node* temp = newNode(str);
    temp->next = s1;
    s1 = temp;
}

void pop(node*& s1) {
    if (s1 == NULL) return;
    node* temp = s1;
    s1 = s1->next;
    delete temp;
}

string reverse(const string& str) {
    string str2 = "";
    int k = str.size();
    for (int i = 0; i < k; i++) {
        str2 += str[k - i - 1];
    }
    return str2;
}

void convertToInfix(node*& s1, string str) {
    string str2 = reverse(str);
    int k = str2.size();
    for (int i = 0; i < k; i++) {
        if (isalpha(str2[i])) {
            string x(1, str2[i]);
            push(s1, x);
        } else {
            string str0 = s1->data;
            pop(s1);
            string str1 = s1->data;
            pop(s1);
            string str3 = "( " + str1 + " " + str2[i] + " " + str0 + " )";
            push(s1, str3);
        }
    }
    cout << s1->data;
}

int main() {
    node* s1 = NULL;
    string str = "+A*BC";
    convertToInfix(s1, str);
    return 0;
}
