<h2>1539. Kth Missing Positive Number</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<p>Given a strictly increasing array <code>arr</code> of positive integers and an integer <code>k</code>, find the <strong>k-th positive integer that is missing</strong> from the array.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [2,3,4,7,11], k = 5

Output: 9
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [1,2,3,4], k = 2

Output: 6
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search</strong>.</li>
<li>For every index <code>i</code>, the number of missing positive integers before <code>arr[i]</code> is:</li>
</ul>

<pre>
missing = arr[i] - (i + 1)
</pre>

<ul>
<li>If <code>missing &lt; k</code>, the k-th missing number is further to the right.</li>
<li>If <code>missing &gt;= k</code>, the answer is at or before the current position.</li>
<li>Binary search for the first index where the number of missing elements is at least <code>k</code>.</li>
</ul>

<h3>Why Does <code>arr[i] - (i + 1)</code> Give the Missing Count?</h3>

<p>If there were no missing numbers, the value at index <code>i</code> would be:</p>

<pre>
i + 1
</pre>

<p>For example:</p>

<pre>
Index:    0  1  2  3
Expected: 1  2  3  4
```

<p>If the actual value is larger than the expected value, the difference represents how many positive integers are missing.</p>

<pre>
arr[i] = 7
i + 1  = 4

Missing = 7 - 4
        = 3
</pre>

<p>So there are <code>3</code> missing positive numbers before <code>7</code>.</p>

<h3>Why Binary Search Works</h3>

<p>Because the array is strictly increasing, the number of missing elements also increases as we move to the right.</p>

<pre>
Index:        0   1   2   3   4
arr:          2   3   4   7  11
Missing:      1   1   1   3   6
</pre>

<p>We need to find the first position where:</p>

<pre>
missing &gt;= k
</pre>

<p>This creates a monotonic pattern:</p>

<pre>
FALSE FALSE FALSE TRUE TRUE
                    ↑
             First valid index
</pre>

<h3>Binary Search Logic</h3>

<pre>
missing = arr[mid] - (mid + 1)

if (missing &lt; k):
    low = mid + 1
else:
    high = mid - 1
</pre>

<p>After the binary search, <code>low</code> represents how many elements of the array are before the answer.</p>

<h3>Finding the Answer</h3>

<p>After binary search, the answer can be calculated as:</p>

<pre>
answer = low + k
</pre>

<p>Why?</p>

<p>If there are <code>low</code> elements from the array before the answer, then we need to move <code>k</code> positions forward while accounting for those existing elements.</p>

<h3>Important Concept</h3>

<p>Instead of explicitly checking every missing number, calculate how many numbers are missing before each array element:</p>

<pre>
missing(i) = arr[i] - (i + 1)
</pre>

<p>Then binary search for the first position where the missing count reaches <code>k</code>.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log n)</code></p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Missing Elements / Monotonic Search</p>

<p><strong>Key Idea:</strong> For every index, calculate the number of missing positive integers using <code>arr[i] - (i + 1)</code>. Binary search for the first index where the missing count is at least <code>k</code>, then return <code>low + k</code>.</p>
