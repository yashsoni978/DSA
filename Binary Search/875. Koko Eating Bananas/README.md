<h2>875. Koko Eating Bananas</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>piles</code> where <code>piles[i]</code> represents the number of bananas in the <code>i-th</code> pile, and an integer <code>h</code> representing the number of hours available, find the <strong>minimum integer eating speed</strong> <code>k</code> such that Koko can eat all the bananas within <code>h</code> hours.</p>

<p>At a speed of <code>k</code> bananas per hour, Koko spends:</p>

<pre>
ceil(pile / k)
</pre>

<p>hours to finish a pile.</p>

<p>The goal is to find the smallest possible <code>k</code>. :contentReference[oaicite:0]{index=0}</p>

<h3>Example 1</h3>

<pre>
Input: piles = [3,6,7,11], h = 8

Output: 4
</pre>

<h3>Example 2</h3>

<pre>
Input: piles = [30,11,23,4,20], h = 5

Output: 30
</pre>

<h3>Example 3</h3>

<pre>
Input: piles = [30,11,23,4,20], h = 6

Output: 23
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>The minimum possible eating speed is <code>1</code>.</li>
<li>The maximum useful eating speed is <code>max(piles)</code>.</li>
<li>For a given speed <code>k</code>, calculate how many hours Koko needs.</li>
<li>For every pile, required hours are <code>ceil(pile / k)</code>.</li>
<li>If the total hours are less than or equal to <code>h</code>, then <code>k</code> is a valid speed.</li>
<li>Since we want the minimum valid speed, search for a smaller speed.</li>
<li>If the total hours are greater than <code>h</code>, <code>k</code> is too slow, so search for a larger speed.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The important observation is that the answer has a <strong>monotonic property</strong>.</p>

<pre>
Speed increases
      ↓
Hours required decrease
</pre>

<p>For example:</p>

<pre>
k = 2  →  takes 10 hours → NOT possible
k = 3  →  takes 8 hours  → possible
k = 4  →  takes 7 hours  → possible
k = 5  →  takes 6 hours  → possible
</pre>

<p>Once a speed becomes possible, every larger speed is also possible.</p>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE TRUE
                    ↑
              Minimum valid speed
</pre>

<p>This is exactly the type of problem where we can use <strong>Binary Search on Answer</strong>. :contentReference[oaicite:1]{index=1}</p>

<h3>Calculating Hours</h3>

<p>For a pile containing <code>x</code> bananas and eating speed <code>k</code>:</p>

<pre>
hours = ceil(x / k)
</pre>

<p>In integer arithmetic:</p>

<pre>
hours = (x + k - 1) / k
</pre>

<p>For example:</p>

<pre>
pile = 11
k = 4

hours = ceil(11 / 4)
      = 3
</pre>

<p>Koko needs 3 hours for this pile.</p>

<h3>Full Dry Run</h3>

<pre>
piles = [3,6,7,11]
h = 8
</pre>

<p>Search range:</p>

<pre>
low = 1
high = 11
</pre>

<h4>Iteration 1</h4>

<pre>
low = 1
high = 11

mid = 6
</pre>

<p>Calculate hours at <code>k = 6</code>:</p>

<pre>
Pile 3:
ceil(3/6) = 1 hour

Pile 6:
ceil(6/6) = 1 hour

Pile 7:
ceil(7/6) = 2 hours

Pile 11:
ceil(11/6) = 2 hours
</pre>

<p>Total:</p>

<pre>
1 + 1 + 2 + 2 = 6 hours
</pre>

<p>We have:</p>

<pre>
6 <= 8
</pre>

<p>So speed <code>6</code> is possible.</p>

<p>But we need the <strong>minimum</strong> possible speed, so search left:</p>

<pre>
high = mid - 1
high = 5
</pre>

<h4>Iteration 2</h4>

<pre>
low = 1
high = 5

mid = 3
</pre>

<p>Calculate hours:</p>

<pre>
Pile 3:
ceil(3/3) = 1

Pile 6:
ceil(6/3) = 2

Pile 7:
ceil(7/3) = 3

Pile 11:
ceil(11/3) = 4
</pre>

<p>Total:</p>

<pre>
1 + 2 + 3 + 4 = 10 hours
</pre>

<p>But:</p>

<pre>
10 > 8
</pre>

<p>Speed <code>3</code> is too slow.</p>

<p>Therefore, search right:</p>

<pre>
low = mid + 1
low = 4
</pre>

<h4>Iteration 3</h4>

<pre>
low = 4
high = 5

mid = 4
</pre>

<p>Calculate hours:</p>

<pre>
Pile 3:
ceil(3/4) = 1

Pile 6:
ceil(6/4) = 2

Pile 7:
ceil(7/4) = 2

Pile 11:
ceil(11/4) = 3
</pre>

<p>Total:</p>

<pre>
1 + 2 + 2 + 3 = 8 hours
</pre>

<p>We have:</p>

<pre>
8 <= 8
</pre>

<p>Therefore, speed <code>4</code> is possible.</p>

<p>Search left:</p>

<pre>
high = mid - 1
high = 3
</pre>

<p>Now:</p>

<pre>
low = 4
high = 3
</pre>

<p>The search ends.</p>

<p>Therefore:</p>

<pre>
Answer = 4
</pre>

<h3>C++ Solution</h3>

<pre>
class Solution {
public:
    bool canFinish(vector&lt;int&gt;&amp; piles, int h, int k) {
        long long hours = 0;

        for (int pile : piles) {
            hours += (pile + k - 1) / k;

            if (hours &gt; h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector&lt;int&gt;&amp; piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while (low &lt;= high) {
            int mid = low + (high - low) / 2;

            if (canFinish(piles, h, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};
</pre>

<h3>Why Does <code>low</code> Become the Answer?</h3>

<p>Whenever <code>mid</code> is valid:</p>

<pre>
canFinish(...) == true
</pre>

<p>we do:</p>

<pre>
high = mid - 1;
</pre>

<p>because we want to find an even smaller valid speed.</p>

<p>When <code>low &gt; high</code>, all smaller speeds have been eliminated and <code>low</code> points to the first valid speed.</p>

<pre>
        invalid        valid
----------|-------------------->
           ↑
          low

        Answer = low
</pre>

<h3>Important Concept</h3>

<p>This is not binary search directly on the array.</p>

<p>We are binary searching over the <strong>answer space</strong>:</p>

<pre>
1 ---------------------- max(piles)
↑                            ↑
slowest                      fastest
possible                     useful speed
speed
</pre>

<p>For each candidate speed, we ask:</p>

<pre>
"Can Koko finish all bananas within h hours?"
</pre>

<p>That yes/no decision allows us to perform binary search.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log M)</code></p>

<p>where <code>n</code> is the number of piles and <code>M = max(piles)</code>.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Monotonic Search</p>

<p><strong>Key Idea:</strong> Binary search for the minimum eating speed <code>k</code>. For every speed, calculate the total hours using <code>ceil(pile / k)</code>. If the total is within <code>h</code>, try a smaller speed; otherwise, increase the speed.</p>
