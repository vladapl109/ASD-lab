#include <iostream>
#include "graph.h"

int main(){
    // LinkedList* list = new LinkedList();

    // Node* newNode = new Node(10);

    // list->insertAfter(newNode, 10);
    // list->insertAfter(newNode, 20);
    // list->insertAfter(newNode, 10);


    // list->displayList();

    Graph graph;

    for (int i = 1; i <= 4; ++i) {
        graph.addNode(i);
    }

    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    graph.addEdge(4, 1);

    int sum = graph.sumOfNeighbors(1);
    std::cout << "Sum of values of neighboring nodes for Node1: " << sum << std::endl;


}
