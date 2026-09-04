class Solution {
private:
    ListNode* arrayToList(vector<int>& arr) {
        if(arr.empty()) return NULL;

        ListNode* head = new ListNode(arr[0]);
        ListNode* mover = head;

        for(int i = 1; i < arr.size(); i++){
            ListNode* temp = new ListNode(arr[i]);
            mover -> next = temp;
            mover = temp;
        }

        return head;
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int> arr;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1){
            arr.push_back(temp1 -> val);
            temp1 = temp1 -> next;
        }

        while(temp2){
            arr.push_back(temp2 -> val);
            temp2 = temp2 -> next;
        }

        sort(arr.begin(), arr.end());

        ListNode* head = arrayToList(arr);

        return head;
    }
};
//n1 + n2 + nlogn + n and 2n


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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while(list1 && list2){
            if(list1 -> val <= list2 -> val){
                curr -> next = list1;
                list1 = list1 -> next;
            }
            else{
                curr -> next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;
        }
        curr -> next = (list1) ? list1 : list2;
        return dummy.next;
    }
};

