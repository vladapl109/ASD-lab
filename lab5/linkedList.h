struct Node {
    int data;
    Node* nextNode;

    Node(int value) : data(value), nextNode(nullptr) {}
};

struct FindNodeResult {
    Node* previousNode;
    Node* foundNode;

    FindNodeResult(Node* prev, Node* found) : previousNode(prev), foundNode(found) {}
};

class LinkedList {
    private:
        Node* head;
        int nodeCount;

    public:
        LinkedList() : head(nullptr) {}

        Node* insertAfter(Node* node, int value);
        FindNodeResult find(int value);
        void removeAfter(Node* node);
        void assertNoCycles();
        void displayList();

};
