<h2>Palindrome Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
Input:
1 → 2 → 2 → 1

First half:   1 → 2
Second half:  2 → 1

Reverse second half:
1 → 2

Compare both halves:
1 = 1
2 = 2

Therefore: Palindrome
</pre>

<p>
Use the <strong>slow and fast pointer</strong> technique to find the middle of
the list. Reverse the second half and compare it with the first half.
</p>

<h3>Approach</h3>

<ol>
  <li>Use <code>slow</code> and <code>fast</code> pointers to find the middle.</li>
  <li>Reverse the second half of the linked list.</li>
  <li>Compare nodes from the first half and reversed second half.</li>
  <li>If any values differ, return <code>false</code>.</li>
  <li>If all values match, return <code>true</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

Finding the middle, reversing, and comparing each take O(n).

SC: O(1)

Only constant extra pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Fast &amp; Slow Pointer / Reversal</p>

<p><strong>Key Idea:</strong> Find the middle, reverse the second half, then compare both halves.</p>
