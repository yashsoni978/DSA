/*Time: O(N × L + P × K) where P is the number of shortest paths and K is the length of each path. In the worst case, the number of shortest paths can be exponential.
Space: O(N + P × K) due to the hash set, queue, and storage of all shortest paths. Worst case is exponential because of the number of valid shortest sequences.*/
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(), wordList.end());
        queue<vector<string>>q;
        q.push({beginWord});
        vector<string>usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec = q.front();
            q.pop();
            //erase all the words that has been used in the previous levels to transform
            if(vec.size() > level){
                level++;
                for(auto it : usedOnLevel) st.erase(it);
            }
            string word = vec.back();
            if(word == endWord){
                if(ans.size() == 0) ans.push_back(vec); //first sequence
                else if(ans[0].size() == vec.size()) ans.push_back(vec);
            }
            for(int i=0; i<word.size(); i++){
                char original = word[i];
                for(char c = 'a'; c <= 'z'; c++){
                    word[i] = c;
                    if(st.count(word) > 0){
                        vec.push_back(word);
                        q.push(vec);
                        usedOnLevel.push_back(word);//mark as vis on level
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};