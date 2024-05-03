#include <iostream>
using  namespace std;
template<class T>
struct node {
    T item;
    node *next;
    node(T data) : item(data), next(nullptr){}
};

template <class T>
class SimpleQueueLinkedListType {
    node<T> *front;
    node<T> *rear;
    int length;
public:
   SimpleQueueLinkedListType() {
        front = nullptr;
        rear = nullptr;
        length = 0;
    }
    bool isEmpty() const {
        return front== nullptr;
    }

    void enqueue(T element){
        node<T>* newNode= new node<T>(element);
        newNode->next= nullptr;
        if(isEmpty()){
            rear=front=newNode;
        }
        else{
            rear->next=newNode;
            rear=newNode;
        }
        length++;
    }
    void dequeue(){
        if (isEmpty()) {
            cout<<"List is already empty"<<endl;
            return;
        }
        if(front==rear){
            rear=front= nullptr;
            length--;
        }
        else{
            node<T>*current=front;
            front=front->next;
            current->next= nullptr;
            delete current;
            length--;
        }
    }
        T first(){
            if (isEmpty()) {
                cout<<"List is already empty"<<endl;
            }
            else{
               return front->item;
            }
        }
    void clear() {
       if (isEmpty()){
           return;
       }
        while (front != nullptr) {
            node<T>* current = front;
            front = front->next;
            delete current;
        }
        rear = nullptr;
        length = 0;
    }

    int queueSize(){
        return length;
    }
    void print() {
        node<T> *current =front;

        while (current != nullptr) {
            cout << current->item << " ";
            current = current->next;
        }
        cout <<endl;
    }
};
int main() {
    SimpleQueueLinkedListType<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.print();
    cout << "Queue size: " << queue.queueSize() << endl;
    cout << "First element: " << queue.first() << endl;
    queue.dequeue();
    cout <<"Size after dequeue: " << queue.queueSize()<< endl;
    cout << "Elements after dequeue: ";
    queue.print();
    queue.clear();
    if (queue.isEmpty()) {
        cout << "Queue is empty after clear" << endl;
    }

}




