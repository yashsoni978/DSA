<h2>Intersection of Two Sorted Arrays</h2>

<img src="https://img.shields.io/badge/Difficulty-Easy-green" alt="Difficulty: Easy"/>

<hr>

<h3>Problem Statement</h3>

<p>
Given two sorted arrays <code>arr1[]</code> and <code>arr2[]</code>, return the
<b>intersection</b> of both arrays.
</p>

<p>
The intersection contains the elements that are <b>common to both arrays</b>.
Duplicate elements should be included only once.
</p>

<p>
If there is no common element, return an empty array.
</p>

<h3>Example</h3>

<pre>
Input:
arr1[] = [1, 2, 3, 4]
arr2[] = [2, 4, 6, 7, 8]

Output:
[2, 4]
</pre>

<pre>
Input:
arr1[] = [1, 2, 2, 3, 4]
arr2[] = [2, 2, 4, 6, 7, 8]

Output:
[2, 4]
</pre>

<h3>Approach</h3>

<p>
Since both arrays are sorted, we can use the <b>two-pointer approach</b>.
</p>

<ul>
<li>Maintain one pointer for each array.</li>
<li>If both elements are equal, add the element to the result.</li>
<li>Move both pointers when a common element is found.</li>
<li>If the element in the first array is smaller, move the first pointer.</li>
<li>If the element in the second array is smaller, move the second pointer.</li>
<li>Skip duplicate values to ensure every common element appears only once.</li>
</ul>

<h3>Example</h3>

<pre>
arr1 = [1, 2, 3, 4]
arr2 = [2, 4, 6, 7, 8]

Common elements:
2 → add
4 → add

Result:
[2, 4]
</pre>

<h3>Complexity</h3>

<pre>
// TC: O(N + M)
// SC: O(min(N, M))
// N = size of arr1
// M = size of arr2
</pre>

<h3>Key Point</h3>

<p>
Because both arrays are sorted, the <b>two-pointer technique</b> allows us to
find all common distinct elements in a single traversal without using a hash
set.
</p>
