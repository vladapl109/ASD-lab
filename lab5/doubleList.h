#include <iostream>
#include <cassert>

struct Node {
    int data;
    Node* prevNode;
    Node* nextNode;

    Node(int value) : data(value), prevNode(nullptr), nextNode(nullptr) {}
};

class DoubleLinkedList {
    Node* firstNode;
    Node* lastNode;

    DoubleLinkedList() : firstNode(nullptr), lastNode(nullptr) {}

    Node* insertAfter(Node* node, int value);
    Node* insertBefore(Node* node, int value);
    Node* find(int value);
    void remove(Node* node);
    void assertNoCycles();

    ~DoubleLinkedList();

private:
    void deleteList();
};
