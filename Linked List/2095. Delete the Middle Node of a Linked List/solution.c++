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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next) return NULL;
        ListNode* temp = head;
        int cnt = 0;
        while(temp){
            cnt++;
            temp = temp -> next;
        }
        int res = cnt/2;
        temp = head;
        while(temp){
            res--;
            if(res == 0){
                ListNode* middle = temp -> next;
                temp -> next = temp -> next -> next;
                delete(middle);
                break;
            }
            temp = temp -> next;
        }
        return head;
    }
};

//n + n/2 and 1

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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head || !head -> next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast -> next -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};

//n/2 and 1