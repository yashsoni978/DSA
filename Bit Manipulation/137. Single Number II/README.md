<h2>137. Single Number II</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given an integer array <b>nums</b>, every element appears exactly three times
except for one element, which appears exactly once.
Find and return the element that appears only once.
</p>

<p>
You must solve the problem with linear runtime complexity and use constant
extra space.
</p>

<h3>Example 1</h3>

<pre>
Input: nums = [2,2,3,2]
Output: 3
</pre>

<p>
The number 2 appears three times, while 3 appears only once.
Therefore, the answer is 3.
</p>

<h3>Example 2</h3>

<pre>
Input: nums = [0,1,0,1,0,1,99]
Output: 99
</pre>

<p>
The numbers 0 and 1 appear three times each, while 99 appears only once.
Therefore, the answer is 99.
</p>

<h3>Approach</h3>

<p>
Use <b>bit manipulation</b> to count the set bits at each bit position.
</p>

<ul>
    <li>Traverse all the numbers and examine each of the 32 bit positions.</li>
    <li>Count how many numbers have a set bit (1) at each position.</li>
    <li>Take the count modulo 3, because bits contributed by numbers appearing three times cancel out modulo 3.</li>
    <li>If the remainder is 1, set that bit in the answer.</li>
</ul>

<p>
After processing all bit positions, the resulting integer is the number
that appears only once.
</p>

<h3>Complexity</h3>

<pre>
// TC: O(32 * N) = O(N)
// SC: O(1)
</pre>

<p>
N = number of elements in the array. Since the integer size is fixed at
32 bits, the algorithm uses constant extra space.
</p>

<h3>Key Point</h3>

<p>
For every bit position, the total number of set bits contributed by
elements appearing three times is a multiple of 3. Taking the count
modulo 3 leaves the corresponding bit of the unique element.
</p>
