class List{
    unsigned int size = 0;
    struct Node{
        Node* next;
        int value;
    };
    Node* head;
    Node* tail;
    public:
    /* default constructor */
    List(void);
    int getSize(void) const;
    /* Push the new item at the end of the list */
    void pushBack(int value);
    /* Remove element by index */
    void removeAtIndex(unsigned int);
    /* Insert element by index */
    void insertAtIndex(unsigned int,int);
    /* Set element by index */
    void setAtIndex(unsigned int,int);
    /* Get element by index */
    int operator[](unsigned int) const;
    /* Print the whole list */
    void printList(void);
    /* Remove the last item from the list */
    void popBack(void);
    /* Remove all elements from the list */
    void clear(void);
    /* Parameterized constructor */
    List(int);
    /* Destructor  */
    ~List(void);

};