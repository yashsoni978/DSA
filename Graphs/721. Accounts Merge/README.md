<h2>721. Accounts Merge</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a list of <code>accounts</code>, where each element <code>accounts[i]</code> is a list of strings, the first element is a <strong>name</strong>, and the remaining elements are <strong>emails</strong> representing emails of the account.</p>

<p>Two accounts definitely belong to the same person if there is at least one common email address. Note that even if two accounts have the same name, they may belong to different people, as people can share the same name.</p>

<p>After merging the accounts, return the accounts in the following format:</p>

<ul>
  <li>The first element of each account is the person's name.</li>
  <li>The remaining elements are the merged email addresses in <strong>sorted order</strong>.</li>
  <li>The returned accounts themselves can be in <strong>any order</strong>.</li>
</ul>

<p><strong>Example 1:</strong></p>

<pre>
<strong>Input:</strong>

accounts = [
["John","johnsmith@mail.com","john_newyork@mail.com"],
["John","johnsmith@mail.com","john00@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]
]

<strong>Output:</strong>

[
["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],
["Mary","mary@mail.com"],
["John","johnnybravo@mail.com"]
]
</pre>

<p><strong>Example 2:</strong></p>

<pre>
<strong>Input:</strong>

accounts = [
["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],
["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],
["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],
["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],
["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]
]

<strong>Output:</strong>

[
["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],
["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],
["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],
["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],
["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]
]
</pre>

<p><strong>Constraints:</strong></p>

<ul>
  <li><code>1 ≤ accounts.length ≤ 1000</code></li>
  <li><code>2 ≤ accounts[i].length ≤ 10</code></li>
  <li><code>1 ≤ accounts[i][j].length ≤ 30</code></li>
  <li><code>accounts[i][0]</code> consists of English letters.</li>
  <li><code>accounts[i][j]</code> (for <code>j &gt; 0</code>) is a valid email address.</li>
</ul>

<p><strong>Follow-up:</strong> Can you solve this problem efficiently using a <strong>Disjoint Set Union (Union-Find)</strong> data structure to merge accounts sharing common email addresses?</p>
