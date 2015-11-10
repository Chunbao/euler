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


    void reverseSection(int m, int n);
    void merge(LinkedList& list) {

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

private:
    Node* head;
};

int _tmain(int argc, _TCHAR* argv[])
{
    LinkedList* m = new LinkedList;
    m->add(0)->add(2)->add(4)->add(6)->add(8);
    m->sort();
    m->displayList();

    LinkedList* n = new LinkedList;
    n->add(1)->add(3)->add(5)->add(7)->add(9);
    n->sort();
    n->displayList();



    system("PAUSE");
	return 0;
}
