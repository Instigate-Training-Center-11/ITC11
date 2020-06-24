#include <iostream>
#include "stack.cpp"

int main() {
    Stack<int, std::vector<int>> st(4, 777);
    Stack<char, std::list<char>> st1;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st1.push('A');
    int size = st1.size();
    for (int i = 0; i < size; ++i) {
        std::cout << st1.top() << std::endl;
        st1.pop();
    }

    st1.push('@');

    if (st1.empty()) {
        std::cout << "Stack is empty!" << std::endl;
    } else {
        std::cout << "Stack is not empty!" << std::endl;
    }

    return 0;
}