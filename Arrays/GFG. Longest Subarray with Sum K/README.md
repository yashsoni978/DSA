<h2>Longest Subarray with Sum K</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an array <code>arr[]</code> containing integers and an integer <code>k</code>,
find the length of the longest subarray whose sum is equal to <code>k</code>.
If no such subarray exists, return <code>0</code>.
</p>

<h3>Example</h3>

<pre>
Input:
arr[] = [10, 5, 2, 7, 1, -10]
k = 15

Output:
6
</pre>

<p>
The subarrays having sum equal to <code>15</code> include:
</p>

<pre>
[10, 5]
[5, 2, 7, 1]
[10, 5, 2, 7, 1, -10]
</pre>

<p>
The longest one has length <code>6</code>.
</p>

<h3>Approach</h3>

<p>
We use <b>Prefix Sum + Hash Map</b> to find the longest subarray efficiently.
</p>

<p>
Let <code>sum</code> be the prefix sum up to the current index.
For a subarray from index <code>j + 1</code> to <code>i</code> to have sum
<code>k</code>:
</p>

<pre>
sum[i] - sum[j] = k
</pre>

<p>Therefore:</p>

<pre>
sum[j] = sum[i] - k
</pre>

<p>
So, for every index, we check whether <code>sum - k</code> has appeared before.
If it has, we can calculate the length of the subarray.
</p>

<h3>Algorithm</h3>

<ol>
<li>Initialize <code>sum = 0</code> and <code>maxLen = 0</code>.</li>
<li>Create a hash map to store the <b>first occurrence</b> of every prefix sum.</li>
<li>Traverse the array:
    <ul>
        <li>Add the current element to <code>sum</code>.</li>
        <li>If <code>sum == k</code>, update <code>maxLen</code> to <code>i + 1</code>.</li>
        <li>Check whether <code>sum - k</code> exists in the map.</li>
        <li>If it exists, calculate the subarray length and update <code>maxLen</code>.</li>
        <li>Store <code>sum</code> only if it is not already present.</li>
    </ul>
</li>
<li>Return <code>maxLen</code>.</li>
</ol>

<h3>Why Store Only the First Occurrence?</h3>

<p>
We want the <b>longest</b> subarray. If the same prefix sum occurs multiple times,
the earliest occurrence gives us the maximum possible length for a future index.
Therefore, we do not overwrite an existing prefix sum.
</p>

<h3>Example Walkthrough</h3>

<pre>
arr = [10, 5, 2, 7, 1, -10]
k = 15
</pre>

<p>Prefix sums:</p>

<pre>
Index:       0   1   2   3   4   5
Prefix Sum: 10  15  17  24  25  15
</pre>

<p>
At index <code>5</code>:
</p>

<pre>
sum = 15
sum - k = 15 - 15 = 0
</pre>

<p>
The prefix sum <code>0</code> represents the position before the array starts,
so the entire array is a valid subarray.
</p>

<pre>
Length = 5 - (-1) = 6
</pre>

<h3>Important Point</h3>

<p>
This approach works even when the array contains <b>negative numbers</b>.
That is why a simple sliding-window approach cannot be used in the general case.
</p>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N)
Space Complexity: O(N)
</pre>

<p>
The array is traversed once, and the hash map stores at most <code>N</code>
different prefix sums.
</p>
