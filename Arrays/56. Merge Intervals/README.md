<h2>56. Merge Intervals</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an array of intervals where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code>,
merge all overlapping intervals and return an array of the non-overlapping intervals.
</p>

<h3>Example</h3>

<pre>
Input:
intervals = [[1,3],[2,6],[8,10],[15,18]]

Output:
[[1,6],[8,10],[15,18]]
</pre>

<h3>Explanation</h3>

<p>
The intervals <code>[1,3]</code> and <code>[2,6]</code> overlap, so they are merged into
<code>[1,6]</code>.
</p>

<p>
The intervals <code>[8,10]</code> and <code>[15,18]</code> do not overlap with any other
intervals, so they remain unchanged.
</p>

<h3>Approach</h3>

<ol>
<li>Sort all intervals based on their starting point.</li>
<li>Maintain an answer array <code>ans</code>.</li>
<li>For each interval:
    <ul>
        <li>If <code>ans</code> is empty or the current interval starts after the last interval ends, add it.</li>
        <li>Otherwise, the intervals overlap, so update the ending point using <code>max()</code>.</li>
    </ul>
</li>
<li>Return the merged intervals.</li>
</ol>

<h3>Key Condition</h3>

<pre>
If current_start &gt; last_end:
    No overlap

Otherwise:
    Overlap → Merge
</pre>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N log N)
Space Complexity: O(N)
</pre>

<p>
The <code>O(N log N)</code> time comes from sorting the intervals. The merging process itself
takes <code>O(N)</code>.
</p>
