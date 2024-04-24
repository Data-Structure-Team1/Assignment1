#include <iostream>
using namespace std;

template<class T>
struct Node {
    T data;
    Node<T>* next;
};

template<class T>
class Stack_list {
private:
    Node<T>* top;
    int count;
public:
    Stack_list() {
        top = NULL;
        count = 0;
    }

    bool isEmpty() {
        return count == 0;
    }

    void push(T element) {
        Node<T>* newnode = new Node<T>;
        newnode->data = element;
      
            newnode->next = top;
            top = newnode;
       
        count++;
    }

    T pop() {
        T popvalue;
        if (isEmpty()) {
            cout << "ERROR: Stack is empty\n";
            return T();
        }
        else {
            Node<T>* temp = top;
            top = top->next;
            popvalue = temp->data;
            delete temp;
        }
        count--;
        return popvalue;
    }

    T Top() {
        if (isEmpty()) {
            cout << "ERROR: Stack is empty\n";
            return T();
        }
        return top->data;
    }

    int stackSize() {
        return count;
    }

    void clear() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
       
        while (top != NULL) {
            Node<T>* temp = top;
            top = top->next;
            delete temp;
        }
        top = NULL;
        count = 0;
    }

    void print() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return;
        }
        Node<T>* curr = top;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack_list<int> s;
    s.push(1);
    cout << "Stack Top: " << s.Top() << endl;


    s.push(22);
    s.push(3);
    s.print();
    cout << "Stack size: " << s.stackSize() << endl;
    cout << "Stack Top: " << s.Top() << endl;

    cout << "Popped: " << s.pop() << endl;
    s.print();
    cout << "Stack size: " << s.stackSize() << endl;
    cout << "Stack Top: " << s.Top() << endl;
    s.clear();
    cout << "Stack size: " << s.stackSize() << endl;
    s.print();

    return 0;
}
 
