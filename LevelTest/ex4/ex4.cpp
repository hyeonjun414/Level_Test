// ex4.cpp : 배열을 이용한 스택 구현

#include <iostream>

using namespace std;

class Stack
{
    int* arr;
    int size;
    int index;
public:
    Stack(int _size)
    {
        arr = new int[_size];
        size = _size;
        index = 0;
    }
    ~Stack()
    {
        delete[] arr;
    }
    void push(int i)
    {
        if (isFull()) return;
        arr[index] = i;
        index++;
    }
    void pop()
    {
        if (isEmpty()) return;

        index--;

    }
    void printAll()
    {
        for (size_t i = 0; i < index; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool isFull()
    {
        return index == size;
    }
    bool isEmpty()
    {
        return index == 0;
    }
};

int main()
{
    Stack* stack = new Stack(5);

    stack->push(1);
    stack->push(2);
    stack->push(3);
    stack->push(4);
    stack->push(5);
    stack->printAll();
    stack->pop();
    stack->pop();

    stack->printAll();

    delete stack;
}

