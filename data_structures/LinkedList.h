#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <string>
#include <cstddef>

template <typename T>
class LinkedList {
protected:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    virtual ~LinkedList() {
        clear();
    }

    virtual void add(const T& item);
    virtual bool remove(const T& item);
    virtual size_t size() const;

    virtual void clear();
    virtual T* find(const std::function<bool(const T&)>& predicate) const;

    // Iterator class
    class Iterator {
    private:
        Node* current;

    public:
        explicit Iterator(Node* node) : current(node) {}
        Iterator& operator++() {
            current = current->next;
            return *this;
        }
        bool operator!=(const Iterator& other) const { return current != other.current; }
        T& operator*() const { return current->data; }
    };

    Iterator begin() const { return Iterator(head); }
    Iterator end() const { return Iterator(nullptr); }
};

// Implementation
template <typename T>
void LinkedList<T>::add(const T& item) {
    Node* newNode = new Node{item, nullptr};
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

template <typename T>
bool LinkedList<T>::remove(const T& item) {
    if (!head) return false;

    if (head->data == item) {
        Node* toDelete = head;
        head = head->next;
        if (!head) tail = nullptr; 
        delete toDelete;
        return true;
    }

    Node* current = head;
    while (current->next && current->next->data != item) {
        current = current->next;
    }

    if (current->next) {
        Node* toDelete = current->next;
        current->next = current->next->next;
        if (!current->next) tail = current; 
        delete toDelete;
        return true;
    }

    return false;
}

template <typename T>
size_t LinkedList<T>::size() const {
    size_t count = 0;
    Node* current = head;
    while (current) {
        ++count;
        current = current->next;
    }
    return count;
}

template <typename T>
void LinkedList<T>::clear() {
    Node* current = head;
    while (current) {
        Node* toDelete = current;
        current = current->next;
        delete toDelete;
    }
    head = tail = nullptr;
}

template <typename T>
T* LinkedList<T>::find(const std::function<bool(const T&)>& predicate) const {
    Node* current = head;
    while (current) {
        if (predicate(current->data)) {
            return &(current->data);
        }
        current = current->next;
    }
    return nullptr;
}

#include "../models/Room.h"

class RoomLinkedList : public LinkedList<Room> {
public:
    Room* findRoomNumber(int roomNumber) {
        return find([roomNumber](const Room& room) {
            return room.getRoomNumber() == roomNumber;
        });
    }
};

#include "../models/Tenant.h"

class TenantLinkedList : public LinkedList<Tenant> {
public:
    Tenant* findTenantById(const std::string& tenantID) {
        return find([tenantID](const Tenant& tenant) {
            return tenant.getId() == tenantID;
        });
    }
};

#endif // LINKEDLIST_H
