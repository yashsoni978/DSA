class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        set<int>st;
        for(int x : a) st.insert(x);
        for(int x : b) st.insert(x);
        vector<int>ans(st.begin(), st.end());
        return ans;
    }
};

//n1 log n + n2 log n + (n1 + n2)
//n1 + n2 + (n1 + n2) -> to return the ans

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int>ans;
        int i = 0, j = 0;
        int n = a.size(), m = b.size();
        while(i < n && j < m){
            if(a[i] <= b[j]){
                if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
                i++;
            }
            else{
                if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
                j++;
            }
        }
        while(i < n){
            if(ans.empty() || ans.back() != a[i]) ans.push_back(a[i]);
            i++;
        }
        while(j < m){
            if(ans.empty() || ans.back() != b[j]) ans.push_back(b[j]);
            j++;
        }
        return ans;
    }
};

//n1 + n2
//n1 + n2