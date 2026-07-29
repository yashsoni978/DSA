/*/* Brute
Idea:
- Try matching needle starting from every index of haystack.
- If all characters match, return that index.
- If no match is found, return -1.

TC: O((n-m+1) × m) ≈ O(nm)

SC: O(1)
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i=0; i<=n-m; i++){
            int j = 0;//j compares characters inside the needle.
            while(j < m && haystack[i+j] == needle[j]) j++;//i = starting position in the haystack ,j = how far we've matched into the needle , So i + j always points to the correct character in the haystack.
            if(j == m) return i;
        }
        return -1;
    }
};

/*Optimal uses KMP algo*/