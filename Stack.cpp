#include<iostream>
using namespace std;

class stack {
private:
    int size, top;
    int* arr;

public:
    stack(int s) {
        size = s;
        top = -1;
        arr = new int[size];   // memory allocation
    }

    // check the stack is empty or not
    bool isempty() {
        return top == -1;
    }

    bool isfull() {
        return top == size - 1;
    }

    void push(int value) {
        if (isfull()) {
            cout << "Stack is full" << endl;
            return;
        }

        arr[++top] = value;
        cout << value << " element pushed" << endl;
    }

    void pop() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << arr[top] << " element popped" << endl;
        top--;
    }

    void peek() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Top element is: " << arr[top] << endl;
    }

    void display() {
        if (isempty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        cout << "Stack elements are:" << endl;

        for (int i = top; i >= 0; i--) {
            cout << arr[i] << endl;
        }
    }

    ~stack() {
        delete[] arr;
    }
};

int main() {
    stack st(5);

    cout << "Stack is created" << endl;

    while (true) {
        int choice;

        cout << "\n1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Display" << endl;
        cout << "4.Peek" << endl;
        cout << "5.delete" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        int val;

        if (choice == 1) {
            cout << "Enter value to push: ";
            cin >> val;
            st.push(val);
        }

        else if (choice == 2) {
            st.pop();
        }

        else if (choice == 3) {
            st.display();
        }

        else if (choice == 4) {
            st.peek();
        }
        else if (choice == 5) {
            cout << "stack deleted" << endl;
            st.~stack();
        }

        else if (choice == 6) {
            cout << "Exiting" << endl;
            break;
        }

        else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}
