#include "queue.h"

    void Queue::enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            firstNode = newNode;
        } else {
            lastNode->nextNode = newNode;
        }
        lastNode = newNode;
    }

    int Queue::dequeue() {
        assert(!isEmpty() && "Queue is empty");
        
        int value = firstNode->data;
        Node* temp = firstNode;
        firstNode = firstNode->nextNode;
        delete temp;

        if (firstNode == nullptr) {
            lastNode = nullptr;
        }

        return value;
    }

    Queue::~Queue() {
        clear();
    }

    void Queue::clear() {
        Node* current = firstNode;
        Node* next = nullptr;

        while (current != nullptr) {
            next = current->nextNode;
            delete current;
            current = next;
        }

        firstNode = nullptr;
        lastNode = nullptr;
    }
