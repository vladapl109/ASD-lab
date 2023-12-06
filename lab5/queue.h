#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* nextNode;

    Node(int value) : data(value), nextNode(nullptr) {}
};

class Queue {
    Node* firstNode;
    Node* lastNode;

    Queue() : firstNode(nullptr), lastNode(nullptr) {}

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const {
        return (firstNode == nullptr);
    }
    ~Queue();

private:
    void clear();
};
