//
// Created by WYR on 2025/2/19.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct ListNode {
    int val;
    ListNode *next;
} ListNode;
ListNode *reverseList(ListNode *head) {
    ListNode *p = head;
    ListNode *q = NULL;
    ListNode *t = q;
    while (p != NULL){
        t = p->next;
        p->next = q;
        q = p;
        p = t;
    }
    return q;
}
int main() {
    int n, x;
    ListNode *l = NULL;
    ListNode *r = NULL;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        //创建新节点
        ListNode *s = (ListNode *) malloc(sizeof(ListNode));
        s->val = x;
        s->next = NULL;
        //头结点
        if (i == 1) {
            l = r = s;
            continue;
        }
        //尾插
        r->next = s;
        r = s;
    }
    l = reverseList(l);
    while (l != NULL) {
        cout << l->val << " ";
        l = l->next;
    }

    return 0;
}