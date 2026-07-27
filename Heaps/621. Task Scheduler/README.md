<h2>621. Task Scheduler</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>You are given an array of CPU tasks <code>tasks</code>, where each task is represented by a capital English letter, and a non-negative integer <code>n</code> representing the cooling time.</p>

<p>Each CPU interval can complete <strong>one task</strong> or remain <strong>idle</strong>.</p>

<p>Two identical tasks must be separated by at least <code>n</code> intervals.</p>

<p>Return the <strong>least number of CPU intervals</strong> required to complete all the given tasks.</p>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>
tasks = ["A","A","A","B","B","B"]
n = 2

<strong>Output:</strong>
8

<strong>Explanation:</strong>

One optimal schedule is:

A → B → idle → A → B → idle → A → B

Total intervals = 8
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>
tasks = ["A","C","A","B","D","B"]
n = 1

<strong>Output:</strong>
6

<strong>Explanation:</strong>

One possible schedule is:

A → B → C → D → A → B

No idle intervals are required.
</pre>

<p><strong>Example 3:</strong></p>

<pre>
<strong>Input:</strong>
tasks = ["A","A","A","B","B","B"]
n = 3

<strong>Output:</strong>
10

<strong>Explanation:</strong>

One optimal schedule is:

A → B → idle → idle → A → B → idle → idle → A → B

Total intervals = 10
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ tasks.length ≤ 10<sup>4</sup></code></li>
  <li><code>tasks[i]</code> is an uppercase English letter.</li>
  <li><code>0 ≤ n ≤ 100</code></li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem by counting task frequencies and using either a <strong>Greedy Math approach</strong> or a <strong>Max Heap</strong>, achieving <code>O(n)</code> or <code>O(n log 26)</code> time complexity?</p>
