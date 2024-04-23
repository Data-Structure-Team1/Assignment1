#include <iostream>
using namespace std;
template<class T>
struct Node {
    T data;
    Node<T>* next;

};

template<class T>
class SinglLinkedList {
private:
    Node<T>* first, * last;
    int count;
public:
    SinglLinkedList() {
        first = NULL;
        last = NULL;
        count = 0;
  
    }
    bool isEmpty() {
        return count == 0;
    }
    void insertAtHead(T element) {
        Node <T>* newnode = new Node<T>;
        newnode->data = element;
        if (isEmpty()) {
            first=last = newnode;
            newnode->next = NULL;

        }
        else {
            newnode->next = first;
            first = newnode;
           
        }
        count++;

    }
    void insertAtTail(T element) {
        Node <T>* newnode = new Node<T>;
        newnode->data = element;
        if (isEmpty()) {
            insertAtHead(element);
         }
        else {
            last->next = newnode;
            newnode->next = NULL;
            last = newnode;
            count++;
        }
       
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
            cout << " ERROR: The list is Epmty you can not remove element\n";
            return;
        }
        else if (count == 1) {
            delete first;
            first = last = NULL;
        }
        else {
            Node<T>* temp = first;
            first= temp->next;
            delete(temp);
          
        }
        count--;

    }
    void removeAtTail() {
        if (isEmpty()) {
            cout << " ERROR: The list is Epmty you can not remove element\n";
            return;
        }
        else if (count == 1) {
            delete first;
            first = last = NULL;
        }
        else {

            Node<T>* curr = first->next;
            Node<T>* prev = first;

            while (curr!=last)
            {
                prev = curr;
                curr = curr->next;


            }
            delete curr;
            prev->next = NULL;
            last = prev;


        }
        count--;
     }

    void removeAt(int index) {
        if (index < 0 || index >= count) {
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
            delete curr;
            count--;

        }

    }
    T retrieveAt(int index) {
        if (index < 0 || index >= count) {
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

        if (index < 0 || index >= count) {
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
        while (curr != NULL) {
            if (curr->data == element) {
                return true; 
            }
            curr = curr->next;
        }
        return false;
    }
    bool isItemAtEqual(T element, int index) {
        if (index >= count || index < 0) {
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
            Node<T>* cur = first;
            for (int i = 0; i < index; i++)
            {
                cur = cur->next;
            }
            if (cur->data == element)
                return true;


        }
        return false;

   }
    int linkedListSize() {
        return count;
    }


    void print() {
        Node<T>* curr=first;
        while (curr!=NULL)
        {
            
            cout << curr->data<<" ";
            curr = curr->next;

        }
        cout << endl;
    }
    void clear() {
        Node<T>* curr =first;
        while (first != NULL) {
            curr = first;  
            first = first->next;  
            delete curr;  
        }
        last = NULL;
        count = 0;
    }




};
int main()
{
    SinglLinkedList<int> *ssl=new SinglLinkedList<int>();
    ssl->insertAtHead(4);
  
  //  ssl->insertAtTail(50);
  //  ssl->insertAtTail(30);
  //  ssl->insertAtHead(2);
  //  ssl->insertAt(9, 4);
  //  ssl->print();
  //
  ///*  ssl->removeAtHead();
  //  ssl->removeAtTail();*/
  // ssl->replaceAt(780, 2);
  // cout<< ssl->retrieveAt(2)<<endl;
 
  // cout << ssl->isItemAtEqual(9,5) << endl;
  //
  //  ssl->print();
  //  cout << ssl->linkedListSize();




    ssl->insertAtHead(5);
    ssl->insertAtHead(4);
    ssl->insertAt(2, 0);
    ssl->insertAt(88, 4);
    ssl->insertAt(-1, 2);
    ssl->removeAt(2);
    ssl->print();
}


