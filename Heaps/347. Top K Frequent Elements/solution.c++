/*Brute Force Approach
Idea
Count the frequency of every element using a hash map.
Store all (frequency, element) pairs in a vector.
Sort the vector in decreasing order of frequency.
Return the first k elements.

Algorithm
Traverse the array and count frequencies.
Store {frequency, element} in a vector.
Sort the vector in descending order.
Pick the first k elements.*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int x : nums) mp[x]++;
        vector<pair<int,int>>freq;
        for(auto &it : mp) freq.push_back({it.second, it.first});
        sort(freq.begin(), freq.end(), greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0; i<k; i++) ans.push_back(freq[i].second);
        return ans;
    }
};

/*Time Complexity
Counting frequency = O(n)
Sorting = O(m log m)

where m = number of distinct elements

Overall:

O(n + m log m)

Space Complexity

O(m)*/

/*Optimal Approach (Min Heap)
Idea

Instead of sorting all frequencies, maintain a Min Heap of size k.

The heap stores the k most frequent elements.

Whenever heap size exceeds k, remove the smallest frequency.

Algorithm
Count frequencies.
Create a Min Heap storing
frequency
element
Traverse frequency map.
Push every pair into heap.
If heap size becomes greater than k, pop the smallest frequency.
Heap finally contains the top k frequent elements.*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(int x : nums) mp[x]++;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>minH;
        for(auto &it : mp){
            minH.push({it.second, it.first});
            if(minH.size() > k) minH.pop();
        }
        vector<int>ans;
        while(!minH.empty()){
            ans.push_back(minH.top().second);
            minH.pop();
        }
        return ans;
    }
};
/*Time Complexity

Let:

n = size of array
m = distinct elements
Frequency map = O(n)
Heap insertion = m × O(log k)

Overall:

O(n + m log k)

If every element is unique (m = n):

O(n log k)

Space Complexity
Frequency map = O(m)
Heap = O(k)

Overall:

O(m + k)*/