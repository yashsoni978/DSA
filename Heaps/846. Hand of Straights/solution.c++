/*Brute Force Approach
Idea
Sort the array.
Start from the smallest unused card.
Try to build a consecutive group of size groupSize.
Mark used cards so they are not reused.

Since we repeatedly search for the next consecutive number, this approach is slow.

Algorithm
Sort the array.
Maintain a used array.
For every unused card:
Start a new group.
Find the next consecutive numbers one by one.
Mark them as used.
If at any point a required card is missing, return false.*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        vector<bool>used(n, false);
        for(int i=0; i<n; i++){
            if(used[i]) continue;
            used[i] = true;
            int prev = hand[i];
            int cnt = 1;
            for(int j=i+1; j<n && cnt < groupSize; j++){
                if(!used[j] && hand[j] == prev+1){
                    used[j] = true;
                    prev = hand[j];
                    cnt++;
                }
            }
            if(cnt != groupSize) return false;
        }
        return true;
    }
};

/*Time Complexity

Sorting

O(n log n)

Searching for every next card

O(n²)

Overall

O(n²)
Space Complexity
O(n)*/

/*Heap Approach (Greedy + Min Heap)
Idea

Instead of using a map to always find the smallest card, use a Min Heap.

Count frequencies using a hash map.
Push all distinct cards into a min heap.
Always take the smallest card from the heap.
If its frequency is already 0, ignore it.

Otherwise, try to form a group:

x, x+1, x+2, ..., x+groupSize-1
Reduce the frequency of every card in the group.
Algorithm
If n % groupSize != 0, return false.
Count frequencies.
Push every distinct card into a min heap.
While heap is not empty:
Let x = heap.top().
If freq[x] == 0, pop it.
Otherwise,
For i = 0 to groupSize-1
If freq[x+i] == 0, return false.
Decrease its frequency.
Return true.*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize) return false;
        unordered_map<int,int>freq;
        for(int x : hand) freq[x]++;
        priority_queue<int, vector<int>, greater<int>>minH;
        for(auto &it : freq) minH.push(it.first);
        while(!minH.empty()){
            int start = minH.top();
            if(freq[start] == 0){
                minH.pop();
                continue;
            }
            for(int i=0; i<groupSize; i++){
                if(freq[start + i] == 0) return false;
                freq[start + i]--;
            }
        }
        return true;
    }
};

/*Time Complexity
Frequency Map → O(n)
Heap Construction → O(m log m) (m = distinct cards)
Processing → O(n log m) in the worst case

Overall: O(n log m)

Space Complexity
Frequency Map → O(m)
Heap → O(m)

Overall: O(m)*/