#include "linkedList.h"
#include <assert.h>
#include <iostream>

Node* LinkedList::insertAfter(Node* node, int value){
        Node* newNode = new Node(value);
        nodeCount++;
        if (this->head == nullptr) {
            this->head = newNode;
            return newNode;
        }

        Node* current = this->head;
        while (current != nullptr) {
            if (current->data == node->data) {
                newNode->nextNode = current->nextNode;
                current->nextNode = newNode;
                return newNode;
            }
            current = current->nextNode;
        }

        newNode->nextNode = this->head;
        this->head = newNode;
        return newNode;
}

FindNodeResult LinkedList::find(int value) {
        if (head == nullptr || head->data == value) {
            // If the list is empty or the first node contains the value, return nullptr as previousNode
            return FindNodeResult(nullptr, head);
        }

        Node* current = head;
        while (current->nextNode != nullptr) {
            if (current->nextNode->data == value) {
                return FindNodeResult(current, current->nextNode);
            }
            current = current->nextNode;
        }

        // If the value was not found, return nullptr as previousNode and foundNode
        return FindNodeResult(nullptr, nullptr);
    }


    void LinkedList::removeAfter(Node* node) {
        if (head == nullptr || (node == nullptr && head->nextNode == nullptr)) {
            // List is empty or there is no node after the given node (or no given node)
            return;
        }

        if (node == nullptr) {
            // If node is nullptr, remove the first node
            Node* temp = head;
            head = head->nextNode;
            delete temp;
            return;
        }

        if (node->nextNode != nullptr) {
            Node* temp = node->nextNode;
            node->nextNode = temp->nextNode;
            delete temp;
        }
    }

void LinkedList::assertNoCycles(){
     int count = 0;
        Node* slow = head;
        Node* fast = head;

        while (fast != nullptr && fast->nextNode != nullptr) {
            slow = slow->nextNode;
            fast = fast->nextNode->nextNode;
            count++;

            if (count > nodeCount) {
                assert(false && "Cycle detected in the linked list!");
            }
        }
}

    void LinkedList::displayList() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->nextNode;
        }
        std::cout << std::endl;
    }
