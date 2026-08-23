<h2>1011. Capacity To Ship Packages Within D Days</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>weights</code> where <code>weights[i]</code> represents the weight of the <code>i-th</code> package, and an integer <code>days</code>, find the <strong>minimum ship capacity</strong> required to ship all packages within <code>days</code> days.</p>

<p>Packages must be shipped in the given order, and a package cannot be split across multiple days.</p>

<h3>Example 1</h3>

<pre>
Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5

Output: 15
</pre>

<h3>Example 2</h3>

<pre>
Input: weights = [3,2,2,4,1,4], days = 3

Output: 6
</pre>

<h3>Example 3</h3>

<pre>
Input: weights = [1,2,3,1,1], days = 4

Output: 3
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible capacity is <code>max(weights)</code>, because the ship must be able to carry the heaviest package.</li>
<li>The maximum possible capacity is <code>sum(weights)</code>, because then all packages can be shipped in one day.</li>
<li>For a candidate capacity, simulate the shipping process and count how many days are required.</li>
<li>Add packages to the current day while their total weight does not exceed the capacity.</li>
<li>If adding a package exceeds the capacity, start a new day.</li>
<li>If the required days are less than or equal to <code>days</code>, the capacity is valid.</li>
<li>Since we want the minimum valid capacity, search for a smaller capacity.</li>
<li>If more than <code>days</code> are required, the capacity is too small, so search for a larger capacity.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The problem has a <strong>monotonic property</strong>.</p>

<pre>
Capacity increases
       ↓
Packages can be shipped using fewer days
</pre>

<p>Therefore, the possible answers follow this pattern:</p>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
             Minimum valid capacity
</pre>

<p>Once a capacity is sufficient to ship all packages within <code>days</code>, every larger capacity will also work.</p>

<p>This allows us to use <strong>Binary Search on Answer</strong>.</p>

<h3>Checking a Candidate Capacity</h3>

<p>For a given capacity:</p>

<ul>
<li>Start with <code>1</code> shipping day.</li>
<li>Keep adding packages to the current day.</li>
<li>If the next package would exceed the capacity, start a new day.</li>
<li>Continue until all packages are shipped.</li>
<li>Compare the number of required days with <code>days</code>.</li>
</ul>

<p>For example:</p>

<pre>
weights = [1,2,3,4,5]
capacity = 6

Day 1 → 1 + 2 + 3 = 6
Day 2 → 4
Day 3 → 5

Required days = 3
</pre>

<h3>Binary Search Logic</h3>

<pre>
if (requiredDays &lt;= days):
    high = mid - 1
else:
    low = mid + 1
</pre>

<p>If the current capacity works, search left because we want a smaller capacity.</p>

<p>If the current capacity does not work, search right because we need more capacity.</p>

<h3>Why Does <code>low</code> Become the Answer?</h3>

<p>At the end of the binary search:</p>

<pre>
low &gt; high
</pre>

<p><code>low</code> points to the first capacity that can successfully ship all packages within the required number of days.</p>

<pre>
Invalid capacities | Valid capacities
-------------------|-------------------&gt;
                   ↑
                  low

             Answer = low
</pre>

<h3>Important Concept</h3>

<p>This is not binary search directly on the <code>weights</code> array.</p>

<p>We are searching over the <strong>answer space</strong>:</p>

<pre>
max(weights) ---------------- sum(weights)
       ↑                           ↑
   Minimum                     Maximum
   possible                    possible
   capacity                    capacity
</pre>

<p>For every candidate capacity, we ask:</p>

<pre>
"Can all packages be shipped within D days?"
</pre>

<p>The answer is either <strong>YES</strong> or <strong>NO</strong>, which gives us the monotonic property required for binary search.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log S)</code></p>

<p>where <code>n</code> is the number of packages and <code>S = sum(weights)</code>.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Monotonic Search</p>

<p><strong>Key Idea:</strong> Binary search for the minimum ship capacity. For each candidate capacity, simulate shipping the packages in order and count the number of days required. If the required days are within <code>D</code>, search left; otherwise, search right.</p>
