<h2>Linked List Cycle II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
Use Floyd's Cycle Detection Algorithm.

First, use slow and fast pointers to detect
whether a cycle exists.

If they meet, reset one pointer to head.
Then move both pointers one step at a time.

The point where they meet again is the starting
node of the cycle.
</pre>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>slow = head</code> and <code>fast = head</code>.</li>
  <li>Move <code>slow</code> one step and <code>fast</code> two steps.</li>
  <li>If <code>fast</code> reaches NULL, there is no cycle, so return <code>NULL</code>.</li>
  <li>When <code>slow == fast</code>, a cycle exists.</li>
  <li>Reset <code>slow = head</code>.</li>
  <li>Move both <code>slow</code> and <code>fast</code> one step at a time.</li>
  <li>When they meet again, return that node as the cycle's starting point.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Fast &amp; Slow Pointers / Floyd's Cycle Detection</p>

<p><strong>Key Idea:</strong> After the first meeting inside the cycle, resetting one pointer to head makes their next meeting occur exactly at the cycle's starting node.</p>
