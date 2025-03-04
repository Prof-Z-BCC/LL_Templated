//
// Created by Rich Zwolinski
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"
#include <iostream>


template <typename T>
class LinkedList {
private:
    Node<T>* head;

public:
    LinkedList() : head(nullptr) {}

    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node<T>* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void insertAtBeginning(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->next = head;
        head = newNode;
    }

    void deleteValue(T val) {
        if (!head) return;

        if (head->data == val) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node<T>* temp = head;
        while (temp->next && temp->next->data != val) {
            temp = temp->next;
        }

        if (temp->next) {
            Node<T>* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
    }

    bool search(T val) {
        Node<T>* temp = head;
        while (temp) {
            if (temp->data == val) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node<T>* temp = head;
        while (temp) {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        }
        std::cout << "NULL" << std::endl;
    }

    ~LinkedList() {
        Node<T>* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};



#endif //LINKEDLIST_H
