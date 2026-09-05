<h2>Longest Substring with K Uniques</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code> containing lowercase alphabets and an integer <code>k</code>, find the length of the longest substring that contains exactly <code>k</code> distinct characters.</p>

<p>If no such substring exists, return <code>-1</code>.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
s = "aabacbebebe"
k = 3

<strong>Output:</strong>
7

<strong>Explanation:</strong>
The longest substring is:

"cbebebe"

It contains exactly 3 distinct characters: c, b, e.
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>Check every substring and count its distinct characters. If the count is exactly <code>k</code>, update the maximum length.</p>

<p>This takes <code>O(n²)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique with a frequency map.</p>

<ol>
  <li>Expand the window using <code>right</code>.</li>
  <li>Store character frequencies in a map.</li>
  <li>If distinct characters exceed <code>k</code>, move <code>left</code> forward.</li>
  <li>When the window contains exactly <code>k</code> distinct characters, update the maximum length.</li>
</ol>

<p><strong>Key Observation:</strong></p>

<p>Maintain a window with <strong>at most k distinct characters</strong>. Whenever the window has exactly <code>k</code>, it is a valid candidate.</p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(k)</code></p>
