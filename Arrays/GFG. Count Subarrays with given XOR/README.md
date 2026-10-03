<h2>Count Subarrays with Given XOR</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>
Given an array of integers <code>arr[]</code> and an integer <code>k</code>,
count the number of subarrays whose XOR of all elements is equal to <code>k</code>.
</p>

<h3>Example</h3>

<pre>
Input:
arr[] = [4, 2, 2, 6, 4]
k = 6

Output:
4
</pre>

<p>
The subarrays having XOR equal to <code>6</code> are:
</p>

<pre>
[4, 2]
[4, 2, 2, 6, 4]
[2, 2, 6]
[6]
</pre>

<h3>Approach</h3>

<p>
We use <b>Prefix XOR + Hash Map</b> to solve the problem efficiently.
</p>

<p>
Let the prefix XOR up to the current index be <code>xr</code>.
For a subarray to have XOR equal to <code>k</code>:
</p>

<pre>
prefixXOR ^ previousPrefixXOR = k
</pre>

<p>
Therefore:
</p>

<pre>
previousPrefixXOR = prefixXOR ^ k
</pre>

<p>
So, while traversing the array, we check how many times
<code>xr ^ k</code> has appeared before.
Each occurrence represents one subarray whose XOR is <code>k</code>.
</p>

<h3>Algorithm</h3>

<ol>
<li>Initialize <code>xr = 0</code> and <code>count = 0</code>.</li>
<li>Create a hash map to store the frequency of prefix XOR values.</li>
<li>Insert <code>0</code> into the map with frequency <code>1</code>.</li>
<li>Traverse the array:
    <ul>
        <li>Update the prefix XOR: <code>xr = xr ^ arr[i]</code>.</li>
        <li>Calculate <code>xr ^ k</code>.</li>
        <li>Add its frequency from the map to <code>count</code>.</li>
        <li>Increase the frequency of <code>xr</code> in the map.</li>
    </ul>
</li>
<li>Return <code>count</code>.</li>
</ol>

<h3>Why Do We Store Frequency?</h3>

<p>
The same prefix XOR can occur multiple times. Each previous occurrence can
form a different subarray with XOR equal to <code>k</code>.
Therefore, we store the <b>frequency</b> rather than just whether the XOR exists.
</p>

<h3>Example Walkthrough</h3>

<pre>
arr = [4, 2, 2, 6, 4]
k = 6

Prefix XORs:
4
4 ^ 2 = 6
6 ^ 2 = 4
4 ^ 6 = 2
2 ^ 4 = 6
</pre>

<p>
Whenever the required previous prefix XOR
<code>currentXOR ^ k</code> is found in the map, we add its frequency to the answer.
This counts all valid subarrays.
</p>

<h3>Complexity</h3>

<pre>
Time Complexity: O(N)
Space Complexity: O(N)
</pre>

<p>
The array is traversed once, and the hash map stores frequencies of prefix XOR values.
</p>
