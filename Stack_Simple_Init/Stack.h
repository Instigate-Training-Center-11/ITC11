#include<iostream>

#include<string>

class Stack {
  private:
    int top;
  int arr[5];

  public:
    Stack() {
      top = -1;
      for (int i = 0; i < 5; i++) {
        arr[i] = 0;
      }
    }
  // public:
  //     Stack(int top, (&arr)[5]) {
  //       this->arr = arr;
  //       this->top = top;
  //     } 
  bool isEmpty() {
    if (top == -1)
      return true;
    else
      return false;
  }
  bool isFull() {
    if (top == 4)
      return true;
    else
      return false;
  }
  void push(int val) {
    if (isFull()) {
      std::cout << "stack overflow" << std::endl;
    } else {
      top++;
      arr[top] = val;
    }
  }
  int pop() {
    if (isEmpty()) {
      std::cout << "item not found" << std::endl;
      return 0;
    } else {
      int popVal = arr[top];
      arr[top] = 0;
      top--;
      return popVal;
    }
  }
  int size() {
    return (top + 1);
  }
  int peek(int pos) {
    if (isEmpty()) {
      std::cout << "item not found" << std::endl;
      return 0;
    } else {
      return arr[pos];
    }
  }
  void display() {
    std::cout << "All values in the Stack are " << std::endl;
    for (int i = 4; i >= 0; i--) {
      std::cout << arr[i] << std::endl;
    }
  }
};