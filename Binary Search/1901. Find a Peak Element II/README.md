<h2>1901. Find a Peak Element II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an <code>m × n</code> matrix where adjacent cells are different, find any <strong>peak element</strong>.</p>

<p>A cell is a peak if it is strictly greater than its <strong>up, down, left, and right</strong> neighbors.</p>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Rows</strong>.</li>
<li>For the middle row, find the column containing the <strong>maximum element</strong>.</li>
<li>Compare this element with the element directly <strong>above</strong> and <strong>below</strong> it.</li>
<li>If it is greater than both, it is a peak because it is already the maximum element in its row, so it is also greater than its left and right neighbors.</li>
<li>If the element below is greater, search the <strong>lower half</strong> of the rows.</li>
<li>Otherwise, search the <strong>upper half</strong>.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>For every middle row, choosing its maximum element eliminates the need to check the entire row.</p>

<pre>
             middle row
                  ↓
        [ find maximum element ]
                  ↓
       compare ↑ current ↓
             /       \
        upper        lower
        half         half
</pre>

<p>If a neighboring row has a larger value, a peak must exist in that direction. Otherwise, the current maximum is a peak.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log m)</code> if binary searching across rows and scanning each row for its maximum, where <code>n</code> is the number of rows and <code>m</code> is the number of columns.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / 2D Binary Search / Peak Element</p>

<p><strong>Key Idea:</strong> Binary search on rows. For each middle row, find its maximum element and compare it with the elements above and below. Move toward the larger neighbor until a peak is found.</p>
