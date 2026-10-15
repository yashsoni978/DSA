<h2>2220. Minimum Bit Flips to Convert Number</h2>
<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given two integers <b>start</b> and <b>goal</b>, return the minimum number
of bit flips required to convert <b>start</b> into <b>goal</b>.
</p>

<p>
A bit flip changes a bit from <b>0 to 1</b> or from <b>1 to 0</b>.
</p>

<h3>Example 1</h3>

<pre>
Input: start = 10, goal = 7
Output: 3
</pre>

<p>
Binary representation:
</p>

<pre>
start = 10 = 1010
goal  =  7 = 0111
</pre>

<p>
Three bits are different, so we need three bit flips.
</p>

<h3>Example 2</h3>

<pre>
Input: start = 3, goal = 4
Output: 3
</pre>

<p>
Binary representation:
</p>

<pre>
start = 3 = 011
goal  = 4 = 100
</pre>

<p>
All three bits differ, so three bit flips are required.
</p>

<h3>Approach</h3>

<p>
Use the <b>XOR ( ^ )</b> operator to identify the positions where the bits
of <b>start</b> and <b>goal</b> are different.
</p>

<ul>
    <li>XOR produces <b>1</b> when two corresponding bits are different.</li>
    <li>XOR produces <b>0</b> when two corresponding bits are the same.</li>
    <li>Count the number of set bits (1s) in the XOR result.</li>
</ul>

<p>
The number of set bits gives the minimum number of bit flips required.
</p>

<h3>Complexity</h3>

<pre>
// TC: O(log(max(start, goal) + 1))
// SC: O(1)
</pre>

<h3>Key Point</h3>

<p>
<b>start ^ goal</b> identifies every bit position that needs to be flipped.
Counting the set bits in this result gives the answer.
</p>
