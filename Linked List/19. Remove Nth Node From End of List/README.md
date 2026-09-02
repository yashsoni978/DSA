<h2>Remove Nth Node From End of List</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Key Observation</h3>

<pre>
List:
1 → 2 → 3 → 4 → 5

n = 2

Remove:
        ↑
1 → 2 → 3 → 4 → 5
            ↑
           2nd from end

Result:
1 → 2 → 3 → 5
</pre>

<p>
Use the <strong>two-pointer technique</strong>. Keep the fast pointer <code>n</code>
nodes ahead of the slow pointer. When fast reaches the end, slow will be just
before the node that needs to be deleted.
</p>

<h3>Approach</h3>

<ol>
  <li>Create a dummy node before the head to handle deletion of the head easily.</li>
  <li>Set both <code>fast</code> and <code>slow</code> to the dummy node.</li>
  <li>Move <code>fast</code> forward <code>n</code> times.</li>
  <li>Move both pointers until <code>fast-&gt;next</code> becomes <code>NULL</code>.</li>
  <li>Now <code>slow-&gt;next</code> is the node to delete.</li>
  <li>Skip that node and delete it.</li>
  <li>Return <code>dummy-&gt;next</code>.</li>
</ol>

<h3>Complexity</h3>

<pre>
TC: O(n)

The list is traversed once.

SC: O(1)

Only a few pointers are used.
</pre>

<hr>

<p><strong>Pattern:</strong> Linked List / Two Pointers / Fast &amp; Slow Pointer / Dummy Node</p>

<p><strong>Key Idea:</strong> Maintain an n-node gap between fast and slow so that slow reaches the node just before the target.</p>
