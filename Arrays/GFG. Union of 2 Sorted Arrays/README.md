<h2>Union of 2 Sorted Arrays</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given two sorted arrays <code>a[]</code> and <code>b[]</code>, where both arrays
may contain duplicate elements, return the <b>union</b> of the two arrays in
sorted order.
</p>

<p>
The union contains only <b>distinct elements</b> that are present in either
of the two arrays.
</p>

<h3>Example</h3>

<pre>
Input:
a[] = [1, 2, 3, 4, 5]
b[] = [1, 2, 3, 6, 7]

Output:
[1, 2, 3, 4, 5, 6, 7]
</pre>

<h3>Approach</h3>

<p>
Since both arrays are already sorted, we can use the <b>two-pointer approach</b>.
</p>

<ul>
<li>Maintain two pointers, one for each array.</li>
<li>Compare the elements pointed to by the two pointers.</li>
<li>Add the smaller element to the result.</li>
<li>If both elements are equal, add it only once and move both pointers.</li>
<li>Skip duplicate elements so that the result contains only distinct values.</li>
<li>After one array is exhausted, add the remaining distinct elements from the other array.</li>
</ul>

<h3>Example</h3>

<pre>
a = [1, 2, 3, 4, 5]
b = [1, 2, 3, 6, 7]

Union:
[1, 2, 3, 4, 5, 6, 7]
</pre>

<h3>Complexity</h3>

<pre>
// TC: O(N + M)
// SC: O(N + M)
// N = size of array a
// M = size of array b
</pre>

<h3>Key Point</h3>

<p>
Because the arrays are already sorted, the <b>two-pointer technique</b> lets us
merge them efficiently while removing duplicates.
</p>
