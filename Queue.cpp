#include<iostream>
using namespace std;
class queue
{
private:
	int* arr;
	int front, rear;
	int capacity;
public:
    queue(int size) {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
    }
    bool isempty() {
        return rear<front;
    }

    bool isfull() {
        return rear==capacity-1;
    }
    void enqueue(int value) {
        if (isfull()) {
            cout << "Queue Overload.Cannot insert" << endl;
            return;
        }

        arr[++rear] = value;
        cout << value << " element is inserted" << endl;
    }
    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << arr[front] << " element removed" << endl;
        front--;
    }
    void display(){
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue elements are:" << endl;

        for (int i = front; i <= rear; i++) {
            cout << arr[i] << endl;
        }
    }
    void peek() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Front element is: " << arr[front] << endl;
    }
    ~queue() {
        delete[] arr;
    }
};
int main() {
    queue qt(5);

    cout << "Queue is created" << endl;

    while (true) {
        int choice;

        cout << "\n1.Enqueue" << endl;
        cout << "2.display" << endl;
        cout << "3.Dequeue" << endl;
        cout << "4.Peek" << endl;
        cout << "5.delete" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        int val;

        if (choice == 1) {
            cout << "Enter value to enqueue: ";
            cin >> val;
            qt.enqueue(val);
        }

        else if (choice == 2) {
            qt.display();
        }
        else if (choice == 3) {
            qt.dequeue();
        }
        else if (choice == 4) {
            qt.peek();
        }
        else if (choice == 5) {
            qt.~queue();
        }
        else if (choice == 6) {
            cout << "exiting" << endl;
            break;
        }
        return 0;
    }
}
