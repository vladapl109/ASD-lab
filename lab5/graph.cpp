#include "graph.h"


    void Graph::addNode(int value) {
        Node* newNode = new Node(value);
        nodes[value] = newNode;
    }

    void Graph::addEdge(int fromValue, int toValue) {
        if (nodes.find(fromValue) == nodes.end() || nodes.find(toValue) == nodes.end()) {
            std::cout << "Node not found!" << std::endl;
            return;
        }

        Node* fromNode = nodes[fromValue];
        Node* toNode = nodes[toValue];

        fromNode->neighbors.push_back(toNode);
    }

    int Graph::sumOfNeighbors(int nodeValue) {
        if (nodes.find(nodeValue) == nodes.end()) {
            std::cout << "Node not found!" << std::endl;
            return 0;
        }

        int sum = 0;
        Node* currentNode = nodes[nodeValue];

        for (Node* neighbor : currentNode->neighbors) {
            sum += neighbor->value;
        }

        return sum;
    }

    Graph::~Graph() {
        for (auto& pair : nodes) {
            delete pair.second;
        }
    }
