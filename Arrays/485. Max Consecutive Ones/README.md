<h2>485. Max Consecutive Ones</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given a binary array <code>nums</code>, return the maximum number of consecutive
<code>1</code>s in the array.
</p>

<h3>Example</h3>

<pre>
Input:  nums = [1,1,0,1,1,1]

Output: 3
</pre>

<h3>Approach</h3>

<p>
Traverse the array and maintain two variables:
</p>

<ul>
<li><code>count</code> → stores the current consecutive count of <code>1</code>s.</li>
<li><code>maxCount</code> → stores the maximum consecutive count found so far.</li>
</ul>

<p>
Whenever we encounter <code>1</code>, increase <code>count</code>.
When we encounter <code>0</code>, reset <code>count</code> to <code>0</code>.
Update <code>maxCount</code> after every <code>1</code>.
</p>

<h3>Code</h3>

<pre>
class Solution {
public:
    int findMaxConsecutiveOnes(vector&lt;int&gt;&amp; nums) {
        int count = 0;
        int maxCount = 0;

        for(int num : nums) {
            if(num == 1) {
                count++;
                maxCount = max(maxCount, count);
            }
            else {
                count = 0;
            }
        }

        return maxCount;
    }
};
</pre>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
// N = number of elements in nums
</pre>

<h3>Key Point</h3>

<p>
A <code>0</code> breaks the consecutive sequence, so we simply reset the current
count whenever we encounter <code>0</code>.
</p>
