<h2>72. Edit Distance</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given two strings <code>word1</code> and <code>word2</code>, return the <strong>minimum number of operations</strong> required to convert <code>word1</code> into <code>word2</code>.</p>

<p>You are allowed to perform the following operations:</p>

<ul>
  <li>Insert a character.</li>
  <li>Delete a character.</li>
  <li>Replace a character.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
word1 = "horse"
word2 = "ros"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

horse → rorse   (replace 'h' with 'r')
rorse → rose    (delete 'r')
rose → ros      (delete 'e')

Minimum operations = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
word1 = "intention"
word2 = "execution"

<strong>Output:</strong>
5

<strong>Explanation:</strong>

One optimal sequence is:

intention → inention     (delete 't')
inention → enention      (replace 'i' with 'e')
enention → exention      (replace 'n' with 'x')
exention → exection      (replace 'n' with 'c')
exection → execution     (insert 'u')

Minimum operations = 5
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ word1.length, word2.length ≤ 500</code></li>
  <li><code>word1</code> and <code>word2</code> consist of lowercase English letters.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Dynamic Programming</strong> in <code>O(n × m)</code> time and optimize the space complexity from <code>O(n × m)</code> to <code>O(m)</code> using rolling arrays?</p>
