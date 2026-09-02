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
    bool isPalindrome(ListNode* head) {
        stack<int>st;
        ListNode* temp = head;
        while(temp){
            st.push(temp -> val);
            temp = temp -> next;
        }
        temp = head;
        while(temp){
            if(temp -> val != st.top()) return false;
            st.pop();
            temp = temp -> next;
        }
        return true;
    }
};

//n and 1

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
private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* newHead = reverseList(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head -> next) return true;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast -> next && fast -> next -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode* newHead = reverseList(slow -> next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second){
            if(first -> val != second -> val){
                reverseList(newHead);
                return false;
            }
            first = first -> next;
            second = second -> next;
        }
        reverseList(newHead);
        return true;
    }
};

//2n and 1