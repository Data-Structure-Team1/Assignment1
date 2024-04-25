#include <iostream>
using namespace std;
template<class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

};

template<class T>
class CircularDoublyLinkedList {
private:
    Node<T>* first, * last;
    int count;
public:
    CircularDoublyLinkedList() {
        first = NULL;
        last = NULL;
        count = 0;
  
    }
    bool isEmpty() {
        return count == 0;
    }
    void insertAtHead(T element) {
        Node<T>* newnode = new Node<T>;
        newnode->data = element;
        if (isEmpty()) {
            first = last = newnode;
            newnode->next = newnode->prev = newnode;
        }
        else {
            newnode->next = first;
            newnode->prev = last;
            first->prev = newnode;
            last->next = newnode;
            first = newnode;
        }
        count++;
    }

    void insertAtTail(T element) {
        Node<T>* newnode = new Node<T>;
        newnode->data = element;
        if (isEmpty()) {
            insertAtHead(element);
        }
        else {
            newnode->next = first;
            newnode->prev = last;
            last->next = newnode;
            first->prev = newnode;
            last = newnode;
        }
        count++;
    }

    void insertAt(T element, int index) {
        if (index<0 || index >count) {
            cout << "ERROR Index out of range\n";
            return;
        }
        else if (index == 0) {
            insertAtHead(element);
        }
        else if (index == count) {
            insertAtTail(element);
        }
        else {
            Node<T>* newnode = new Node<T>;
            newnode->data = element;
            Node<T>* curr = first;
            for (int i = 1; i <index ; i++)
            {
                curr = curr->next;
            }
            newnode->next = curr->next;
            curr->next = newnode;
            count++;
        }


    }
    void removeAtHead() {
        if (isEmpty()) {
            cout << " ERROR: The list is Empty you can not remove element\n";
            return;
        }
        else if (count == 1) {
            delete first;
            first = last = NULL;
        }
        else {
            Node<T>* temp = first;
            first= temp->next;
            first->prev = last;
            last->next = first;
            delete(temp);

          
        }
        count--;

    }
    void removeAtTail() {
        if (isEmpty()) {
            cout << " ERROR: The list is Empty you can not remove element\n";
            return;
        }
        else if (count == 1) {
            delete first;
            first = last = NULL;
        }
        else {
            Node<T>* curr = first;
            while (curr->next != last)
            { 
                curr = curr->next;
            }
            delete last;
            last = curr;
            first->prev = last;
            last->next = first;

        }
        count--;
     }

    void removeAt(int index) {
        if (isEmpty() || index < 0 || index >= count) {
            cout << "ERROR Index out of range\n";
            return;
        }
        else if(index==0)
        {
            removeAtHead();
        }
        else if (index == count - 1) {
            removeAtTail();
        }
        else {
            Node<T>* curr = first->next;
            Node<T>* prev = first;

            for (int i = 1; i < index; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = curr->next;
            curr->next->prev = prev;
            delete curr;
            count--;

        }

    }
    T retrieveAt(int index) {
        if (isEmpty() || index < 0 || index >= count) {
            cout << "ERROR Index out of range\n";
            return 0;
        }

        if (index == 0)
            return first->data;
        else if (index == count - 1)
            return last->data;
        else {
            Node <T>* curr = first;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }
            return curr->data;
        }


   }
    void replaceAt(T newElement, int index) {

        if (isEmpty() || index < 0 || index >= count) {
            cout << "ERROR Index out of range\n";
            return;
        }
       else if (index == 0)
            first->data=newElement;
        else if (index == count - 1)
            last->data=newElement;
        else {
            Node <T>* curr = first;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }
           curr->data=newElement;
        }


    }
    bool isExist(T element)  {
        Node<T>* curr = first;
        do {
            if (curr->data == element) {
                return true;
            }
            curr = curr->next;
        } while (curr != first);
        return false;
    }
    bool isItemAtEqual(T element, int index) {
        if (isEmpty() || index >= count || index < 0) {
            cout << "Error : out of range\n";
            return 0;
        }

       else if (index == 0&&first->data==element) {
            return true;
         }
        else if (index == count - 1 && last->data == element) {
            return true;

        }
        else {
            Node<T>* curr = first;
            for (int i = 0; i < index; i++)
            {
                curr = curr->next;
            }
            if (curr->data == element)
                return true;


        }
        return false;

   }
    int linkedListSize() {
        return count;
    }
    
    void swap(int a, int b) {
        if ( a== b) {
            return;
        }
        if (a < 0 || a >= count || b < 0 || b >= count) {
            cout << "OUT OF RANGE" <<endl;
        }
        if (a > b) {
            swap(b, a);
            return;
        }
        Node<T> *firstNode = NULL;
        Node<T> *secondNode = NULL;
        if (a == 0) {
            firstNode = first;
        } else {
            firstNode = first;
            for (int i = 0; i < a; ++i) {
                firstNode = firstNode->next;
            }
        }
        if (b == 0) {
            secondNode = first;
        } else {
            secondNode = first;
            for (int i = 0; i < b; ++i) {
                secondNode = secondNode->next;
            }
        }
        T current = firstNode->data;
        firstNode->data= secondNode->data;
        secondNode->data= current;
    }


    void print() {
        if (isEmpty()) {
            cout << "List is empty\n";
            return;
        }
        Node<T>* curr = first;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != first);
        cout << endl;
    }

    void clear() {while (!isEmpty()) {
            removeAtTail();
        }
    }


};
int main() {
    CircularDoublyLinkedList<int> ssl;
    ssl.insertAtHead(7);
    ssl.insertAtHead(9);
    ssl.insertAtHead(7);
    ssl.insertAt(2, 0);
    ssl.removeAt(2);
    ssl.swap(0, 1);
    ssl.print();
    return 0;
}
