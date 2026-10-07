<h2>268. Missing Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given an array <code>nums</code> containing <code>n</code> distinct numbers in the range
<code>[0, n]</code>, return the only number in the range that is missing from the array.
</p>

<h3>Example</h3>

<pre>
Input:  nums = [3,0,1]

Output: 2
</pre>

<h3>Approach</h3>

<p>
We can use the <b>XOR</b> operation.
</p>

<p>
The important properties of XOR are:
</p>

<ul>
<li><code>a ^ a = 0</code></li>
<li><code>a ^ 0 = a</code></li>
</ul>

<p>
If we XOR all numbers from <code>0</code> to <code>n</code> with all elements of the array,
every number that exists in the array will cancel itself out. Only the missing number remains.
</p>

<h3>Example</h3>

<pre>
nums = [3, 0, 1]
n = 3

0 ^ 1 ^ 2 ^ 3
^
3 ^ 0 ^ 1

= 2
</pre>

<h3>Code</h3>

<pre>
class Solution {
public:
    int missingNumber(vector&lt;int&gt;&amp; nums) {
        int n = nums.size();
        int ans = n;

        for(int i = 0; i &lt; n; i++) {
            ans = ans ^ i ^ nums[i];
        }

        return ans;
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
XOR is useful here because every number that appears twice gets cancelled,
leaving only the missing number.
</p>
