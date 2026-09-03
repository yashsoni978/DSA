<h2>Cycle Length in Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
First detect the cycle using Floyd's Algorithm:
- slow moves one step
- fast moves two steps

If they meet, a cycle exists.

Once they meet, keep one pointer fixed and move
another pointer around the cycle until it reaches
the same node again. Count the number of steps.
</pre>

<h3>Approach</h3>

<ol>
  <li>Initialize <code>slow = head</code> and <code>fast = head</code>.</li>
  <li>Move <code>slow</code> one step and <code>fast</code> two steps.</li>
  <li>If <code>fast</code> reaches NULL, return <code>0</code>.</li>
  <li>When <code>slow == fast</code>, a cycle exists.</li>
  <li>Keep <code>slow</code> fixed and move another pointer one step at a time.</li>
  <li>Count the steps until it reaches <code>slow</code> again.</li>
  <li>Return the count as the cycle length.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1)
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Fast &amp; Slow Pointers / Floyd's Cycle Detection</p>

<p><strong>Key Idea:</strong> First find a meeting point inside the cycle, then traverse the cycle once to count its length.</p>
