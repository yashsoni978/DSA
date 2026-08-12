<h2>1004. Max Consecutive Ones III</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a binary array <code>nums</code> and an integer <code>k</code>, return the maximum number of consecutive <code>1</code>'s in the array if you can flip at most <code>k</code> <code>0</code>'s.</p>

<p>In other words, you can change at most <code>k</code> zeros into ones. Find the length of the longest subarray that can contain only <code>1</code>'s after these operations.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
nums = [1,1,1,0,0,0,1,1,1,1,0]
k = 2

<strong>Output:</strong>
6

<strong>Explanation:</strong>
The longest subarray is:

[1,1,1,0,0,1]

Flip the two zeros to ones:

[1,1,1,1,1,1]

Length = 6.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
nums = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1]
k = 3

<strong>Output:</strong>
10

<strong>Explanation:</strong>
The longest valid subarray can contain at most
3 zeros, which can all be flipped to ones.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ nums.length ≤ 10<sup>5</sup></code></li>
  <li><code>nums[i]</code> is either <code>0</code> or <code>1</code>.</li>
  <li><code>0 ≤ k ≤ nums.length</code></li>
</ul>

<p><strong>Brute Force Approach:</strong></p>

<p>Consider every possible subarray. Count the number of zeros in the current subarray.</p>

<p>If the number of zeros is at most <code>k</code>, the subarray can be converted completely into ones.</p>

<pre>
For every starting index:

    zeroCount = 0

    for every ending index:
        if nums[j] == 0:
            zeroCount++

        if zeroCount ≤ k:
            update answer
</pre>

<p>This approach takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique.</p>

<p>Maintain a window using two pointers, <code>left</code> and <code>right</code>. The window represents a subarray that contains at most <code>k</code> zeros.</p>

<p>For every element:</p>

<ol>
  <li>Expand the window by moving <code>right</code>.</li>
  <li>If <code>nums[right] == 0</code>, increase the zero count.</li>
  <li>If the number of zeros becomes greater than <code>k</code>, move <code>left</code> forward until the window becomes valid again.</li>
  <li>Update the maximum window length.</li>
</ol>

<p><strong>Sliding Window Condition:</strong></p>

<pre>
number of zeros in current window ≤ k
</pre>

<p><strong>Example:</strong></p>

<pre>
nums = [1,1,0,0,1,1,1]
k = 1

Window:
[1,1,0]

zeros = 1
valid → length = 3

Expand:

[1,1,0,0]

zeros = 2
invalid

Move left:

[1,0,0]

still 2 zeros → invalid

Move left again:

[0,0]

still invalid

Move left again:

[0]

zeros = 1 → valid
</pre>

<p>The window always represents the longest valid range ending at the current <code>right</code>.</p>

<p><strong>Key Observation:</strong></p>

<p>You do not need to actually flip the zeros. You only need to count how many zeros are inside the current window.</p>

<p>If the window contains at most <code>k</code> zeros, all those zeros <strong>could</strong> be flipped, so the entire window can become ones.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
