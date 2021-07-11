#ifndef DATA_STRUCTURES_STACK_H_
#define DATA_STRUCTURES_STACK_H_

#include <cassert>
#include <iostream>

template <class Type>
struct node
{
    Type data;
    node<Type> *next;
};

template <class Type>
class stack
{
public:
    void display()
    {
        node<Type> *current = stackTop;
        std::cout << "Top --> ";
        while (current != nullptr)
        {
            std::cout << current->data << "  ";
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << "Size of stack: " << size << std::endl;
    }

    stack()
    {
        stackTop = nullptr;
        size = 0;
    }

    explicit stack(const stack<Type> &otherStack)
    {
        node<Type> *newNode, *current, *last;

        if (stackTop != nullptr)
        {
            stackTop = nullptr;
        }
        if (otherStack.stackTop == nullptr)
        {
            stackTop = nullptr;
        }
        else
        {
            current = otherStack.stackTop;
            stackTop = new node<Type>;
            stackTop->data = current->data;
            stackTop->next = nullptr;
            last = stackTop;
            current = current->next;
            while (current != nullptr)
            {
                newNode = new node<Type>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next;
            }
        }
        size = otherStack.size;
    }

    ~stack() {}

    bool isEmptyStack() { return (stackTop == nullptr); }

    void push(Type item)
    {
        node<Type> *newNode;
        newNode = new node<Type>;
        newNode->data = item;
        newNode->next = stackTop;
        stackTop = newNode;
        size++;
    }

    Type top()
    {
        assert(stackTop != nullptr);
        return stackTop->data;
    }

    void pop()
    {
        node<Type> *temp;
        if (!isEmptyStack())
        {
            temp = stackTop;
            stackTop = stackTop->next;
            delete temp;
            size--;
        }
        else
        {
            std::cout << "Stack is empty !" << std::endl;
        }
    }

    void clear() { stackTop = nullptr; }

    stack<Type> &operator=(const stack<Type> &otherStack)
    {
        node<Type> *newNode, *current, *last;

        if (stackTop != nullptr)
        {
            stackTop = nullptr;
        }
        if (otherStack.stackTop == nullptr)
        {
            stackTop = nullptr;
        }
        else
        {
            current = otherStack.stackTop;
            stackTop = new node<Type>;
            stackTop->data = current->data;
            stackTop->next = nullptr;
            last = stackTop;
            current = current->next;
            while (current != nullptr)
            {
                newNode = new node<Type>;
                newNode->data = current->data;
                newNode->next = nullptr;
                last->next = newNode;
                last = newNode;
                current = current->next;
            }
        }
        size = otherStack.size;
        return *this;
    }

private:
    node<Type> *stackTop;
    int size;
};

#endif
