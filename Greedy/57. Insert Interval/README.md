<h2>57. Insert Interval</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an array of non-overlapping intervals <code>intervals</code> where <code>intervals[i] = [start<sub>i</sub>, end<sub>i</sub>]</code> represent the start and end of the interval.</p>

<p>The intervals are sorted in ascending order by their start time. You are also given a new interval <code>newInterval = [start, end]</code>.</p>

<p>Insert <code>newInterval</code> into <code>intervals</code> so that the intervals remain sorted and non-overlapping. Merge overlapping intervals if necessary.</p>

<h3>Example 1</h3>

<pre>
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]

Output: [[1,5],[6,9]]
</pre>

<h3>Example 2</h3>

<pre>
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]

Output: [[1,2],[3,10],[12,16]]
</pre>

<h3>Approach</h3>

<ul>
<li>Traverse all intervals and divide them into three categories.</li>
<li>First, add all intervals that end before <code>newInterval</code> starts. These intervals do not overlap with the new interval.</li>
<li>Next, merge all intervals that overlap with <code>newInterval</code> by updating the start and end boundaries.</li>
<li>Finally, add <code>newInterval</code> after all overlapping intervals have been merged.</li>
<li>Then add all remaining intervals that start after the merged interval ends.</li>
</ul>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(n)</code> for the output array</p>

<hr>

<p><strong>Pattern:</strong> Array / Intervals / Merging Intervals</p>

<p><strong>Key Idea:</strong> Add intervals before the new interval, merge all overlapping intervals into one, then add the remaining intervals.</p>
