<h2>76. Minimum Window Substring</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given two strings <code>s</code> and <code>t</code>, return the <strong>minimum window substring</strong> of <code>s</code> such that every character in <code>t</code>, including duplicate characters, is included in the window.</p>

<p>If there is no such substring, return an empty string <code>""</code>.</p>

<p>The answer is guaranteed to be unique.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "ADOBECODEBANC"
t = "ABC"

<strong>Output:</strong>
"BANC"

<strong>Explanation:</strong>
The substring "BANC" contains all characters from "ABC"
and is the shortest valid window.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "a"
t = "a"

<strong>Output:</strong>
"a"
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "a"
t = "aa"

<strong>Output:</strong>
""

<strong>Explanation:</strong>
The string "a" does not contain two 'a's, so no valid
window exists.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length, t.length ≤ 10<sup>5</sup></code></li>
  <li><code>s</code> and <code>t</code> consist of uppercase and lowercase English letters.</li>
</ul>

<p><strong>Brute Force Approach:</strong></p>

<p>Consider every possible starting position in <code>s</code>. For each starting position, expand the window until all characters of <code>t</code> are found with the required frequencies.</p>

<p>Use a frequency array to keep track of the characters still required from <code>t</code>.</p>

<p>When the window becomes valid, update the minimum length and stop expanding from that starting position.</p>

<p><strong>Brute Force Complexity:</strong></p>

<p><strong>Time Complexity:</strong> <code>O(n²)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Sliding Window</strong> technique with two pointers <code>l</code> and <code>r</code>.</p>

<p>First, store the required frequency of every character in <code>t</code>.</p>

<pre>
t = "AABC"

hash:
A → 2
B → 1
C → 1
</pre>

<p>Expand the window using <code>r</code>. Whenever <code>s[r]</code> is a required character that is still needed, increase <code>cnt</code>.</p>

<pre>
if(hash[s[r]] &gt; 0)
    cnt++;

hash[s[r]]--;
</pre>

<p>Once:</p>

<pre>
cnt == t.length()
</pre>

<p>the current window contains all required characters, so it is valid.</p>

<p>Now shrink the window from the left while it remains valid:</p>

<pre>
while(cnt == t.length()) {

    update minimum window;

    hash[s[l]]++;

    if(hash[s[l]] &gt; 0)
        cnt--;

    l++;
}
</pre>

<p>The moment removing <code>s[l]</code> makes <code>cnt</code> smaller than <code>t.length()</code>, the window becomes invalid again. Then continue expanding using <code>r</code>.</p>

<p><strong>Key Idea:</strong></p>

<p>The frequency array has two meanings:</p>

<ul>
  <li><code>hash[c] &gt; 0</code> → we still need more of character <code>c</code>.</li>
  <li><code>hash[c] ≤ 0</code> → the current window already has enough of character <code>c</code>.</li>
</ul>

<p>The variable <code>cnt</code> represents how many characters from <code>t</code> have been satisfied, including duplicates.</p>

<p>For example, if:</p>

<pre>
t = "AABC"
</pre>

<p>then we need exactly:</p>

<pre>
A → 2
B → 1
C → 1

cnt = 4
</pre>

<p>A window becomes valid when <code>cnt == 4</code>.</p>

<p><strong>Sliding Window Pattern:</strong></p>

<pre>
Expand right
     ↓
Window becomes valid
     ↓
Record answer
     ↓
Shrink left
     ↓
Window becomes invalid
     ↓
Expand right again
</pre>

<p><strong>Important:</strong> When shrinking the window, remember to increment <code>l</code>. Otherwise, the same character will be processed repeatedly and the window will never shrink.</p>

<p><strong>Time Complexity:</strong> <code>O(n + m)</code></p>

<p>Each character is added to the window once and removed from the window at most once.</p>

<p><strong>Space Complexity:</strong> <code>O(1)</code></p>

<p>The frequency array has a fixed size of 256.</p>
