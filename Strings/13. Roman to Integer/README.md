<h2>13. Roman to Integer</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-brightgreen" alt="Difficulty: Easy"/>

<hr>

<p>Roman numerals are represented by seven different symbols:</p>

<ul>
  <li><code>I</code> → 1</li>
  <li><code>V</code> → 5</li>
  <li><code>X</code> → 10</li>
  <li><code>L</code> → 50</li>
  <li><code>C</code> → 100</li>
  <li><code>D</code> → 500</li>
  <li><code>M</code> → 1000</li>
</ul>

<p>Given a Roman numeral <code>s</code>, convert it to an integer.</p>

<p>Roman numerals are usually written from largest to smallest from left to right. However, in the following cases, subtraction is used:</p>

<ul>
  <li><code>I</code> can be placed before <code>V</code> and <code>X</code> to make 4 and 9.</li>
  <li><code>X</code> can be placed before <code>L</code> and <code>C</code> to make 40 and 90.</li>
  <li><code>C</code> can be placed before <code>D</code> and <code>M</code> to make 400 and 900.</li>
</ul>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "III"

<strong>Output:</strong>
3

<strong>Explanation:</strong>

I + I + I = 3
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "LVIII"

<strong>Output:</strong>
58

<strong>Explanation:</strong>

L = 50
V = 5
III = 3

50 + 5 + 3 = 58
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "MCMXCIV"

<strong>Output:</strong>
1994

<strong>Explanation:</strong>

M = 1000
CM = 900
XC = 90
IV = 4

1000 + 900 + 90 + 4 = 1994
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 15</code></li>
  <li><code>s</code> contains only the characters <code>'I'</code>, <code>'V'</code>, <code>'X'</code>, <code>'L'</code>, <code>'C'</code>, <code>'D'</code>, and <code>'M'</code>.</li>
  <li>It is guaranteed that <code>s</code> is a valid Roman numeral in the range <code>[1, 3999]</code>.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this in a single pass by comparing each Roman numeral with the next one, subtracting its value if it is smaller than the next numeral and adding it otherwise, achieving <code>O(n)</code> time and <code>O(1)</code> extra space?</p>
