/* Brute
Idea:
- Count frequency of each character.
- Repeatedly find the character with the highest remaining frequency.
- Append it frequency times to the answer.
- Mark its frequency as 0.
- Repeat until all characters are processed.

TC: O(n²)
SC: O(1)
*/
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char c : s) freq[c]++;
        string ans = "";
        while(!freq.empty()){
            char ch;
            int mx = 0;
            for(auto &it : freq){
                if(it.second > mx){
                    mx = it.second;
                    ch = it.first;
                }
            }
            ans.append(mx, ch);
            freq.erase(ch);
        }
        return ans;
    }
};

/* Optimal (Max Heap)
Idea:
- Count frequency of each character.
- Push {frequency, character} into a max heap.
- Pop the character with the highest frequency.
- Append it frequency times to the answer.
- Repeat until the heap becomes empty.

Why Heap?
- Max heap always gives the character with the highest remaining frequency.

TC:
Frequency Count : O(n)
Heap Operations : O(k log k)

Overall: O(n + k log k)

SC: O(k)

(k = number of unique characters)
*/

class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        unordered_map<char,int>freq;
        for(char c : s) freq[c]++;
        priority_queue<pair<int, char>>maxH;
        for(auto &it : freq) maxH.push({it.second, it.first});
        while(!maxH.empty()){
            auto [cnt, ch] = maxH.top();
            maxH.pop();
            ans.append(cnt, ch);
        }
        return ans;
    }
};