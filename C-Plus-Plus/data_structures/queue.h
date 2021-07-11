/* This class specifies the basic operation on a queue as a linked list */
#ifndef DATA_STRUCTURES_QUEUE_H_
#define DATA_STRUCTURES_QUEUE_H_

#include <cassert>
#include <iostream>

template <class Kind>
struct node
{
    Kind data;
    node<Kind> *next;
};

template <class Kind>
class queue
{
public:
    void display()
    {
        node<Kind> *current = queueFront;
        std::cout << "Front --> ";
        while (current != NULL)
        {
            std::cout << current->data << "    ";
            current = current->next;
        }
        std::cout << std::endl;
        std::cout << "Size of queue: " << size << std::endl;
    }

    queue()
    {
        queueFront = NULL;
        queueRear = NULL;
        size = 0;
    }

    ~queue() {}

    bool isEmptyQueue() { return (queueFront == NULL); }

    void enQueue(Kind item)
    {
        node<Kind> *newNode;
        newNode = new node<Kind>;
        newNode->data = item;
        newNode->next = NULL;
        if (queueFront == NULL)
        {
            queueFront = newNode;
            queueRear = newNode;
        }
        else
        {
            queueRear->next = newNode;
            queueRear = queueRear->next;
        }
        size++;
    }

    Kind front()
    {
        assert(queueFront != NULL);
        return queueFront->data;
    }

    void deQueue()
    {
        node<Kind> *temp;
        if (!isEmptyQueue())
        {
            temp = queueFront;
            queueFront = queueFront->next;
            delete temp;
            size--;
        }
        else
        {
            std::cout << "Queue is empty !" << std::endl;
        }
    }

    void clear() { queueFront = NULL; }

private:
    node<Kind> *queueFront;
    node<Kind> *queueRear;
    int size;
};

#endif
