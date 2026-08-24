<h2>774. Minimize Max Distance to Gas Station</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>Given sorted gas station positions and <code>k</code> additional gas stations, place the new stations such that the <strong>maximum distance between adjacent gas stations is minimized</strong>.</p>

<h3>Example 1</h3>

<pre>
Input: stations = [1,2,3,4,5], k = 2

Output: 1.000000
</pre>

<h3>Example 2</h3>

<pre>
Input: stations = [3,6,12,19,33], k = 3

Output: 6.000000
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible maximum distance is <code>0</code>.</li>
<li>The maximum possible distance is the largest gap between adjacent stations.</li>
<li>For a candidate distance <code>mid</code>, calculate how many additional stations are required to make every gap at most <code>mid</code>.</li>
<li>For a gap of length <code>gap</code>, the required number of new stations is <code>ceil(gap / mid) - 1</code>.</li>
<li>If the required stations are greater than <code>k</code>, <code>mid</code> is too small, so search right.</li>
<li>If the required stations are less than or equal to <code>k</code>, <code>mid</code> is possible, so search left.</li>
<li>Continue until the difference between <code>low</code> and <code>high</code> is less than <code>10^-6</code>.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The problem has a <strong>monotonic property</strong>.</p>

<pre>
Allowed distance increases
        ↓
Required additional stations decrease
</pre>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
            Minimum valid distance
</pre>

<p>Once a distance is possible using at most <code>k</code> stations, every larger distance is also possible.</p>

<h3>Helper Function</h3>

<p>The helper function answers:</p>

<pre>
"How many new stations are required if
the maximum allowed gap is dist?"
</pre>

<p>For every adjacent gap:</p>

<pre>
gap = stations[i] - stations[i-1]
</pre>

<p>The number of required stations is:</p>

<pre>
ceil(gap / dist) - 1
</pre>

<p>For example:</p>

<pre>
gap = 10
dist = 3

ceil(10 / 3) - 1
= 4 - 1
= 3
</pre>

<p>So 3 new stations are required.</p>

<h3>Binary Search Logic</h3>

<pre>
if requiredStations &gt; k:
    low = mid

else:
    high = mid
</pre>

<p>If more than <code>k</code> stations are required, the distance is too small.</p>

<p>If at most <code>k</code> stations are required, the distance is valid and we try a smaller one.</p>

<h3>Why Return <code>high</code>?</h3>

<p>This is a <strong>floating-point binary search</strong>. We stop when:</p>

<pre>
high - low &lt; 10^-6
</pre>

<p>At this point, <code>high</code> represents the minimum valid distance within the required precision.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n × log(maxGap / 10^-6))</code></p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search on Answer / Floating Point Binary Search / Greedy</p>

<p><strong>Key Idea:</strong> Binary search for the minimum possible maximum gap. For every candidate distance, count how many additional stations are needed. If more than <code>k</code> are required, increase the distance; otherwise, decrease it.</p>
