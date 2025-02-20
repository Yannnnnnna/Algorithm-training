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

ListNode* trainingPlan(ListNode* head, int cnt) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL){
        if(cnt > 1){
            fast = fast->next;
            --cnt;
        } else{
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
}
int main(){
    int n,x,k;
    ListNode* l=NULL;
    ListNode* r=NULL;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        //创建新节点
        ListNode* s=(ListNode*)malloc(sizeof(ListNode));
        s->val=x;
        s->next=NULL;
        //头结点
        if(i==1)
        {
            l=r=s;
            continue;
        }
        //尾插
        r->next =s;
        r=s;
    }
    ListNode* ans=trainingPlan(l,k);
    cout<<ans->val<<" ";

    return 0;
}