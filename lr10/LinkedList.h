#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template<class T>
class LinkedList {
public:
    struct Node {
        T d;
        Node* next;
        Node(const T& data) : d(data), next(nullptr) {}
    };

private:
    Node* pbeg;
    Node* pend;

public:
    LinkedList() : pbeg(nullptr), pend(nullptr) {}

    LinkedList(const T& data) {
        pbeg = new Node(data);
        pend = pbeg;
    }

    ~LinkedList() {
        while (pbeg) {
            Node* temp = pbeg;
            pbeg = pbeg->next;
            delete temp;
        }
    }

    void add(const T& data) {
        Node* newNode = new Node(data);
        if (pbeg == nullptr) {
            pbeg = newNode;
        } else {
            pend->next = newNode;
        }
        pend = newNode;
    }

    Node* find(const T& data) {
        Node* current = pbeg;
        while (current) {
            if (current->d == data) break;
            current = current->next;
        }
        return current;
    }

    Node* insert(int pos, T data) {
        Node* pv = new Node(data);
        pv->d = data;
        pv->next = nullptr;
        if (!pos || !pbeg) {
            pv->next = pbeg;
            pbeg = pv;
        }
        else {
            Node* prev = pbeg;
            for (int i = 0; i < pos - 1 && prev->next; i++) {
                prev = prev->next;
            }
            pv->next = prev->next;
            prev->next = pv;
        }
        return pv;
    }

    int remove(const T& data) {
        Node* prev = nullptr;
        Node* target = pbeg;
        
        while (target) {
            if (target->d == data) break;
            prev = target;
            target = target->next;
        }

        if (target) {
            if (target == pbeg) {
                pbeg = target->next;
            } else {
                prev->next = target->next;
            }
            
            if (target == pend) {
                pend = prev;
            }
            
            delete target;
            return 1;
        }
        return 0;
    }

    void print() const {
        Node* current = pbeg;
        while (current) {
            std::cout << current->d << " ";
            current = current->next;
        }
        std::cout << '\n';
    }
};

#endif