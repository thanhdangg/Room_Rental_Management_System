#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <functional>
#include <vector>
#include "../models/Room.h"
#include "../models/Tenant.h"
#include "../models/Invoice.h"

using namespace std;
template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();
    void add(const T &item);
    bool remove(const T &item);
    T* find(function<bool(const T&)> predicate);
    T& back();

    typename vector<T>::iterator begin();
    typename vector<T>::iterator end();
    typename vector<T>::const_iterator begin() const;
    typename vector<T>::const_iterator end() const;

    int size() const;
    void showList();

private:
    struct Node {
        T data;
        Node* next;
    };
    Node* head;
    vector<T> data;
    int listSize;
};

template <typename T>
LinkedList<T>::~LinkedList() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
}

template <typename T>
void LinkedList<T>::add(const T &item) {
    Node* newNode = new Node{item, nullptr};
    if (!head) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    data.push_back(item);
    listSize++; 
}

template <typename T>
bool LinkedList<T>::remove(const T &item) {
    if (!head) return false;

    if (head->data == item) {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
        listSize--;
        return true;
    }

    Node* current = head;
    while (current->next && current->next->data != item) {
        current = current->next;
    }

    if (current->next) {
        Node* toDelete = current->next;
        current->next = current->next->next;
        delete toDelete;
        return true;
    }

    return false;
}


template <typename T>
T* LinkedList<T>::find(function<bool(const T&)> predicate) {
    Node* current = head;
    while (current) {
        if (predicate(current->data)) {
            return &current->data;
        }
        current = current->next;
    }
    return nullptr;
}

template <typename T>
inline T &LinkedList<T>::back()
{
        if (!head) {
        throw runtime_error("List is empty, no last element available.");
    }

    Node* current = head;
    while (current->next) {
        current = current->next;
    }

    return current->data;
}

template <typename T>
typename vector<T>::iterator LinkedList<T>::begin() {
    return data.begin();
}

template <typename T>
typename vector<T>::iterator LinkedList<T>::end() {
    return data.end();
}

template <typename T>
typename vector<T>::const_iterator LinkedList<T>::begin() const {
    return data.begin();
}

template <typename T>
typename vector<T>::const_iterator LinkedList<T>::end() const {
    return data.end();
}

template <typename T>
int LinkedList<T>::size() const {
    return listSize;
}

template <typename T>
inline void LinkedList<T>::showList()
{
    Node* current = head;
    while (current) {
        cout << current->data << endl;
        current = current->next;
    }
}

class RoomLinkedList : public LinkedList<Room> {
public:
    Room* findRoomNumber(int roomNumber) {
        return find([roomNumber](const Room& room) {
            return room.getRoomNumber() == roomNumber;
        });
    }
};

class TenantLinkedList : public LinkedList<Tenant> {
public:
    Tenant* findTenantById(const int& tenantID) {
        return find([tenantID](const Tenant& tenant) {
            return tenant.getId() == tenantID;
        });
    }
};

#endif // LINKEDLIST_H