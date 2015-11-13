// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <mutex>

using namespace std;

struct Node {
    int val;
    Node* next;
};

class LinkedList {
public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
        while(head) {
            Node* headptr = head;
            cout << "deleted " << headptr->val << endl;
            head = head->next;
            delete headptr;
        }
    }

    void displayList() const {
        Node* p = head;
        while(p) {
            cout << "  " << p->val << endl;
            p = p->next;
        }
    }

    LinkedList* add(int value) {
        Node* p = new Node;
        p->val = value;
        p->next = head;
        head = p;

        return this;
    }

    void merge(LinkedList* list) {
        Node* p2 =  list->headPointer();
        Node* phead = head;
        Node* temp;
        Node* pre = phead;
        bool flag = false;

        while(p2) {
            while (phead) {
                if(p2->val <= phead->val) { 
                    if (head == phead) {//left insert
                        temp = p2;
                        p2 = p2->next;
                        temp->next = head;
                        phead = head;
                        head = temp;
                    }
                    else { //middle insert
                        temp = p2;
                        p2 = p2->next;
                        temp->next = phead;
                        pre->next = temp;
                    }
                    //continue p2
                    flag = true;
                    break;
                }
                else { // no insert, continue finding
                    pre = phead;
                    phead= phead->next;
                    flag = false;
                    continue;
                }
            }
            if (flag) {
                continue;
            }
            // right insert
            phead->next = p2;
            break;
        }
    }

    void sort() {
        if (!head || !head->next) {
            return;
        }
        for (Node* p = head; p->next; p=p->next) {
            //swap p and p->next if 
            for (Node* p1 = p; p1; p1=p1->next) {
                if (p->val > p1->val) {
                    int temp = p1->val;
                    p1->val = p->val;
                    p->val = temp;
                }
            }
        }
    }

    void reverse() {
        Node* p = head;
        head = nullptr;
        while(p) {
            Node* temp = p;
            p = p->next;

            temp->next = head;
            head = temp;
        }
    }

    Node* headPointer() {
        return head;
    }

    void reverseSection(int m, int n) {
        // check m and n are within reasonable scope
        int reg = 0;
        Node* p = head;
        Node* end1 = head;
        Node* mend = head;
        Node* mstart = nullptr;
        Node* temp = nullptr;
        while (reg != n+1) {
            ++reg;

            if (reg < m-1) {
                p = p->next;
                continue;
            }
            else if(reg == m-1) {
                end1 = p;
                p = p->next;
                mend = p;
                mstart = mend;
            }
            else if (reg > m-1 && reg <= n) {
                temp = p;
                p = p->next;
                temp->next = mstart;
                mstart = temp;
            }
            else {
                break;
            }
        }

        if (m == 1) {
            head = mstart;
            mend->next = p;
        }
        else {
            end1->next = mstart;
            mend->next = p;
        }
    }

private:
    Node* head;
};


int _tmain(int argc, _TCHAR* argv[])
{
    LinkedList* m = new LinkedList;
    m->add(0)->add(2)->add(4)->add(6)->add(8)->add(9);
    m->sort();
    m->displayList();

    // m->reverseSection(2,7);
    // m->displayList();

    LinkedList* n = new LinkedList;
    n->add(1)->add(3)->add(5)->add(7)->add(9);
    n->sort();
    n->displayList();

    m->merge(n);
    cout << "===========" << endl;
    m->displayList();

    system("PAUSE");
	return 0;
}
