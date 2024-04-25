#include <iostream>
using namespace std;
template <class T>
struct node {
    T item;
    node *next;
    node *pre;
    node(T data) : item(data), next(nullptr), pre(nullptr) {}
};

template <class T>
class doublyLinkedList {
    node<T> *first;
    node<T> *last;
    int length;
public:
    doublyLinkedList() {
        first = nullptr;
        last = nullptr;
        length = 0;
    }
    ~doublyLinkedList(){
        while (first!= nullptr){
            node<T>* current=first;
            first=first->next;
            delete current;
        }
    }

    bool isEmpty() const {
        return first == nullptr;
    }

    void insertAtHead(T element) {
        node<T> *newNode = new node(element);
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = newNode->pre = nullptr;
        } else {
            newNode->next = first;
            newNode->pre = nullptr;
            first->pre = newNode;
            first = newNode;
        }
        length++;
    }

//
    void insertAtTail(T element) {
        node<T> *newNode = new node(element);
        if (isEmpty()) {
            first = last = newNode;
            newNode->next = newNode->pre = nullptr;
        } else {
            newNode->next = nullptr;
            newNode->pre = last;
            last->next = newNode;
            last = newNode;
        }
        length++;
    }

    void insertAt(T element, int index) {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        if (index< 0||index >=length) {
            throw out_of_range("out of range");
        }
        else {
            node<T> *newNode = new node(element);
            if (index == 0) {
                insertAtHead(element);
            }
            if (index == length) {
                insertAtTail(element);
            } else {
                node<T> *current = first;
                for (int i = 0; i < index - 1; i++) {
                    current = current->next;
                }
                newNode->next = current->next;
                newNode->pre = current;
                current->next = newNode;
                current->next->next->pre = newNode;
                length++;
            }
        }
    }


    void removeAtHead() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        else if (length == 1) {
            delete first;
            last = first = nullptr;
        } else {
            node<T> *current = first;
            first = first->next;
            first->pre = nullptr;
            delete current;
        }
        length--;
    }

    void removeAtTail() {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        else if (length == 1) {
            delete first;
            last = first = nullptr;
        } else {
            node<T> *current = last;
            last = last->pre;
            last->next = nullptr;
            delete current;
        }
        length--;
    }

    void removeAt(int index) {
        if (isEmpty()) {
            cout<<"List is Empty"<<endl;
        }
        if (index< 0||index >=length) {
            cout<<"Out of the Range"<<endl;
        }
        if (index == 0) {
            removeAtHead();
            return;
        }
        if (index == length - 1) {
            removeAtTail();
            return;
        }
        node<T>* current = first->next;
        node<T>* previous = first;

        for (int i = 1; i < index; i++)
        {
            previous= current;
            current = current->next;
        }
        previous->next = current->next;
        current->next->pre = previous;
        delete current;
        length--;

    }

    void swap(int one, int two) {
        if (one == two) {
            return;
        }
        if (one < 0 || one >= length || two < 0 || two >= length) {
            cout << "OUT OF RANGE" <<endl;
        }
        if (one > two) {
            swap(two, one);
            return;
        }
        node<T> *firstNode = nullptr;
        node<T> *secondNode = nullptr;
        if (one == 0) {
            firstNode = first;
        } else {
            firstNode = first;
            for (int i = 0; i < one; ++i) {
                firstNode = firstNode->next;
            }
        }
        if (two == 0) {
            secondNode = first;
        } else {
            secondNode = first;
            for (int i = 0; i < two; ++i) {
                secondNode = secondNode->next;
            }
        }
        T current = firstNode->item;
        firstNode->item= secondNode->item;
        secondNode->item= current;
    }

    bool isExist(T element) {
        node<T>* temp =first;
        if(isEmpty()){
            cout<<"NO ITEMS"<<endl;
            return false;
        }
        while (temp != nullptr) {
            if (temp->item == element) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
    T retrieveAt(int index)  {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        if (index< 0||index >=length) {
            throw out_of_range("out of range");
        }

        node<T>* current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->item;
    }
    bool isItemAtEqual(T element, int index) {
        if (isEmpty()) {
            throw out_of_range("List is empty");
            return false;
        }

        if (index< 0||index >=length) {
            throw out_of_range("out of range");
            return false;
        }
        return retrieveAt(index) == element;
    }
        void replaceAt(T newElement,int index) {
        if (isEmpty()) {
            throw out_of_range("List is empty");
        }

        if (index <0|| index >= length) {
            throw out_of_range("Index out of range");
        }

        node<T>* current = first;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        current->item = newElement;
    }

    int linkedListSize() {
        return length;
    }

    void clear() {
        while (first!= nullptr) {
            removeAtHead();
        }
    }

    void print() {
        node<T> *current = first;

        while (current != nullptr) {
            cout << current->item << " ";
            current = current->next;
        }
        cout <<endl;
    }
};

int main() {
    doublyLinkedList<int> list;

    cout << "Is list empty? " << (list.isEmpty()?"Yes" : "No") <<endl;
    list.insertAtHead(3);
    list.insertAtHead(2);
    list.insertAtHead(1);

    cout << "after inserting at head: ";
    list.print();

    list.insertAtTail(4);
    list.insertAtTail(5);

    cout << "after inserting at tail: ";
    list.print();



    list.insertAt(25, 2);
    cout << "after inserting at index 2: ";
    list.print();


    list.removeAtHead();
    cout << "after removing at head: ";
    list.print();
    cout << "List size: " << list.linkedListSize() <<endl;
    list.removeAtTail();
    cout << "after removing at tail: ";
    list.print();

    list.removeAt(2);
    cout << "after removing index 2: ";
    list.print();

    list.swap(0, 2);

    cout << "after swapping elements at 0 and 2: ";
    list.print();


    if (list.isExist(2)) {
        cout << " 2 exists in the list." <<endl;
    } else {
        cout << "2 does not exist in the list." <<endl;
    }

    int retrievedItem = list.retrieveAt(1);
    cout << "Item at index 1: " << retrievedItem <<endl;


    if (list.isItemAtEqual(10, 1)) {
        cout << "Element at index 1 is equal to 10." <<endl;
        }
    else {
        cout << "Element at index 1 is not equal to 10." <<endl;
        }

    list.replaceAt(100, 2);
    cout << "after replacing index 2 with '100'"<<endl;
    list.print();
    cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") <<endl;

    list.clear();
    cout<<"after clearing"<<endl;
    cout << "Is list empty? " << (list.isEmpty() ? "Yes" : "No") <<endl;

}
