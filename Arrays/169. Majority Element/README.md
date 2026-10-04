<h2>169. Majority Element</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>
Given an array <code>nums</code> of size <code>n</code>, return the element
that appears more than <code>⌊n / 2⌋</code> times.
</p>

<p>
You may assume that the majority element always exists in the array.
</p>

<h3>Example</h3>

<pre>
Input:
nums = [2,2,1,1,1,2,2]

Output:
2
</pre>

<h3>Explanation</h3>

<p>
The element <code>2</code> appears <code>4</code> times, while
<code>⌊7/2⌋ = 3</code>.
Therefore, <code>2</code> is the majority element.
</p>

<h3>Approach</h3>

<p>
We use <b>Boyer-Moore Voting Algorithm</b>.
</p>

<p>
The main idea is to maintain a <b>candidate</b> and a <b>count</b>.
Whenever the current element is the same as the candidate, increase
the count. Otherwise, decrease the count.
</p>

<ol>
<li>Initialize <code>candidate = 0</code> and <code>count = 0</code>.</li>
<li>Traverse the array.</li>
<li>If <code>count == 0</code>, make the current element the candidate.</li>
<li>If the current element equals the candidate, increase <code>count</code>.</li>
<li>Otherwise, decrease <code>count</code>.</li>
<li>Return the candidate.</li>
</ol>

<h3>Intuition</h3>

<p>
Think of the majority element as having more votes than all other elements
combined. Whenever we encounter a different element, we cancel one vote of
the candidate against that different element.
</p>

<p>
Since the majority element occurs more than half of the array, it cannot be
completely cancelled. Therefore, it remains as the final candidate.
</p>

<h3>Example</h3>

<pre>
nums = [2,2,1,1,1,2,2]

Candidate   Count
2             1
2             2
1             1
1             0
1             1
2             0
2             1

Answer = 2
</pre>

<h3>Why It Works</h3>

<p>
Every time a different element is encountered, one occurrence of the current
candidate is cancelled. Since the majority element appears more than
<code>n/2</code> times, it will have occurrences left after all possible
cancellations.
</p>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N)
Space Complexity: O(1)
</pre>

<p>
The array is traversed only once and no extra data structure is required.
</p>
