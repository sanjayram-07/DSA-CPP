#include<iostream>
using namespace std;

class para {
public:
    char arr[100]; 
    int top = -1;

    void push(char c) {
        arr[++top] = c;
    }

    void pop() {
        if (top >= 0) top--;
    }

    char topChar() {
        return arr[top];
    }


    void calc(string a) {
        for (int i = 0; i < a.length(); i++) {
            char ch = a[i];

            if (ch == '(' || ch == '[' || ch == '{') {
                push(ch);
            }
            else if (ch == ')' || ch == ']' || ch == '}') {
                if (top==-1) { 
                    cout << "Invalid";
                    return;
                }
                if ((ch == ')' && topChar() == '(') ||
                    (ch == ']' && topChar() == '[') ||
                    (ch == '}' && topChar() == '{')) {
                    pop();
                }
                else {
                    cout << "Invalid";
                    return;
                }
            }
        }

        if (top==-1)
            cout << "Valid";
        else
            cout << "Invalid";
    }
};

int main() {
    para obj;
    string a;
    cout << "Enter expression: ";
    cin >> a;  
    obj.calc(a);
}
