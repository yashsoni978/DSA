<h2>152. Maximum Product Subarray</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an integer array <code>nums</code>, find a contiguous subarray that has the largest product and return its product.</p>

<p><strong>Example 1:</strong></p>
<pre>
<strong>Input:</strong>
nums = [2,3,-2,4]

<strong>Output:</strong>
6

<strong>Explanation:</strong>
The subarray [2,3] has the largest product:
2 × 3 = 6 </pre>

<p><strong>Example 2:</strong></p>
<pre>
<strong>Input:</strong>
nums = [-2,0,-1]

<strong>Output:</strong>
0 </pre>

<p><strong>Approach:</strong></p>

<p>Maintain two values while traversing the array:</p>

<ul>
<li><code>maxProduct</code> → maximum product ending at the current position.</li>
<li><code>minProduct</code> → minimum product ending at the current position.</li>
</ul>

<p>We need both maximum and minimum because multiplying a negative number by the minimum negative product can produce a new maximum positive product.</p>

<p>For every element, calculate the maximum and minimum possible products by considering:</p>

<ul>
<li>The current element itself.</li>
<li>Current element × previous maximum product.</li>
<li>Current element × previous minimum product.</li>
</ul>

<p>If the current element is negative, the maximum and minimum values effectively switch roles, so we must preserve the previous values before updating them.</p>

<p><strong>Key Observation:</strong></p>

<p>A negative number can turn the smallest negative product into the largest positive product. Therefore, tracking only the maximum product is not enough.</p>

<p>For example:</p>

<pre>
nums = [-2, 3, -4]

(-2) × 3 × (-4) = 24
</pre>

<p>The negative value <code>-2</code> creates a negative product, but multiplying it later by another negative number produces the maximum positive product.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
