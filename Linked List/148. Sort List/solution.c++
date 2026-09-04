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
    ListNode* sortList(ListNode* head) {
        vector<int>arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        sort(arr.begin(), arr.end());
        temp = head;
        for(int i=0; i<arr.size(); i++){
            temp -> val = arr[i];
            temp = temp -> next;
        }
        return head;
    }
};

/*n + nlogn + n and n*/

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* t1 = list1;
        ListNode* t2 = list2;
        ListNode* dummyNode = new ListNode(-1);
        ListNode* temp = dummyNode;
        while(t1 && t2){
            if(t1 -> val < t2 -> val){
                temp -> next = t1;
                temp = t1;
                t1 = t1 -> next;
            }
            else{
                temp -> next = t2;
                temp = t2;
                t2 = t2 -> next;
            }
        }
        if(t1) temp -> next = t1;
        else temp -> next = t2;
        return dummyNode -> next;
    }
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head -> next) return head;
        ListNode* middle = findMiddle(head);
        ListNode* leftHead = head;
        ListNode* rightHead = middle -> next;
        middle -> next = NULL;
        ListNode* left = sortList(leftHead);
        ListNode* right = sortList(rightHead);
        return mergeTwoLists(left, right);
    }
};

/*TC → O(N log N)

SC → O(log N) → recursion stack

No extra array/vector is used.*/