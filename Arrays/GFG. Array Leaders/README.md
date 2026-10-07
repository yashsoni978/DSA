<h2>Array Leaders</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>
Given an array <code>arr</code> of positive integers, find all the
<b>leaders</b> in the array.
</p>

<p>
An element is called a leader if it is <b>greater than or equal to all
elements to its right</b>. The rightmost element is always a leader.
</p>

<h3>Example</h3>

<pre>
Input:
arr = [16, 17, 4, 3, 5, 2]

Output:
[17, 5, 2]
</pre>

<p>
Explanation:
</p>

<pre>
17 → all elements to its right are smaller
5  → all elements to its right are smaller
2  → rightmost element, so always a leader
</pre>

<h3>Approach</h3>

<p>
Traverse the array from <b>right to left</b>.
Keep track of the maximum element seen so far from the right.
</p>

<ol>
<li>The rightmost element is always a leader.</li>
<li>If the current element is greater than or equal to <code>maxRight</code>, it is a leader.</li>
<li>Update <code>maxRight</code> after checking each element.</li>
<li>Since we traverse from right to left, reverse the answer at the end.</li>
</ol>

<h3>Example</h3>

<pre>
arr = [16, 17, 4, 3, 5, 2]

Traverse from right:

2 → leader
5 → leader
3 → not leader
4 → not leader
17 → leader
16 → not leader

Collected:
[2, 5, 17]

Reverse:
[17, 5, 2]
</pre>

<h3>Important Point</h3>

<p>
The condition is <code>&gt;=</code>, not just <code>&gt;</code>.
Therefore, equal elements can both be leaders.
</p>

<pre>
arr = [10, 4, 2, 4, 1]

Output:
[10, 4, 4, 1]
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N)
Space Complexity: O(N)
</pre>

<p>
We traverse the array once. The extra space is used for storing the
leader elements in the result.
</p>
