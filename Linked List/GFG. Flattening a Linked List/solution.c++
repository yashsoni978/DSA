/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  private:
    Node* convert(vector<int>& arr){
        if(arr.size() == 0) return NULL;
        Node* head = new Node(arr[0]);
        Node* temp = head;
        for(int i=1; i<arr.size(); i++){
            Node* newNode = new Node(arr[i]);
            temp -> bottom = newNode;
            temp = temp -> bottom;
        }
        return head;
    }
  public:
    Node* flatten(Node* head) {
        // code here
        vector<int>arr;
        Node* temp = head;
        while(temp){
            Node* t2 = temp;
            while(t2){
                arr.push_back(t2 -> data);
                t2 = t2 -> bottom;
            }
            temp = temp -> next;
        }
        sort(arr.begin(), arr.end());
        head = convert(arr);
        return head;
    }
};

//n*m*2 + xlogx (x = n*m)
//2*n*m

/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
  private:
    Node* merge(Node* list1, Node* list2){
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while(list1 && list2){
            if(list1 -> data < list2 -> data){
                res -> bottom = list1;
                res = list1;
                list1 = list1 -> bottom;
            }
            else{
                res -> bottom = list2;
                res = list2;
                list2 = list2 -> bottom;
            }
            res -> next = NULL;
        }
        if(list1) res -> bottom = list1;
        else res -> bottom = list2;
        if(dummyNode -> next) dummyNode -> bottom -> next = NULL;
        return dummyNode -> bottom;
    }
  public:
    Node* flatten(Node* head) {
        // code here
        if(!head || !head -> next) return head;
        Node* mergedHead = flatten(head -> next);
        head = merge(head, mergedHead);
        return head;
    }
};

//n * 2m and 1