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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return NULL;
        int cnt = 0;
        ListNode* temp = head;
        while(temp){
            cnt++;
            temp = temp -> next;
        }
        if(cnt == n){
            ListNode* newHead = head -> next;
            delete(head);
            return newHead;
        }
        int res = cnt - n;
        temp = head;
        while(temp){
            res--;
            if(res == 0) break;
            temp = temp -> next;
        }
        ListNode* delNode = temp -> next;
        temp -> next = temp -> next -> next;
        delete(delNode);
        return head;
    }
};

//l + (n-l) and 1

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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<n; i++) fast = fast -> next;
        if(!fast) return head -> next; //nth node from end is head
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        ListNode* delNode = slow -> next;
        slow -> next = slow -> next -> next;
        delete(delNode);
        return head;
    }
};
//n and 1