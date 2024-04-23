#include <iostream>
using namespace std;
const int MAX=100;
template<class T>
class CircularQueueArrayType{
    int front;
    int rear;
    int length;
    int array[MAX];
public:
    CircularQueueArrayType(){
        front=0;
        rear=MAX-1;
        length=0;
    }
    bool isEmpty(){
        return length==0;
    }
    bool isFull(){
        return length==MAX;
    }
    void enqueue(T element){
        if (isFull()){
            throw out_of_range("Array is Already full");
        }
        else{
            rear=(rear+1)%MAX;
            array[rear]=element;
            length++;
        }
    }
    void dequeue(){
        if (isEmpty()){
            throw out_of_range("Array is Already EMPTY");
        }
        else{
            front=(front+1)%MAX;
            length--;
        }
    }
    T first(){
        if(isEmpty()){
            throw out_of_range("Array is Already EMPTY");
        }
        else{
            return array[front];
        }
    }

    void print(){
        cout<< "{   ";
        for(size_t i=front;i!=(rear+1)%MAX;i++){
            cout<<array[i]<<"   ";
        }
        cout<<" }";
    }
    void clear() {
      rear=MAX-1;front=0;
        length=0;
    }
};
 int main() {
     CircularQueueArrayType<int> queue;
     queue.enqueue(1);
     queue.enqueue(2);
     queue.enqueue(3);
     queue.enqueue(4);
     cout << "Queue after inserting: ";
     queue.print();
     cout<<endl;
     queue.dequeue();
     cout << "Queue after deleting one item: ";
     queue.print();
     cout<<endl;
     cout << "first is: "<<queue.first()<<endl;
     cout << "Queue before clear: ";
     queue.print();
     cout<<endl;
     queue.clear();
     cout << "Queue after clear: ";
     queue.print();
 }