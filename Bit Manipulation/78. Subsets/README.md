<h2>78. Subsets</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given an integer array <b>nums</b> of unique elements, return all possible
subsets (the power set).
</p>

<p>
The solution set must not contain duplicate subsets. Return the subsets
in any order.
</p>

<h3>Example 1</h3>

<pre>
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
</pre>

<p>
All possible subsets, including the empty subset and the original array,
are included.
</p>

<h3>Example 2</h3>

<pre>
Input: nums = [0]
Output: [[],[0]]
</pre>

<p>
An array containing one element has two possible subsets: the empty subset
and the subset containing that element.
</p>

<h3>Approach</h3>

<p>
Use <b>Backtracking</b> to generate all possible subsets.
For each element, make two choices:
</p>

<ul>
    <li><b>Include:</b> Add the current element to the subset.</li>
    <li><b>Exclude:</b> Skip the current element.</li>
</ul>

<p>
Continue making these choices for every element. Whenever all elements
have been considered, add the current subset to the result.
</p>

<p>
Since each of the <b>N</b> elements has two choices, the total number
of subsets is <b>2<sup>N</sup></b>.
</p>

<h3>Complexity</h3>

<pre>
// TC: O(N * 2^N)
// SC: O(N) auxiliary space, excluding the output
</pre>

<h3>Key Point</h3>

<p>
An array of <b>N</b> distinct elements has exactly <b>2<sup>N</sup></b>
subsets. Backtracking explores the include-or-exclude choices for every
element to generate them all.
</p>
