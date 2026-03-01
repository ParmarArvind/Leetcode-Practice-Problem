/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// iterative way
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev=nullptr;
        ListNode* temp=head;
        ListNode* next;
        while(temp)
        {
            next=temp->next;
            temp->next=prev;
            prev=temp;
            temp=next;
        }

        head=prev;
        return head;
        
    }
};


// recusive -1
class Solution {
public:
    ListNode* solve(ListNode* curr,ListNode* prev)
    {
        if(!curr) return prev;

        ListNode* next= curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

        return solve(curr,prev);

    }
    ListNode* reverseList(ListNode* head) {
        return solve(head,nullptr)  ;     
    }
};

// recursive -2 
class Solution {
public:
// use diagram in linklist for understand 
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next==nullptr) return head;

        ListNode* last=reverseList(head->next);
        
        head->next->next=head; 

        head->next=nullptr;

        return last;
    }
};
