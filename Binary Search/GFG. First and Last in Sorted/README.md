<h2>First and Last in Sorted</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a sorted array <code>arr[]</code> that may contain duplicate elements, find the <strong>first</strong> and <strong>last occurrence</strong> of an element <code>x</code>.</p>

<p>If <code>x</code> is not present in the array, return <code>[-1, -1]</code>.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [1,3,5,5,5,5,67,123,125], x = 5

Output: [2,5]

Explanation:
The first occurrence of 5 is at index 2.
The last occurrence of 5 is at index 5.
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [1,3,5,5,5,5,7,123,125], x = 7

Output: [6,6]

Explanation:
7 occurs only once, at index 6.
</pre>

<h3>Example 3</h3>

<pre>
Input: arr = [1,2,3], x = 4

Output: [-1,-1]

Explanation:
4 is not present in the array.
</pre>

<h3>Approach</h3>

<ul>
<li>Since the array is sorted, use <strong>Binary Search</strong>.</li>
<li>Perform one binary search to find the <strong>first occurrence</strong> of <code>x</code>.</li>
<li>When <code>arr[mid] == x</code>, store <code>mid</code> as a possible answer and continue searching to the <strong>left</strong>.</li>
<li>Perform another binary search to find the <strong>last occurrence</strong> of <code>x</code>.</li>
<li>When <code>arr[mid] == x</code>, store <code>mid</code> as a possible answer and continue searching to the <strong>right</strong>.</li>
<li>If the first occurrence does not exist, return <code>[-1,-1]</code>.</li>
</ul>

<h3>Finding the First Occurrence</h3>

<pre>
if arr[mid] == x:
    ans = mid
    search LEFT

if arr[mid] < x:
    search RIGHT

if arr[mid] > x:
    search LEFT
</pre>

<p>We continue searching left after finding <code>x</code> because there may be another occurrence of <code>x</code> at a smaller index.</p>

<h3>Finding the Last Occurrence</h3>

<pre>
if arr[mid] == x:
    ans = mid
    search RIGHT

if arr[mid] < x:
    search RIGHT

if arr[mid] > x:
    search LEFT
</pre>

<p>We continue searching right after finding <code>x</code> because there may be another occurrence of <code>x</code> at a larger index.</p>

<h3>Example</h3>

<pre>
arr = [1,3,5,5,5,5,67]
          ↑       ↑
        first    last

x = 5

First occurrence = 2
Last occurrence  = 5

Answer = [2,5]
</pre>

<h3>Connection with Lower Bound and Upper Bound</h3>

<p>The first occurrence can also be found using <strong>lower bound</strong>:</p>

<pre>
lower_bound(x) = first index where arr[i] >= x
</pre>

<p>The last occurrence can be found using <strong>upper bound</strong>:</p>

<pre>
upper_bound(x) - 1 = last index where arr[i] == x
</pre>

<p>Therefore:</p>

<pre>
First occurrence = lower_bound(x)

Last occurrence = upper_bound(x) - 1
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(log n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Lower Bound / Upper Bound</p>

<p><strong>Key Idea:</strong> After finding <code>x</code>, don't stop. For the first occurrence, continue searching left; for the last occurrence, continue searching right.</p>
