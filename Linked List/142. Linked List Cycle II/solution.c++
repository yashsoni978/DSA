/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        unordered_map<ListNode*,int>mp;
        while(temp){
            if(mp.find(temp) != mp.end()) return temp;
            mp[temp] = 1;
            temp = temp -> next;
        }
        return NULL;
    }
};

//n and n

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow -> next;
                    fast = fast -> next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

//n and 1
/*Intuition:
Once slow and fast meet inside the cycle, the distances are aligned
such that the distance from head to the cycle start equals the
remaining distance from the meeting point to the cycle start.

So, move one pointer back to head and move both pointers one step
at a time. They will meet exactly at the cycle's starting node.*/