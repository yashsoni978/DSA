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
    ListNode* convert(vector<int>& arr){
        if(arr.size() == 0) return NULL;
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;
        for(int i=1; i<arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
            temp -> next = newNode;
            temp = temp -> next;
        }
        return head;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>arr;
        for(int i=0; i<lists.size(); i++){
            ListNode* temp = lists[i];
            while(temp){
                arr.push_back(temp -> val);
                temp = temp -> next;
            }
        }
        sort(arr.begin(), arr.end());
        ListNode* head = convert(arr);
        return head;
    }
};

//n*k + mlogm + m where m = n*k
//2m

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
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return NULL;
        ListNode* head = lists[0];
        for(int i=1; i<lists.size(); i++){
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};

/*TC → O(N × k²)

Because:
N + 2N + 3N + ... + kN
= N × k(k+1)/2
= O(N × k²)

SC → O(1)*/

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int,ListNode*>>, greater<pair<int,ListNode*>>>minH;
        for(int i=0; i<lists.size(); i++){
            if(lists[i]) minH.push({lists[i] -> val, lists[i]});//k log k
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while(!minH.empty()){
            pair<int, ListNode*>p = minH.top();
            minH.pop();
            temp -> next = p.second;
            temp = temp -> next;
            if(p.second -> next) minH.push({p.second -> next -> val, p.second -> next});
        }
        return dummy -> next;
    }
};

//klogk + n*k*logk
//k -> pq stores k elements