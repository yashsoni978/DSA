<h2>Subset Sums</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<p>Given an array <code>arr</code>, find the sums of all possible subsets.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
arr = [2, 3]

<strong>Output:</strong>
[0, 2, 3, 5] </pre>

<p><strong>Approach:</strong></p>

<p>Use <strong>recursion with take / not-take</strong>.</p>

<ul>
<li><strong>Take:</strong> Include the current element in the subset sum.</li>
<li><strong>Not Take:</strong> Skip the current element.</li>
<li>When all elements are processed, store the current sum.</li>
</ul>

<pre>
void findSum(int ind, int sum) {
    if(ind == arr.size()) {
        ans.push_back(sum);
        return;
    }

    // Take
    findSum(ind + 1, sum + arr[ind]);

    // Not Take
    findSum(ind + 1, sum);
}
</pre>

<p><strong>Key Observation:</strong></p>

<p>Every element has exactly <strong>2 choices</strong>: take it or don't take it. Therefore, for <code>n</code> elements there are <code>2<sup>n</sup></code> subsets.</p>

<p><strong>Time Complexity:</strong> <code>O(2<sup>n</sup>)</code></p>

<p><strong>Space Complexity:</strong> <code>O(n)</code> recursion stack, excluding the output.</p>
