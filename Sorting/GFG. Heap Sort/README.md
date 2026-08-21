<h2>Heap Sort</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>arr[]</code>, sort all the elements using the <strong>Heap Sort</strong> algorithm.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [4,1,3,9,7]

Output: [1,3,4,7,9]
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [10,9,8,7,6,5,4,3,2,1]

Output: [1,2,3,4,5,6,7,8,9,10]
</pre>

<h3>Example 3</h3>

<pre>
Input: arr = [2,1,5]

Output: [1,2,5]
</pre>

<h3>Approach</h3>

<ul>
<li>Use a <strong>Max Heap</strong> to sort the array in ascending order.</li>
<li>First, convert the entire array into a Max Heap using <code>heapify</code>.</li>
<li>In a Max Heap, the largest element is always present at index <code>0</code>.</li>
<li>Swap the root element with the last element of the current heap.</li>
<li>Reduce the heap size by one because the largest element is now in its correct final position.</li>
<li>Call <code>heapify</code> on the root to restore the Max Heap property.</li>
<li>Repeat the process until only one element remains in the heap.</li>
</ul>

<h3>Heap Representation</h3>

<p>For an element at index <code>i</code>:</p>

<ul>
<li>Left child = <code>2 * i + 1</code></li>
<li>Right child = <code>2 * i + 2</code></li>
</ul>

<h3>Why Max Heap?</h3>

<p>A Max Heap keeps the largest element at the root. By repeatedly moving this largest element to the end of the array, we place elements in their correct positions from right to left.</p>

<p>Therefore, after repeatedly extracting the maximum element, the array becomes sorted in ascending order.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log n)</code></p>
<p><strong>Space:</strong> <code>O(1)</code> auxiliary space</p>

<hr>

<p><strong>Pattern:</strong> Heap / Sorting / Complete Binary Tree</p>

<p><strong>Key Idea:</strong> Build a Max Heap, repeatedly move the maximum element to the end of the array, reduce the heap size, and restore the heap using <code>heapify</code>.</p>
