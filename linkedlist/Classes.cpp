//
//  Classes.cpp
//  linkedlist

#include <iostream>

using namespace std;

class Node {
public:
    int value;
    Node* next;
    
    Node(int value) {
        this->value = value;
    }
};


class LinkedList {
public:
    Node* head;
    Node* tail;
    int length;
    LinkedList(int value) {
        Node* tmp = new Node(value);
        this->head = tmp;
        this->tail = tmp;
        this->length = 1;
    }
    ~LinkedList() {
        Node* tmp = this->head;
        while(head != nullptr) {
            this->head = this->head->next;
            delete tmp;
            tmp = this->head;
        }
    }
    void append(int value) {
        Node* newNode = new Node(value);
        if (this->length == 0) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        this->length += 1;
    }
    void prepend(int value) {
        Node* newNode = new Node(value);
        if (this->length == 0) {
            this->head = newNode;
            this->tail = newNode;
        } else {
            newNode->next = this->head;
            this->head = newNode;
        }
        this->length += 1;

    }
    bool insert(int index, int value) {
        if (index < 0 || index > length) {
            return false;
        } else if (index == 0) {
            prepend(value);
            return true;
        } else if (index == length) {
            append(value);
            return true;
        } else {
            Node* newNode = new Node(value);
            Node* prev = get(index - 1);
            newNode->next = prev->next;
            prev->next = newNode;
            length++;
            return true;
        }
    }
    
    void pop() {
        if (length == 0) {
            return;
        } else if (length == 1) {
            delete head;
            tail = nullptr;
            head = nullptr;
            length--;
        } else {
            Node* tmp = head;
            while (tmp->next != nullptr && tmp->next->next != nullptr) {
                tmp = tmp->next;
            }
            tail = tmp;
            delete tmp->next;
            tmp->next = nullptr;
            length--;
        }
    }
    
    void shift() {
        Node* tmp = head;
        if (tmp) {
            head = head->next;
            delete tmp;
            length--;
            if (length == 0) {
                tail = nullptr;
            }
        }
    }
    
    bool deleteAt(int index) {
        if (index < 0 || index >= length) {
            return false;
        }
        if (index == 0) {
            shift();
        } else if (index == length - 1) {
            pop();
        } else {
            Node* prev = get(index - 1);
            Node* tmp = prev->next;
            prev->next = tmp->next;
            delete tmp;
        }
        length--;
        return true;
    }
    
    void reverse() {
        Node* tmp = head;
        head = tail;
        tail = tmp;
        
        Node* next = tmp->next;
        Node* prev = nullptr;
        for (int i = 0; i < length; i++) {
            next = tmp->next;
            tmp->next = prev;
            prev = tmp;
            tmp = next;
        }
    }
    
    void print() {
        Node* tmp = this->head;
        while (tmp) {
            cout << tmp->value << endl;
            tmp = tmp->next;
        }
        stats();
    }
    
    Node* get(int index) {
        if (index < 0 || index >= length) {
            return nullptr;
        }
        Node* tmp = head;
        for (int i = 0; i < index; i++) {
            tmp = tmp->next;
        }
        return tmp;
        
    }
    
    bool set(int index, int value) {
        Node* tmp = get(index);
        if (tmp) {
            tmp->value = value;
            return true;
        }
        return false;
    }
    
    void stats() {
        cout << "--- stats ---" << endl;
        if (head == nullptr)
            cout << "head: nullptr" << endl;
        else
            cout << "head: node" << endl;
        if (tail == nullptr)
            cout << "tail: nullptr" << endl;
        else
            cout << "tail: node" << endl;
        cout << "length: " << length << endl;
        cout << "---  end  ---" << endl;
    }
};
