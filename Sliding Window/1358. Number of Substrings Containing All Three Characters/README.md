<h2>1358. Number of Substrings Containing All Three Characters</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code> consisting only of characters <code>a</code>, <code>b</code>, and <code>c</code>, return the number of substrings that contain at least one occurrence of all three characters.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "abcabc"

<strong>Output:</strong>
10

<strong>Explanation:</strong>
There are 10 substrings containing at least one
'a', one 'b', and one 'c'.
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Generate every substring and check whether it contains <code>a</code>, <code>b</code>, and <code>c</code>.</p>

<p>This takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique.</p>

<ol>
  <li>Expand the window using <code>right</code>.</li>
  <li>Track the frequency of <code>a</code>, <code>b</code>, and <code>c</code>.</li>
  <li>When the window contains all three characters, count all valid substrings ending at <code>right</code>.</li>
  <li>Move <code>left</code> forward to find other valid windows.</li>
</ol>

<p><strong>Key Observation:</strong></p>

<p>When the current window <code>[left, right]</code> contains all three characters, every substring starting from <code>0</code> to <code>left</code> and ending at <code>right</code> is also valid.</p>

<pre>
Number of valid substrings = left + 1
</pre>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>
