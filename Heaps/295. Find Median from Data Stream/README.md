<h2>295. Find Median from Data Stream</h2>

<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>

<hr>

<p>The <strong>median</strong> is the middle value in an ordered integer list.</p>

<ul>
  <li>If the size of the list is <strong>odd</strong>, the median is the middle element.</li>
  <li>If the size of the list is <strong>even</strong>, the median is the average of the two middle elements.</li>
</ul>

<p>Implement the <code>MedianFinder</code> class:</p>

<ul>
  <li><code>MedianFinder()</code> initializes the object.</li>
  <li><code>void addNum(int num)</code> adds the integer <code>num</code> from the data stream to the data structure.</li>
  <li><code>double findMedian()</code> returns the median of all elements so far.</li>
</ul>

<hr>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>

["MedianFinder","addNum","addNum","findMedian",
 "addNum","findMedian"]

[[],[1],[2],[],[3],[]]

<strong>Output:</strong>

[null,null,null,1.5,null,2.0]

<strong>Explanation:</strong>

MedianFinder medianFinder = new MedianFinder();

medianFinder.addNum(1);    // [1]
medianFinder.addNum(2);    // [1,2]
medianFinder.findMedian(); // 1.5

medianFinder.addNum(3);    // [1,2,3]
medianFinder.findMedian(); // 2.0
</pre>

<hr>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>-10<sup>5</sup> ≤ num ≤ 10<sup>5</sup></code></li>
  <li>There will be at least one element in the data structure before calling <code>findMedian()</code>.</li>
  <li>At most <code>5 × 10<sup>4</sup></code> calls will be made to <code>addNum()</code> and <code>findMedian()</code>.</li>
</ul>

<p><strong>Follow-up:</strong></p>

<ul>
  <li>If all integer numbers are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
  <li>If <code>99%</code> of all integer numbers are in the range <code>[0, 100]</code>, how would you optimize your solution?</li>
</ul>

<hr>

<p><strong>Hint:</strong> Can you maintain two heaps—a <strong>Max Heap</strong> for the smaller half and a <strong>Min Heap</strong> for the larger half—so that insertion takes <code>O(log n)</code> time and finding the median takes <code>O(1)</code> time?</p>
