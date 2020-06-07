class List{
    unsigned int size = 0;
    struct Node{
        Node* next;
        int value;
    };
    Node* head;
    public:
    /* default constructor */
    List(void);
    /* Parameterized constructor */
    List(int);
    int getSize(void) const;
    /* Push the new item at the end of the list */
    void pushBack(int);
    /* Remove element by index */
    void removeAtIndex(unsigned int);
    /* Insert element by index */
    void insertAtIndex(unsigned int,int);
    /* Set element by index */
    void setAtIndex(unsigned int,int);
    /* Get element by index */
    int operator[](unsigned int) const;
    /* Print the whole list */
    void printList(void) const;
    /* Remove the last item from the list */
    void popFront(void);
    /* Added the last item from the list */
    void pushFront(int);
    /* Remove all elements from the list */
    void clear(void);
    /* Destructor  */
    ~List(void);

};