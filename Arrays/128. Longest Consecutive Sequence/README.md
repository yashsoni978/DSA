<h2>128. Longest Consecutive Sequence</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an unsorted array of integers <code>nums</code>, return the length of the
longest consecutive elements sequence.
</p>

<p>
The algorithm must run in <b>O(N)</b> time.
</p>

<h3>Example</h3>

<pre>
Input:
nums = [100,4,200,1,3,2]

Output:
4
</pre>

<p>
The longest consecutive sequence is:
</p>

<pre>
[1,2,3,4]
</pre>

<p>
Therefore, the answer is <code>4</code>.
</p>

<h3>Approach</h3>

<p>
We use an <b>Unordered Set</b> to achieve average <code>O(1)</code> lookup time.
</p>

<ol>
<li>Insert all elements into an unordered set.</li>
<li>Traverse every number in the set.</li>
<li>Check whether <code>num - 1</code> exists.</li>
<li>If <code>num - 1</code> does not exist, <code>num</code> is the beginning of a consecutive sequence.</li>
<li>Starting from <code>num</code>, keep checking <code>num + 1</code>, <code>num + 2</code>, etc.</li>
<li>Update the maximum sequence length.</li>
</ol>

<h3>Why Check <code>num - 1</code>?</h3>

<p>
We only start counting from the first element of a sequence.
</p>

<pre>
nums = [1,2,3,4]

For 1:
0 does not exist → start sequence

1 → 2 → 3 → 4
</pre>

<p>
For <code>2</code>, <code>1</code> already exists, so we don't start another
sequence from <code>2</code>. This prevents unnecessary work.
</p>

<h3>Example</h3>

<pre>
nums = [100,4,200,1,3,2]

Set = {100,4,200,1,3,2}

Starting points:

100 → 99 doesn't exist → length = 1

4 → 3 exists → skip

200 → 199 doesn't exist → length = 1

1 → 0 doesn't exist
1 → 2 → 3 → 4
length = 4

3 → 2 exists → skip

2 → 1 exists → skip

Answer = 4
</pre>

<h3>Why Is the Complexity O(N)?</h3>

<p>
Although there is a nested <code>while</code> loop, each number belongs to a
consecutive sequence and is processed only when necessary.
We start expanding only from the beginning of a sequence.
</p>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N) average
Space Complexity: O(N)
</pre>

<p>
The unordered set stores all <code>N</code> elements, while each element is
looked up in average <code>O(1)</code> time.
</p>
