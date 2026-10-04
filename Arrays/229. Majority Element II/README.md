<h2>229. Majority Element II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an integer array <code>nums</code> of size <code>n</code>, return all elements
that appear more than <code>⌊n / 3⌋</code> times.
</p>

<p>
The answer can contain at most <b>2 elements</b>.
</p>

<h3>Example</h3>

<pre>
Input:
nums = [3,2,3]

Output:
[3]
</pre>

<h3>Another Example</h3>

<pre>
Input:
nums = [1,1,1,3,3,2,2,2]

Output:
[1,2]
</pre>

<h3>Approach</h3>

<p>
We use the <b>Extended Boyer-Moore Voting Algorithm</b>.
</p>

<p>
For the condition <code>n / 3</code>, there can be at most <b>2 majority
elements</b>. Therefore, we maintain two candidates and their counts.
</p>

<ol>
<li>Maintain two candidates: <code>candidate1</code> and <code>candidate2</code>.</li>
<li>Maintain their counts: <code>count1</code> and <code>count2</code>.</li>
<li>Traverse the array and update the candidates and counts.</li>
<li>After finding the candidates, perform a second pass to count their actual frequencies.</li>
<li>Add a candidate to the answer if its frequency is greater than <code>n / 3</code>.</li>
</ol>

<h3>Why At Most 2 Elements?</h3>

<p>
Suppose there were 3 different elements appearing more than <code>n / 3</code>
times.
Their total frequency would be greater than <code>n</code>, which is impossible.
</p>

<pre>
Maximum number of majority elements = 2
</pre>

<h3>Voting Logic</h3>

<pre>
if nums[i] == candidate1:
    count1++

else if nums[i] == candidate2:
    count2++

else if count1 == 0:
    candidate1 = nums[i]
    count1 = 1

else if count2 == 0:
    candidate2 = nums[i]
    count2 = 1

else:
    count1--
    count2--
</pre>

<p>
When the current element matches a candidate, its vote increases.
If it matches neither candidate and both candidates have votes, we cancel
one vote from both candidates.
</p>

<h3>Important: Verification</h3>

<p>
Unlike the normal Majority Element problem, the candidates obtained from
the voting process are not automatically guaranteed to satisfy the
<code>n / 3</code> condition.
</p>

<p>
Therefore, we must count their actual occurrences in a second pass.
</p>

<h3>Example</h3>

<pre>
nums = [1,1,1,3,3,2,2,2]

n = 8
n / 3 = 2

1 appears 3 times → valid
2 appears 3 times → valid
3 appears 2 times → not valid

Answer:
[1,2]
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N)
Space Complexity: O(1)
</pre>

<p>
We make two linear passes through the array and use only a constant amount
of extra space.
</p>
