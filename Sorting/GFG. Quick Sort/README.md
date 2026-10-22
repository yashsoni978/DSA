<h2>Quick Sort</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given an array <b>arr[]</b> with starting index <b>low</b> and ending index
<b>high</b>, implement the <b>partition()</b> and <b>quickSort()</b> functions
to sort the array in ascending order.
</p>

<p>
Quick Sort selects a pivot element and rearranges the array so that elements
smaller than or equal to the pivot appear before it, while larger elements
appear after it. The process is then repeated recursively for both partitions.
</p>

<h3>Example 1</h3>

<pre>
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
</pre>

<p>
Explanation: After sorting, all elements are arranged in ascending order.
</p>

<h3>Example 2</h3>

<pre>
Input: arr[] = [2, 1, 6, 10, 4, 1, 3, 9, 7]
Output: [1, 1, 2, 3, 4, 6, 7, 9, 10]
</pre>

<p>
Explanation: All elements are sorted in ascending order, and duplicate
elements are retained.
</p>

<h3>Example 3</h3>

<pre>
Input: arr[] = [5, 5, 5, 5]
Output: [5, 5, 5, 5]
</pre>

<p>
Explanation: All elements are equal, so the array remains unchanged.
</p>

<h3>Approach</h3>

<ol>
    <li>
        <b>Choose a pivot:</b> Select an element as the pivot. In the standard
        Lomuto partition approach, the last element is often selected.
    </li>
    <li>
        <b>Partition:</b> Rearrange the elements so that values less than or
        equal to the pivot are placed before it, and larger values are placed
        after it.
    </li>
    <li>
        <b>Place the pivot:</b> Put the pivot in its correct sorted position
        and return its index.
    </li>
    <li>
        <b>Recursive sorting:</b> Apply Quick Sort to the subarray before the
        pivot and the subarray after the pivot.
    </li>
    <li>
        <b>Base case:</b> Stop when a subarray contains zero or one element,
        because it is already sorted.
    </li>
</ol>

<h3>Complexity</h3>

<pre>
// Best/Average TC: O(N log N)
// Worst TC: O(N^2)
// Average SC: O(log N) recursive stack
// Worst SC: O(N) recursive stack
</pre>

<h3>Key Point</h3>

<p>
The partition operation places the pivot in its correct sorted position.
Quick Sort then recursively sorts the elements on either side of the pivot.
Its average time complexity is <b>O(N log N)</b>, but poor pivot choices can
lead to a worst-case time complexity of <b>O(N²)</b>.
</p>
