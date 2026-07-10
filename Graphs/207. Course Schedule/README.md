<h2>207. Course Schedule</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>There are a total of <code>numCourses</code> courses you have to take, labeled from <code>0</code> to <code>numCourses - 1</code>.</p>

<p>You are given an array <code>prerequisites</code> where <code>prerequisites[i] = [a, b]</code> indicates that you must take course <code>b</code> before course <code>a</code>.</p>

<ul>
  <li>For example, the pair <code>[0,1]</code> indicates that to take course <code>0</code> you must first take course <code>1</code>.</li>
</ul>

<p>Return <code>true</code> if you can finish all courses. Otherwise, return <code>false</code>.</p>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
numCourses = 2, prerequisites = [[1,0]]

<strong>Output:</strong>
true

<strong>Explanation:</strong>
Take course 0 first and then course 1.
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
numCourses = 2, prerequisites = [[1,0],[0,1]]

<strong>Output:</strong>
false

<strong>Explanation:</strong>
There is a cycle between courses 0 and 1, making it impossible to finish all courses.
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 &lt;= numCourses &lt;= 2000</code></li>
  <li><code>0 &lt;= prerequisites.length &lt;= 5000</code></li>
  <li><code>prerequisites[i].length == 2</code></li>
  <li><code>0 &lt;= a, b &lt; numCourses</code></li>
  <li>All pairs <code>[a, b]</code> are unique.</li>
</ul>

<p><strong>Follow-up:</strong> Can you determine whether all courses can be completed using <strong>Topological Sort (Kahn's Algorithm)</strong> or <strong>DFS Cycle Detection</strong>?</p>
