// AlgoExpert - Shift Linked List
using namespace std;

class LinkedList {
public:
    int value;
    LinkedList *next;

    LinkedList(int value) {
        this->value = value;
        next = NULL;
    }
};

LinkedList *reverseList(LinkedList *head) {
    LinkedList *tail = head;
    LinkedList *pre_tail = NULL;

    while (tail->next != NULL) {
        LinkedList *tmp = tail->next;
        tail->next = pre_tail;
        pre_tail = tail;
        tail = tmp;
    }
    
    tail->next = pre_tail;

    return tail;
}

LinkedList *shiftLinkedList(LinkedList *head, int k) {
    bool forward = k > 0;
    
    if (forward) {
        head = reverseList(head);
    }
    else {
        k = -k;
    }

    LinkedList *tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
    }

    for (int i = 0; i < k; i++) {
        tail->next = head;
        tail = tail->next;

        head = head->next;

        tail->next = NULL;
    }

    if (forward) {
        head = reverseList(head);
    }
  
    return head;
}
