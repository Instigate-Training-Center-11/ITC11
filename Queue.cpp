#include <iostream>
using namespace std;
#define SIZE 5

int queue[SIZE];

int front = -1; /* queue is empty */
int rear = -1;

void enqueue(int x)
{
    if (rear == SIZE - 1)
    {
        cout << "queue is full" << endl;
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout << "queue is empty" << endl;
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
        front++; /* if front passed to right, queues start is rigtest element */
}

void display()
{
    if (front == -1 && rear == -1)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        for (int i = front; i < rear + 1; i++)
        {
            cout << queue[i] << '\t';
        }
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        cout << "queue is empty" << endl;
    }
    else
    {
        cout << queue[front] << endl;
    }
}

int main()
{
    enqueue(2);
    enqueue(5);
    enqueue(-1);
    display();
    peek();
    dequeue();
    peek();
    display();
    cout << endl;
}