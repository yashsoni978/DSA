<h2>1482. Minimum Number of Days to Make m Bouquets</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an integer array <code>bloomDay</code> where <code>bloomDay[i]</code> represents the day the <code>i-th</code> flower blooms, and two integers <code>m</code> and <code>k</code>, find the <strong>minimum number of days</strong> needed to make <code>m</code> bouquets.</p>

<p>Each bouquet requires exactly <code>k</code> <strong>adjacent flowers</strong> that have already bloomed.</p>

<h3>Example 1</h3>

<pre>
Input: bloomDay = [1,10,3,10,2], m = 3, k = 1

Output: 3
</pre>

<h3>Example 2</h3>

<pre>
Input: bloomDay = [1,10,3,10,2], m = 3, k = 2

Output: -1
</pre>

<h3>Example 3</h3>

<pre>
Input: bloomDay = [7,7,7,7,12,7,7], m = 2, k = 3

Output: 12
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>We binary search over the possible number of days from <code>min(bloomDay)</code> to <code>max(bloomDay)</code>.</li>
<li>For a given day, check how many bouquets can be formed.</li>
<li>A flower is available if <code>bloomDay[i] &lt;= day</code>.</li>
<li>Count consecutive available flowers.</li>
<li>Whenever the consecutive count reaches <code>k</code>, one bouquet can be formed.</li>
<li>If a flower has not bloomed, reset the consecutive count to zero.</li>
<li>If at least <code>m</code> bouquets can be formed, the current day is valid, so search for a smaller day.</li>
<li>Otherwise, search for a larger day.</li>
</ul>

<h3>Important Observation</h3>

<p>Before binary search, check whether there are enough flowers to make the required bouquets.</p>

<pre>
Required flowers = m × k
</pre>

<p>If:</p>

<pre>
m × k &gt; bloomDay.size()
</pre>

<p>then it is impossible to make <code>m</code> bouquets, so return <code>-1</code>.</p>

<h3>Why Binary Search Works</h3>

<p>The problem has a <strong>monotonic property</strong>.</p>

<pre>
Days increase
      ↓
More flowers become available
      ↓
Number of possible bouquets increases
</pre>

<p>Therefore, the result follows this pattern:</p>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
             Minimum valid day
</pre>

<p>Once a particular day is sufficient to make <code>m</code> bouquets, every later day will also be sufficient.</p>

<p>So we can use <strong>Binary Search on Answer</strong> to find the first valid day.</p>

<h3>Checking a Candidate Day</h3>

<p>For each candidate day:</p>

<ul>
<li>If <code>bloomDay[i] &lt;= day</code>, increment the consecutive flower count.</li>
<li>If <code>bloomDay[i] &gt; day</code>, reset the consecutive count to zero.</li>
<li>Whenever consecutive flowers reach <code>k</code>, increment the bouquet count and reset the consecutive count.</li>
<li>If the bouquet count reaches <code>m</code>, the day is valid.</li>
</ul>

<h3>Binary Search Logic</h3>

<pre>
if (canMake(mid)):
    high = mid - 1
else:
    low = mid + 1
</pre>

<p>When the current day is valid, we move left because we want the <strong>minimum possible day</strong>.</p>

<p>When the current day is invalid, we move right because more flowers need time to bloom.</p>

<h3>Why Does <code>low</code> Become the Answer?</h3>

<p>At the end of binary search:</p>

<pre>
low &gt; high
</pre>

<p><code>low</code> points to the <strong>first day that satisfies the requirement</strong>.</p>

<pre>
Invalid days | Valid days
-------------|--------------------&gt;
             ↑
            low

        Answer = low
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log M)</code></p>

<p>where <code>n</code> is the number of flowers and <code>M</code> is the range of possible days.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Monotonic Search</p>

<p><strong>Key Idea:</strong> Binary search for the minimum day. For each candidate day, count consecutive bloomed flowers and determine whether at least <code>m</code> bouquets of <code>k</code> adjacent flowers can be formed.</p>
