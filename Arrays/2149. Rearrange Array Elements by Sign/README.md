<h2>2149. Rearrange Array Elements by Sign</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an integer array <code>nums</code> containing an equal number of positive
and negative integers, rearrange the elements such that every consecutive pair
has opposite signs.
</p>

<p>
The relative order of the positive and negative numbers should be preserved.
The array should start with a positive integer.
</p>

<h3>Example</h3>

<pre>
Input:
nums = [3,1,-2,-5,2,-4]

Output:
[3,-2,1,-5,2,-4]
</pre>

<h3>Explanation</h3>

<p>
The positive numbers are:
</p>

<pre>
[3,1,2]
</pre>

<p>
The negative numbers are:
</p>

<pre>
[-2,-5,-4]
</pre>

<p>
We place one positive and one negative alternately:
</p>

<pre>
3, -2, 1, -5, 2, -4
</pre>

<h3>Approach</h3>

<p>
We use two separate arrays to store positive and negative numbers.
</p>

<ol>
<li>Traverse the input array.</li>
<li>Store positive numbers in the <code>positive</code> array.</li>
<li>Store negative numbers in the <code>negative</code> array.</li>
<li>Use two indices to place them alternately into the answer.</li>
<li>Place positive numbers at even indices and negative numbers at odd indices.</li>
</ol>

<h3>Index Pattern</h3>

<pre>
Positive → 0, 2, 4, 6, ...
Negative → 1, 3, 5, 7, ...
</pre>

<p>
Since the problem guarantees an equal number of positive and negative
elements, we can safely alternate them.
</p>

<h3>Important Point</h3>

<p>
We preserve the original relative order of both positive and negative numbers.
For example:
</p>

<pre>
Input positives:
[3, 1, 2]

Output positives:
[3, 1, 2]
</pre>

<p>
Similarly:
</p>

<pre>
Input negatives:
[-2, -5, -4]

Output negatives:
[-2, -5, -4]
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N)
Space Complexity: O(N)
</pre>

<p>
We traverse the array once and use additional arrays to store the positive and
negative elements.
</p>
