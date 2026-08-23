<h2>Aggressive Cows</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>arr</code> representing the positions of stalls and <code>k</code> cows, place the cows in different stalls such that the <strong>minimum distance between any two cows is maximized</strong>.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [1,2,4,8,9], k = 3

Output: 3
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [10,1,2,7,5], k = 3

Output: 4
</pre>

<h3>Approach</h3>

<ul>
<li>First, <strong>sort</strong> the stall positions.</li>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible distance is <code>1</code> (or <code>0</code> if duplicate positions were allowed).</li>
<li>The maximum possible distance is <code>arr[n-1] - arr[0]</code>.</li>
<li>For a candidate distance <code>mid</code>, check whether we can place all <code>k</code> cows while maintaining at least <code>mid</code> distance between consecutive cows.</li>
<li>Place the first cow in the first stall.</li>
<li>Then greedily place every next cow in the earliest stall whose distance from the previously placed cow is at least <code>mid</code>.</li>
<li>If we can place at least <code>k</code> cows, the distance is possible, so search for a larger distance.</li>
<li>If we cannot place <code>k</code> cows, the distance is too large, so search for a smaller distance.</li>
</ul>

<h3>Why Greedy Works</h3>

<p>For a fixed minimum distance, placing each cow in the <strong>earliest possible stall</strong> leaves the maximum amount of space for the remaining cows.</p>

<p>Therefore, if the greedy approach cannot place <code>k</code> cows, no other placement can do so for that distance.</p>

<h3>Why Binary Search Works</h3>

<p>The problem has a <strong>monotonic property</strong>.</p>

<p>If we can place all cows with a minimum distance of <code>x</code>, then we can also place them with any distance smaller than <code>x</code>.</p>

<pre>
Distance increases
       ↓
Placement becomes harder
</pre>

<p>Therefore, the possible answers follow this pattern:</p>

<pre>
TRUE TRUE TRUE TRUE FALSE FALSE
                  ↑
          Maximum valid distance
</pre>

<p>We use binary search to find the <strong>largest valid distance</strong>.</p>

<h3>Checking a Candidate Distance</h3>

<p>For a candidate distance <code>mid</code>:</p>

<ul>
<li>Place the first cow at the first stall.</li>
<li>Keep track of the position of the last placed cow.</li>
<li>For every stall, check:</li>
</ul>

<pre>
currentPosition - lastPosition >= mid
</pre>

<ul>
<li>If the condition is satisfied, place another cow.</li>
<li>Continue until either all stalls are checked or <code>k</code> cows are placed.</li>
</ul>

<h3>Binary Search Logic</h3>

<pre>
if (canPlace(mid)):
    ans = mid
    low = mid + 1
else:
    high = mid - 1
</pre>

<p>If the current distance is possible, try a <strong>larger distance</strong> because we want to maximize the minimum distance.</p>

<p>If the current distance is not possible, try a <strong>smaller distance</strong>.</p>

<h3>Why Does <code>ans</code> Store the Answer?</h3>

<p>Whenever a distance is valid, store it:</p>

<pre>
ans = mid
</pre>

<p>Then search for an even larger valid distance.</p>

<p>When the binary search ends, <code>ans</code> contains the largest distance for which all <code>k</code> cows can be placed.</p>

<pre>
Valid distances | Invalid distances
----------------|-------------------&gt;
             ans ↑

        Maximum valid distance
</pre>

<h3>Important Concept</h3>

<p>This is not binary search directly on the stall positions.</p>

<p>We are binary searching over the <strong>answer space</strong>:</p>

<pre>
1 ---------------- arr[n-1] - arr[0]
↑                              ↑
Minimum                    Maximum possible
distance                      distance
</pre>

<p>For every candidate distance, we ask:</p>

<pre>
"Can I place k cows such that
every pair has at least this distance?"
</pre>

<p>The answer is either <strong>YES</strong> or <strong>NO</strong>, which gives us the monotonic property needed for binary search.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log n + n log M)</code></p>

<p>where <code>n</code> is the number of stalls and <code>M = max(arr) - min(arr)</code>.</p>

<p>The <code>O(n log n)</code> comes from sorting, while the binary search takes <code>O(log M)</code> iterations and each feasibility check takes <code>O(n)</code>.</p>

<p><strong>Space:</strong> <code>O(1)</code> auxiliary space, excluding the sorting implementation.</p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Greedy / Monotonic Search</p>

<p><strong>Key Idea:</strong> Sort the stalls and binary search for the maximum possible minimum distance. For every candidate distance, greedily place cows in the earliest possible stalls and check whether all <code>k</code> cows can be placed.</p>
