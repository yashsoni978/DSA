<h2>260. Single Number III</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given an integer array <b>nums</b>, in which exactly two elements appear
only once and all the other elements appear exactly twice, find the two
elements that appear only once.
</p>

<p>
You must solve the problem in linear runtime complexity and use only
constant extra space.
</p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
</pre>

<p>
The numbers 1 and 2 appear twice, while 3 and 5 appear only once.
Therefore, the answer is [3,5].
</p>

<h3>Example 2</h3>

<pre>
Input: nums = [-1,0]
Output: [-1,0]
</pre>

<p>
Both elements appear only once, so the answer is [-1,0].
</p>

<h3>Example 3</h3>

<pre>
Input: nums = [0,1]
Output: [1,0]
</pre>

<p>
Both elements appear only once. The answer can be returned in any order.
</p>

<h3>Approach</h3>

<p>
Use <b>Bit Manipulation</b> and the XOR operator.
</p>

<ol>
    <li>
        XOR all elements of the array. Since equal numbers cancel each other
        out, the result is the XOR of the two unique numbers.
    </li>
    <li>
        Find any set bit (1) in this XOR result. This bit must be different
        between the two unique numbers.
    </li>
    <li>
        Divide the elements into two groups based on that bit: one group
        contains numbers where the bit is set, and the other contains
        numbers where it is not set.
    </li>
    <li>
        XOR the numbers within each group separately. Duplicate numbers cancel
        out, leaving one unique number in each group.
    </li>
    <li>
        Return the two unique numbers.
    </li>
</ol>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1), excluding the output
</pre>

<h3>Key Point</h3>

<p>
The XOR of all elements gives the XOR of the two unique numbers.
A set bit in this result helps separate those numbers into different groups,
allowing us to recover both unique elements independently.
</p>
