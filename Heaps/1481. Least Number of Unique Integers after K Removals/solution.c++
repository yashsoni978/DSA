/*Brute Force Approach
Idea
Count the frequency of every unique integer.
Repeatedly find the element with the minimum frequency.
Remove all of its occurrences if k allows.
Repeat until k becomes 0 or no more complete removals are possible.

Since we search for the minimum frequency every time, this is inefficient.

Algorithm
Count frequencies using a hash map.
While k > 0:
Find the element having the smallest positive frequency.
If k >= frequency
Remove that element completely.
Decrease k.
Otherwise stop.
Count remaining unique elements.*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>freq;
        for(int x : arr) freq[x]++;
        while(k > 0){
            int minFreq = INT_MAX, ele = -1;
            for(auto &it : freq){
                if(it.second > 0 && it.second < minFreq){
                    minFreq = it.second;
                    ele = it.first;
                }
            }
            if(ele == -1 || minFreq > k) break;
            k -= minFreq;
            freq[ele] = 0;
        }
        int unique = 0;
        for(auto &it : freq){
            if(it.second > 0) unique++;
        }
        return unique;
    }
};

/*Time Complexity

Let m = number of unique elements.

Frequency map = O(n)
Every removal scans all unique elements = O(m²) in the worst case

Overall: O(n + m²)

Space Complexity

O(m)*/

/*Optimal Approach (Min Heap)
Idea

To minimize the number of unique integers:

Always remove the integer having the smallest frequency first.
Store all frequencies in a Min Heap.
Keep removing the smallest frequency while k permits.
Algorithm
Count frequencies.
Push every frequency into a Min Heap.
While heap is not empty and k >= top frequency:
Remove the top frequency.
Subtract it from k.
Remaining heap size equals the number of unique integers left.*/

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int>freq;
        for(int x : arr) freq[x]++;
        priority_queue<int, vector<int>, greater<int>>minH;
        for(auto &it : freq) minH.push(it.second);
        while(!minH.empty() && k >= minH.top()){
            k -= minH.top();
            minH.pop();
        }
        return minH.size();
    }
};

/*Time Complexity

Let:

n = array size
m = number of unique integers
Frequency map = O(n)
Heap construction = O(m log m)
Heap removals = O(m log m)

Overall: O(n + m log m)

Space Complexity
Frequency map = O(m)
Min Heap = O(m)

Overall: O(m)*/