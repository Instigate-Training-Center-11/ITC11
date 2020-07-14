#ifndef NODE_HPP

class Node {
    public:
    Node* next;
    int value;

    /**
     * @brief Default constructor
     * @param value - value for current node(by default value = 0)
     * @param node - pointer for current node(by default value = nullptr)
     */
    Node(int value = 0, Node* node = nullptr) : value(value), next(node) {

    }
};

#endif