<h2>424. Longest Repeating Character Replacement</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given a string <code>s</code> consisting of uppercase English letters and an integer <code>k</code>.</p>

<p>You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most <code>k</code> times.</p>

<p>Return the length of the <strong>longest substring</strong> containing the same letter after performing at most <code>k</code> replacements.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "ABAB"
k = 2

<strong>Output:</strong>
4

<strong>Explanation:</strong>
Replace the two 'B's with 'A's:

"AAAA"

The longest substring has length 4.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "AABABBA"
k = 1

<strong>Output:</strong>
4

<strong>Explanation:</strong>
Replace the 'B' at index 2 with 'A':

"AAAABBA"

The longest valid substring is "AABA" or "ABBA",
which has length 4.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 10<sup>5</sup></li>
  <li><code>s</code> consists of only uppercase English letters.</li>
  <li><code>0 ≤ k ≤ s.length</code></li>
</ul>

<p><strong>Brute Force Approach:</strong></p>

<p>Consider every possible substring and count the frequency of each character. For a particular substring, let <code>maxFreq</code> be the frequency of the most common character.</p>

<p>To make the entire substring consist of the same character, we need to replace all other characters:</p>

<pre>
replacements = windowLength - maxFreq
</pre>

<p>If:</p>

<pre>
windowLength - maxFreq ≤ k
</pre>

<p>then the substring can be converted into a string containing only one character.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique.</p>

<p>Maintain a window from <code>left</code> to <code>right</code> and a frequency array for the characters inside the window.</p>

<p>For every window, keep track of the frequency of the most common character:</p>

<pre>
maxFreq = maximum frequency of any character in the window
</pre>

<p>The number of replacements required is:</p>

<pre>
windowLength - maxFreq
</pre>

<p>If this value becomes greater than <code>k</code>, the current window is invalid, so move <code>left</code> forward until it becomes valid again.</p>

<p>For every valid window, update the maximum length.</p>

<p><strong>Example:</strong></p>

<pre>
s = "AABABBA"
k = 1

Window: "AABA"

A = 3
B = 1

windowLength = 4
maxFreq = 3

replacements = 4 - 3 = 1

Since 1 ≤ k, this window is valid.

Answer = 4
</pre>

<p><strong>Key Observation:</strong></p>

<p>We only need to change the characters that are <strong>not</strong> the most frequent character in the current window.</p>

<pre>
Required replacements =
window size - frequency of most frequent character
</pre>

<p>Therefore, the sliding window condition is:</p>

<pre>
window size - maxFreq ≤ k
</pre>

<p><strong>Time Complexity:</strong> <code>O(n)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>

<p>Since there are only 26 uppercase English letters, the frequency array always uses constant space.</p>
