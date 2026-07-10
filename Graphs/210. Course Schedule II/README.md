<h2>210. Course Schedule II</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>.</p>

<p>You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a, b]</code> indicates that you must take course <code>b</code> before course <code>a</code>.</p>

<p>Return <em>any valid ordering of courses</em> you should take to finish all courses. If it is impossible to finish all courses, return an empty array.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
numCourses = 2, prerequisites = [[1,0]]

<strong>Output:</strong>
[0,1]

<strong>Explanation:</strong>
There are only two courses to take. To take course 1 you should first take course 0.
So the correct course order is [0,1].
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]

<strong>Output:</strong>
[0,2,1,3]

<strong>Explanation:</strong>
Another valid ordering is [0,1,2,3].
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
numCourses = 1, prerequisites = []

<strong>Output:</strong>
[0]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= numCourses &lt;= 2000</code></li>
  <li><code>0 &lt;= prerequisites.length &lt;= numCourses × (numCourses - 1)</code></li>
  <li><code>prerequisites[i].length == 2</code></li>
  <li><code>0 &lt;= a, b &lt; numCourses</code></li>
  <li>All pairs <code>[a, b]</code> are distinct.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem using <strong>Topological Sort (Kahn's Algorithm)</strong> in <code>O(V + E)</code> time?</p>
