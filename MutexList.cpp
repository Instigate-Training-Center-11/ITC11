#include <bits/stdc++.h>
#include <thread>
#include <mutex>
using namespace std;

/* declare the mutex */
mutex mtx;

/* structure of a linked list node */
class Node {
public:
    int data;
    Node* next;
};
void delete(Node* head, Node* n) {
    /* mutex for methode delete */
    mtx.lock();
    if (head == n) {
        if (head->next == NULL) {
            cout << "There is only one node."
                 << " The list can't be made empty ";
            return;
        }
        head->data = head->next->data;
        n = head->next;
        head->next = head->next->next;
        free(n);
        /* unlock mutex for methode delete */
        mtx.unlock();
        return;
    }
    Node* prev = head;
    while (prev->next != NULL && prev->next != n) {
        prev = prev->next;
    }
    if (prev->next == NULL) {
        cout << "\nGiven node is not exist in Linked List";
        return;
    }
    prev->next = prev->next->next;
    free(n);
    return;
}
void add(Node** head_ref, int new_data) {
    /* mutex for methode add */
    mtx.lock();
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
    /* unlock mutex for methode add */
    mtx.unlock();
}
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    /* Add the values */
    thread t1(add, &head, 9);
    thread t2(add, &head, 10);

    /* joins */
    t1.join();
    t2.join();

    cout << "Given Linked List: ";
    printList(head);
    printList(head);

    /* Delete the second node */
    cout << "\nDeleting first node ";
    thread t1(delete, head, head->next);
    thread t2(delete, head, head->next);

    t1.join();
    t2.join();

    printList(head);
    return 0;
}
