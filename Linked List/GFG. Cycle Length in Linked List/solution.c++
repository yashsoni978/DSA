/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* temp = head;
        unordered_map<Node*,int>mp;
        int timer = 0;
        while(temp){
            if(mp.find(temp) != mp.end()){
                int value = mp[temp];
                return (timer - value);
            }
            mp[temp] = timer;
            timer++;
            temp = temp -> next;
        }
        return 0;
    }
};

//2n and n

/* Structure of Linked List Node
class Node {
 public:
    int data;
    Node *next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  private:
    int findLength(Node* slow, Node* fast){
        int cnt = 1;
        fast = fast -> next;
        while(slow != fast){
            cnt++;
            fast = fast -> next;
        }
        return cnt;
    }
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node* slow = head;
        Node* fast = head;
        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return findLength(slow, fast);
        }
        return 0;
    }
};

/*Complexity

TC: O(n)

Floyd's cycle detection → O(n)
findLength() traverses the cycle once → O(n)
Overall → O(n)

SC: O(1)*/