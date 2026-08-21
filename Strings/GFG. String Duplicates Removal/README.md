<h2>String Duplicates Removal</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given a string <code>s</code> containing lowercase and uppercase English characters, remove all duplicate characters and return the resultant string.</p>

<p>The order of the remaining characters must be the same as their order in the original string.</p>

<h3>Example 1</h3>

<pre>
Input: s = "geEksforGEeks"

Output: "geEksforG"

Explanation: Duplicate characters such as E, e, k, and s are removed while
preserving the order of the first occurrence of each character.
</pre>

<h3>Example 2</h3>

<pre>
Input: s = "HaPpyNewYear"

Output: "HaPpyNewYr"

Explanation: Duplicate characters such as e and a are removed.
</pre>

<h3>Approach</h3>

<ul>
<li>Use a frequency/visited array of size <code>256</code> to keep track of characters that have already appeared.</li>
<li>Traverse the string from left to right.</li>
<li>For each character, check whether it has already been encountered.</li>
<li>If the character has not appeared before, add it to the result string and mark it as visited.</li>
<li>If the character has already appeared, skip it.</li>
<li>This preserves the order of the first occurrence of every character.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code> since the character set is fixed</p>

<hr>

<p><strong>Pattern:</strong> String / Hashing / Frequency Counting</p>

<p><strong>Key Idea:</strong> Traverse the string once and keep track of characters already seen. Add a character to the result only when it appears for the first time.</p>
