<h2>Second Largest</h2>
<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given an array of positive integers <b>arr[]</b>, find and return the
<b>second largest distinct element</b> in the array.
</p>

<p>
If a second largest element does not exist, return <b>-1</b>.
The second largest element must be different from the largest element.
</p>

<h3>Example</h3>

<pre>
Input: arr[] = [12, 35, 1, 10, 34, 1]
Output: 34
</pre>

<p>
The largest element is <b>35</b>, so the second largest distinct element is <b>34</b>.
</p>

<pre>
Input: arr[] = [10, 5, 10]
Output: 5
</pre>

<p>
The largest element is <b>10</b>, and the second largest distinct element is <b>5</b>.
</p>

<pre>
Input: arr[] = [10, 10, 10]
Output: -1
</pre>

<p>
There is no element smaller than the largest element, so a second largest
element does not exist.
</p>

<h3>Approach</h3>

<p>
Traverse the array once while maintaining two variables:
</p>

<ul>
    <li><b>largest</b> → stores the largest element.</li>
    <li><b>secondLargest</b> → stores the second largest distinct element.</li>
</ul>

<p>
For every element:
</p>

<ul>
    <li>If it is greater than <b>largest</b>, update both values.</li>
    <li>Otherwise, if it is smaller than <b>largest</b> but greater than <b>secondLargest</b>, update <b>secondLargest</b>.</li>
</ul>

<p>
This automatically handles duplicate largest elements because the second largest
must be <b>strictly smaller</b> than the largest.
</p>

<h3>Complexity</h3>

<pre>
// TC: O(N)
// SC: O(1)
</pre>

<h3>Key Point</h3>

<p>
The second largest element must be <b>distinct</b> from the largest element,
so we only consider values strictly smaller than <b>largest</b>.
</p>
