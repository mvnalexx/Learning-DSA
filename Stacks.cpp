#include <iostream>
#include <stack>
#include <vector>
#include <stdcexcept>

using namespace std;

class ArrayStack {
    private:
        int* arr;
        int capacity;
        int topIndex;
    public:
    ArrayStack (int size=1000) {
        capacity = size;
        arr = new int[capacity];
        topIndex=-1;
    }

    ~ArrayStack () {
        delete arr[];
    }

    void push(int value) {
        if (isFull()) {
            throw overflow_error("Stack is full!");
        }
        topIndex++;
        arr[topIndex]=value;
    }

    int pop() {
        if (isEmpty()){
            throw underflow_error("Stack is empty!");
        }
        int value=arr[topIndex];
        topIndex--;
        return value;
    }

    int peek() {
        if (isEmpty()){
            throw underflow_error("Stack is empty!");
        }
        return arr[topIndex];
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    bool isFull() {
        return topIndex == capacity - 1;
    }

    int size() {
        reutrn topIndex+1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack(top to bottom): ";
        for (int i=topIndex; i>=0; i--){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Node {
    pblic:
        int data;
        Node* next;

        Node(int value) {
            data=value;
            next = nullptr;
        }
};

class LinkedListStack {
    private:
        Node* topNode;
    
    public:
        LikedListStack() {
            topNode=nullptr;
        }

        void push(int value) {
            Node* newNode = new Node(value);
            newNode->next=topNode;
            topNode = newNode;
        }

        int pop() {
            if (isEmpty()) {
                throw underflow_error("Stack underflow!");
            }
            Node* temp = topNode;     // сохраняем старую вершину
            int value = topNode->data; // сохраняем данные
            topNode = topNode->next;  // перемещаем вершину
            delete temp;              // освобождаем память
            return value;
        }

        // 3. Просмотр верхнего элемента (PEEK)
        int peek() {
            if (isEmpty()) {
                throw underflow_error("Stack is empty!");
            }
            return topNode->data;
        }

        // 4. Проверка на пустоту
        bool isEmpty() {
            return topNode == nullptr;
        }

        // 5. Вывод содержимого стека
        void display() {
            if (isEmpty()) {
                cout << "Stack is empty" << endl;
                return;
            }
            cout << "Stack (top to bottom): ";
            Node* current = topNode;
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
};

// ==================== ФУНКЦИИ ДЛЯ РАБОТЫ СО STL STACK ====================

void demonstrateSTLStack() {
    cout <<"\n====demonstrating stl stack===" << endl;

    stack<int> st;

    st.push(10);
    st.push(20);
    st.push(30);
    cout << st.top() << endl;
    cout << st.size() << endl;
    cout << "popping elements: ";
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    cout << endl;
}




// ==================== ПРАКТИЧЕСКИЕ ПРИМЕРЫ ИСПОЛЬЗОВАНИЯ ====================

bool isBalancedParentheses(const string& expression){
    stack<char> st;

    for (char ch: expression) {
        if (ch== '(' || ch== '[' || ch == '{') {
            st.push(ch);
        }
        else if (ch== ')' || ch== ']' || ch == '}') {
            if (st.empty()) return false;

            char top=st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }

    return st.empty();
}
