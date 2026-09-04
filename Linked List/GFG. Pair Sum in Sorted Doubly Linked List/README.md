<h2>Pair Sum in Sorted Doubly Linked List</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Key Observation</h3>

<pre>
The DLL is sorted, so use two pointers:
- left starts at the head
- right starts at the tail

If their sum is:
- target → store the pair and move both
- less than target → move left forward
- greater than target → move right backward

Stop when left and right meet or cross.
</pre>

<h3>Approach</h3>

<ol>
  <li>Find the tail of the doubly linked list.</li>
  <li>Set <code>left = head</code> and <code>right = tail</code>.</li>
  <li>While <code>left != right</code> and <code>left</code> has not crossed <code>right</code>, calculate their sum.</li>
  <li>If the sum equals <code>target</code>, store the pair and move both pointers.</li>
  <li>If the sum is smaller, move <code>left</code> forward.</li>
  <li>If the sum is larger, move <code>right</code> backward.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

SC: O(1) auxiliary space

Output Space: O(p)
where p = number of valid pairs
</pre>

<hr>

<p><strong>Pattern:</strong> Doubly Linked List / Two Pointers / Sorted Array Technique</p>

<p><strong>Key Idea:</strong> Use the sorted order to decide which pointer to move based on whether the current sum is smaller or larger than the target.</p>
