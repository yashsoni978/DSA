class Solution {
private:
    int count = 0;
    string ans = "";

    void solve(string& nums, int k, vector<bool>& used, string& curr) {
        if (curr.size() == nums.size()) {
            count++;

            if (count == k)
                ans = curr;

            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            used[i] = true;
            curr.push_back(nums[i]);

            solve(nums, k, used, curr);

            curr.pop_back();
            used[i] = false;

            // Stop generating once kth permutation is found
            if (!ans.empty())
                return;
        }
    }

public:
    string getPermutation(int n, int k) {
        string nums = "";

        for (int i = 1; i <= n; i++)
            nums += char('0' + i);

        vector<bool> used(n, false);
        string curr;

        solve(nums, k, used, curr);

        return ans;
    }
};
/*Time: O(n × n!)
Space: O(n) excluding the recursion/output.*/

class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>numbers;
        for(int i=1; i<n; i++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        k -= 1;
        string ans = "";
        while(true){
            ans += to_string(numbers[k / fact]);
            numbers.erase(numbers.begin() + k / fact);
            if(numbers.size() == 0) break;
            k %= fact;
            fact /= numbers.size();
        }
        return ans;
    }
};

//n^2
//n