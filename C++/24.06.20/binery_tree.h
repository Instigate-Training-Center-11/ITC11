#ifndef _BINERY_TREE_H_
#define _BINERY_TREE_H_

class Tree {
    class Node {
    public:
        Node* left;
        Node* right;
        int value;
        int index;

        /* Constructor with default arguments for class Node */
        Node
        (int value = 0,
        int index = 0,
        Node* left_node = nullptr,
        Node* right_node = nullptr)
        : value(value),
        left(left_node), right(right_node) {
        }
    };
    Node* head;
    int size;
    public:

    Tree() {
        this-> size = 0;
        this->head = new Node();
    }

    void insert(int value) {
        if (size == 0) {
            head->value = value;
            ++size;
            return;
        }

        bool exit = true;
        Node* tmp = head;
        while (exit) {
            if (value < tmp->value) {
                if (tmp->left == nullptr) {
                    tmp->left = new Node(value);
                    tmp->left->index = size;
                    ++size;
                    exit = false;
                }
                tmp = tmp->left;
            } else {
                if (tmp->right == nullptr) {
                    tmp->right = new Node(value);
                    tmp->right->index = size;
                    ++size;
                    exit = false;
                }
                tmp = tmp->right;
            }
        }
    }

    int search_by_value(int value) {
        Node* tmp = head;
        if (value == tmp->value) {
            return tmp->index;
        }
        while (value != tmp->value) {
            if (value < tmp->value && tmp->left != nullptr) {
                tmp = tmp->left;
            } else if (value > tmp->value && tmp->right != nullptr) {
                tmp = tmp->right;
            } else {
                std::cout << "Value not exist!" << std::endl;
                return 0;
            }
        }

        return tmp->index;
    }

    int get_size() {
        return this->size;
    }

    int head_value() {
        return head->value;
    }

    int left() {
        Node* tmp = head->left;
        return tmp->value;
    }

    int left_index() {
        Node* tmp = head->left;
        return tmp->index;
    }

    int right() {
        Node* tmp = head->right;
        return tmp->value;
    }

    int right_index() {
        Node* tmp = head->right;
        return tmp->index;
    }
};

#endif