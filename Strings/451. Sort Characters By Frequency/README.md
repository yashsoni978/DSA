<h2>451. Sort Characters By Frequency</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code>, sort it in <strong>decreasing order</strong> based on the <strong>frequency</strong> of its characters.</p>

<p>Return the resulting string.</p>

<p>If multiple characters have the same frequency, their relative order in the output does not matter.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
s = "tree"

<strong>Output:</strong>
"eert"

<strong>Explanation:</strong>

Character frequencies are:

e → 2
r → 1
t → 1

The character 'e' appears most frequently,
so it comes first.

"eetr" is also a valid answer.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
s = "cccaaa"

<strong>Output:</strong>
"aaaccc"

<strong>Explanation:</strong>

Character frequencies are:

a → 3
c → 3

Since both have the same frequency,
either "aaaccc" or "cccaaa"
is accepted.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
s = "Aabb"

<strong>Output:</strong>
"bbAa"

<strong>Explanation:</strong>

Character frequencies are:

b → 2
A → 1
a → 1

Uppercase and lowercase letters
are treated as different characters.

"bbaA" is also a valid answer.
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ s.length ≤ 5 × 10<sup>5</sup></code></li>
  <li><code>s</code> consists of uppercase and lowercase English letters and digits.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this efficiently using a <strong>Hash Map</strong> to count character frequencies and a <strong>Max Heap</strong> (or Bucket Sort) to output characters in decreasing frequency, achieving <code>O(n log k)</code> or <code>O(n)</code> time, where <code>k</code> is the number of distinct characters?</p>
