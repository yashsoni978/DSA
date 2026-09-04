class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string url) {
        val = url;
        next = nullptr;
        prev = nullptr;
    }
};

class BrowserHistory {
public:
    Node* current;
    BrowserHistory(string homepage) {
        current = new Node(homepage);//1
    }
    
    void visit(string url) {//1
        current -> next = NULL;//remove forward history
        Node* newNode = new Node(url);
        newNode -> prev = current;
        current -> next = newNode;
        current = newNode;
    }
    
    string back(int steps) {//steps
        while(steps){
            if(current -> prev) current = current -> prev;
            else break;
            steps--;
        }
        return current -> val;
    }
    
    string forward(int steps) {//O(steps)
        while(steps){
            if(current -> next) current = current -> next;
            else break;
            steps--;
        }
        return current -> val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

 /*visit:   O(1)
back:    O(steps)
forward: O(steps)

Space: O(N)*/