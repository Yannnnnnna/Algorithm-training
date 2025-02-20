//
// Created by WYR on 2025/2/20.
//
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

ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast != NULL){
        slow = slow->next;
        if(fast->next == NULL){
            return NULL;
        }
        fast = fast->next->next;
        if(fast == slow){
            ListNode *p = head;
            while (p != slow){
                p = p->next;
                slow = slow->next;
            }
            return p;
        }
    }
    return NULL;
}
int main()
{
    int n,x;
    ListNode* l=NULL;
    ListNode* r=NULL;
    ListNode* s=NULL;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        //创建新节点
        s=(ListNode*)malloc(sizeof(ListNode));
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
    //连环
    cin>>x;
    s=l;
    while(s!=NULL&&s->val !=x)
    {
        s=s->next;
    }
    r->next =s;

    ListNode* ans=detectCycle(l);

    if(ans==NULL)
    {
        cout<<"无环"<<endl;
    }
    else
    {
        int pos=0;
        s=l;
        while(s!=ans)
        {
            s=s->next;
            pos++;
        }
        cout<<pos<<endl;
    }

    return 0;
}

