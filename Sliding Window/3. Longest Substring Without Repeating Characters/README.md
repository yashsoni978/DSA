<h2>3. Longest Substring Without Repeating Characters</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code>, find the length of the <strong>longest substring</strong> without repeating characters.</p>

<p>A <strong>substring</strong> is a contiguous sequence of characters within a string.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "abcabcbb"

<strong>Output:</strong>
3

<strong>Explanation:</strong>
The answer is "abc", with a length of 3.
Other valid substrings include "bca" and "cab".
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "bbbbb"

<strong>Output:</strong>
1

<strong>Explanation:</strong>
The answer is "b", with a length of 1.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "pwwkew"

<strong>Output:</strong>
3

<strong>Explanation:</strong>
The answer is "wke", with a length of 3.
Note that "pwke" is a subsequence, not a substring.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>0 ≤ s.length ≤ 5 × 10<sup>4</sup></code>.</li>
  <li><code>s</code> consists of English letters, digits, symbols and spaces.</li>
</ul>

<p><strong>Brute Force Approach:</strong></p>

<p>Start a substring from every possible index. For each starting position, keep adding characters until a duplicate character is found.</p>

<p>Use a hash map to store the frequency of characters in the current substring.</p>

<pre>
for every starting index i:

    create a frequency map

    for j = i to n-1:

        add s[j] to the map

        if s[j] is repeated:
            break

        update maximum length
</pre>

<p><strong>Example:</strong></p>

<pre>
s = "abcabcbb"

Starting from index 0:

a → unique
ab → unique
abc → unique
abca → duplicate 'a'

Maximum length = 3
</pre>

<p><strong>Optimal Approach:</strong></p>

<p>The brute-force approach can be optimized using the <strong>Sliding Window</strong> technique.</p>

<p>Maintain two pointers <code>left</code> and <code>right</code> representing the current window. Expand the window using <code>right</code>. When a duplicate character appears, move <code>left</code> forward until the window again contains only unique characters.</p>

<p>A hash map can store the most recent index of every character.</p>

<pre>
right moves → expand window

if character is repeated:
    move left to the position after
    the previous occurrence

update:
maxLen = max(maxLen, right - left + 1)
</pre>

<p><strong>Important:</strong> A substring must be <strong>contiguous</strong>. You cannot skip characters while forming the substring.</p>

<p><strong>Brute Force Complexity:</strong></p>

<p><strong>Time Complexity:</strong> <code>O(n²)</code></p>

<p><strong>Space Complexity:</strong> <code>O(min(n, charset))</code></p>

<p><strong>Optimal Complexity:</strong></p>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(min(n, charset))</code></p>
