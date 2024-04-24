#include <iostream>
using namespace std;
const int Max_size = 4;
template <class T>
class StackArrayBased {
private:
    int top;
    T arr[Max_size];
public:
    StackArrayBased () {
        top = -1;
    }
    bool isEmpty() {
        return top == -1;
   }
    bool IsFull() {
        return top >= Max_size - 1;
    }
    void push(T element) {
        if (IsFull()) {
            cout << "Error: Stack if full\n ";
            return;
         }

        else {
            arr[++top] = element;
        }
    }
    T pop() {
        if (isEmpty()) {
            cout << "Error: stack is empty you can not remove element\n";
            return T();
        }

        else {
            T temp = arr[top];
            top--;
           return temp;
        }
       
    }

    T Top() {
        if (isEmpty()) {
            cout << "Error: stack is empty you can not get  element on top\n";
            return T();
        }
        else
            return arr[top];
        
    }
    int StackSize() {
        if (isEmpty())
            return 0;
        else
            return top + 1;
    }
    void clear() {
        top = -1;
    }
    void print() {
        if (!isEmpty()) {
            for (int i = top; i >=0 ; i--)
            {
                cout << arr[i] << " ";
                

            }
            cout << endl;
        }
   }
};


int main()
{
    StackArrayBased<int>s;
 
    s.push(1);
    cout << "Top:" << s.Top() << endl;
    s.push(2);
    s.push(3);
    s.push(4);
    s.print();
    cout << "stack size" << s.StackSize();
    cout << "Top:" << s.Top() << endl;
    cout << "removed element:" << s.pop() << endl;
    s.print();
    cout << "Top:" << s.Top() << endl;



 
    cout << "stack size " << s.StackSize();

}
