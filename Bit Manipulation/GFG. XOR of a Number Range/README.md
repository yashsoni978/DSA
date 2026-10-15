<h2>XOR of a Number Range</h2>
<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given two integers <b>l</b> and <b>r</b>, find the bitwise XOR of all
integers in the range <b>[l, r]</b>, including both endpoints.
</p>

<h3>Example 1</h3>

<pre>
Input: l = 4, r = 8
Output: 8
</pre>

<p>
Explanation: The XOR of all numbers in the range is:
</p>

<pre>
4 ^ 5 ^ 6 ^ 7 ^ 8 = 8
</pre>

<h3>Example 2</h3>

<pre>
Input: l = 2, r = 4
Output: 5
</pre>

<p>
Explanation:
</p>

<pre>
2 ^ 3 ^ 4 = 5
</pre>

<h3>Example 3</h3>

<pre>
Input: l = 5, r = 9
Output: 5
</pre>

<p>
Explanation:
</p>

<pre>
5 ^ 6 ^ 7 ^ 8 ^ 9 = 5
</pre>

<h3>Approach</h3>

<p>
Use the properties of XOR to calculate the result efficiently without
iterating through every number in the range.
</p>

<p>
The XOR of all numbers from <b>0</b> to <b>n</b> follows a repeating
pattern based on <b>n % 4</b>:
</p>

<ul>
    <li>If <b>n % 4 == 0</b>, the result is <b>n</b>.</li>
    <li>If <b>n % 4 == 1</b>, the result is <b>1</b>.</li>
    <li>If <b>n % 4 == 2</b>, the result is <b>n + 1</b>.</li>
    <li>If <b>n % 4 == 3</b>, the result is <b>0</b>.</li>
</ul>

<p>
Let <b>prefixXOR(n)</b> represent the XOR of all numbers from 0 to n.
Then the XOR of the range [l, r] can be calculated as:
</p>

<pre>
XOR(l, r) = prefixXOR(r) ^ prefixXOR(l - 1)
</pre>

<p>
The numbers from 0 to l - 1 cancel out because XORing a number with itself
produces 0.
</p>

<h3>Complexity</h3>

<pre>
// TC: O(1)
// SC: O(1)
</pre>

<h3>Key Point</h3>

<p>
Use the repeating pattern of prefix XOR and the identity
<b>a ^ a = 0</b> to find the XOR of any range in constant time.
</p>
