<h2>455. Assign Cookies</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>You are given two integer arrays <code>g</code> and <code>s</code>.</p>

<p><code>g[i]</code> represents the greed factor of a child, and <code>s[j]</code> represents the size of a cookie.</p>

<p>A child can be satisfied if the cookie size is at least their greed factor. Return the maximum number of satisfied children.</p>

<p><strong>Example:</strong></p>

<pre>
<strong>Input:</strong>
g = [1,2,3]
s = [1,1]

<strong>Output:</strong>
1

<strong>Explanation:</strong>
Only the child with greed factor 1 can be satisfied.
</pre>

<p><strong>Brute Force Approach:</strong></p>

<p>For every child, search for a cookie that can satisfy them.</p>

<p>This can take <code>O(n × m)</code> time.</p>

<p><strong>Optimal Approach:</strong></p>

<p>Use the <strong>Greedy + Two Pointer</strong> technique.</p>

<ol>
  <li>Sort both arrays.</li>
  <li>Use one pointer for children and one for cookies.</li>
  <li>If the current cookie can satisfy the current child, assign it and move both pointers.</li>
  <li>Otherwise, the cookie is too small, so move to the next cookie.</li>
</ol>

<p><strong>Key Observation:</strong></p>

<p>Always give the <strong>smallest cookie that can satisfy the least greedy child</strong>. This preserves larger cookies for children with higher greed factors.</p>

<p><strong>Time Complexity:</strong> <code>O(n log n + m log m)</code></p>

<p><strong>Space Complexity:</strong> <code>O(1)</code> (excluding sorting space)</p>
