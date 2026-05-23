#include <bits/stdc++.h>
using namespace std;

struct DListNode {
    int val;
    DListNode* prev;
    DListNode* next;
    DListNode(int v) : val(v), prev(nullptr), next(nullptr) {}
};

struct DoublyLinkedList {
    DListNode* head;
    DListNode* tail;
    int size;

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void pushFront(int val) {
        DListNode* node = new DListNode(val);
        if (!head) { head = tail = node; }
        else { node->next = head; head->prev = node; head = node; }
        size++;
    }

    void pushBack(int val) {
        DListNode* node = new DListNode(val);
        if (!tail) { head = tail = node; }
        else { tail->next = node; node->prev = tail; tail = node; }
        size++;
    }

    void popFront() {
        if (!head) return;
        DListNode* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        else tail = nullptr;
        delete temp;
        size--;
    }

    void popBack() {
        if (!tail) return;
        DListNode* temp = tail;
        tail = tail->prev;
        if (tail) tail->next = nullptr;
        else head = nullptr;
        delete temp;
        size--;
    }

    void remove(DListNode* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;
        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
        delete node;
        size--;
    }

    void print() {
        DListNode* cur = head;
        while (cur) { cout << cur->val << " "; cur = cur->next; }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    dll.pushBack(1);
    dll.pushBack(2);
    dll.pushBack(3);
    dll.pushFront(0);
    dll.print();
    dll.popFront();
    dll.popBack();
    dll.print();
    return 0;
}