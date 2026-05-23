#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int v) : val(v), next(nullptr) {}
};

ListNode* buildList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    for (int v : vals) { cur->next = new ListNode(v); cur = cur->next; }
    return dummy.next;
}

void printList(ListNode* head) {
    while (head) { cout << head->val << " "; head = head->next; }
    cout << "\n";
}

ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

ListNode* mergeSortedLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { cur->next = l1; l1 = l1->next; }
        else { cur->next = l2; l2 = l2->next; }
        cur = cur->next;
    }
    cur->next = l1 ? l1 : l2;
    return dummy.next;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* fast = &dummy, *slow = &dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) { fast = fast->next; slow = slow->next; }
    ListNode* toDelete = slow->next;
    slow->next = slow->next->next;
    delete toDelete;
    return dummy.next;
}

bool hasCycle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

ListNode* findMiddle(ListNode* head) {
    ListNode* slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main() {
    ListNode* l1 = buildList({1, 2, 3, 4, 5});
    printList(reverseList(l1));
    ListNode* a = buildList({1, 3, 5});
    ListNode* b = buildList({2, 4, 6});
    printList(mergeSortedLists(a, b));
    return 0;
}