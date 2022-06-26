#include <iostream>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    set<ListNode*> setA, setB;

    for (auto tmpA = headA, tmpB = headB; tmpA != NULL || tmpB != NULL;) {
        if (setA.find(tmpB) == setA.end()) {
            setA.insert(tmpA);
        }
        else if (setA.find(tmpB) != setA.end()) {
            return tmpB;
        }

        if (setB.find(tmpA) == setB.end()) {
            setB.insert(tmpB);
        }
        else if (setB.find(tmpA) != setB.end()) {
            return tmpA;
        }

        if (tmpA == tmpB) {
            return tmpA;
        }

        if (tmpA != NULL) {
            tmpA = tmpA->next;
        }

        if (tmpB != NULL) {
            tmpB = tmpB->next;
        }
    }

    return NULL;
}

int main()
{
    ListNode n5(5);
    ListNode n4(4);
    n4.next = &n5;
    ListNode n8(8);
    n8.next = &n4;

    ListNode n1(1);
    n1.next = &n8;
    ListNode n41(4);
    n41.next = &n1;

    ListNode n11(1);
    n11.next = &n8;
    ListNode n6(6);
    n6.next = &n11;
    ListNode n51(5);
    n51.next = &n6;

    ListNode* ret = getIntersectionNode(&n41, &n51);

    if (ret != NULL) {
        cout << "Val: " << ret->val << "   Next val: " << ret->next->val;
    }
    
    return 0;
}