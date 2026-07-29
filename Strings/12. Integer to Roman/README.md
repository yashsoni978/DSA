<h2>12. Integer to Roman</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

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

<p>Roman numerals are usually formed by appending the largest possible values from left to right, with the following subtractive combinations:</p>

<ul>
  <li><code>IV</code> → 4</li>
  <li><code>IX</code> → 9</li>
  <li><code>XL</code> → 40</li>
  <li><code>XC</code> → 90</li>
  <li><code>CD</code> → 400</li>
  <li><code>CM</code> → 900</li>
</ul>

<p>Given an integer, convert it to its Roman numeral representation.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
num = 3749

<strong>Output:</strong>
"MMMDCCXLIX"

<strong>Explanation:</strong>

3000 → MMM
700  → DCC
40   → XL
9    → IX

Result = MMMDCCXLIX
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
num = 58

<strong>Output:</strong>
"LVIII"

<strong>Explanation:</strong>

50 → L
5  → V
3  → III

Result = LVIII
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
num = 1994

<strong>Output:</strong>
"MCMXCIV"

<strong>Explanation:</strong>

1000 → M
900  → CM
90   → XC
4    → IV

Result = MCMXCIV
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ num ≤ 3999</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this greedily by maintaining ordered arrays of Roman values and symbols, repeatedly taking the largest value that does not exceed the remaining number, achieving <code>O(1)</code> time (since there are only 13 Roman symbols/combinations) and <code>O(1)</code> extra space?</p>
