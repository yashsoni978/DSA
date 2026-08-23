<h2>Allocate Minimum Pages</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given an array <code>arr</code> where <code>arr[i]</code> represents the number of pages in the <code>i-th</code> book, and an integer <code>k</code> representing the number of students, allocate all books such that:</p>

<ul>
<li>Each student gets at least one book.</li>
<li>Each student receives a <strong>contiguous sequence</strong> of books.</li>
<li>No book is assigned to more than one student.</li>
<li>All books must be allocated.</li>
</ul>

<p>The goal is to <strong>minimize the maximum number of pages</strong> assigned to any student.</p>

<h3>Example 1</h3>

<pre>
Input: arr = [12,34,67,90], k = 2

Output: 113
</pre>

<h3>Example 2</h3>

<pre>
Input: arr = [15,17,20], k = 5

Output: -1
</pre>

<h3>Approach</h3>

<ul>
<li>Use <strong>Binary Search on Answer</strong>.</li>
<li>If there are more students than books, return <code>-1</code>.</li>
<li>The minimum possible maximum pages is <code>max(arr)</code>, because every student must receive a complete book.</li>
<li>The maximum possible maximum pages is <code>sum(arr)</code>, when one student receives all books.</li>
<li>For a candidate maximum page limit, greedily allocate books in order.</li>
<li>Keep adding books to the current student while the total does not exceed the candidate limit.</li>
<li>If adding a book exceeds the limit, allocate the book to the next student.</li>
<li>Count how many students are required.</li>
<li>If the required students are less than or equal to <code>k</code>, the candidate limit is valid.</li>
<li>If more than <code>k</code> students are required, the candidate limit is too small.</li>
</ul>

<h3>Why Binary Search Works</h3>

<p>The problem has a <strong>monotonic property</strong>.</p>

<pre>
Maximum page limit increases
          ↓
More books can be assigned to each student
          ↓
Number of students required decreases
</pre>

<p>Therefore, the possible answers follow this pattern:</p>

<pre>
FALSE FALSE FALSE TRUE TRUE TRUE
                    ↑
             Minimum valid limit
</pre>

<p>Once a maximum page limit is sufficient, every larger limit will also be sufficient.</p>

<p>So we can use <strong>Binary Search on Answer</strong> to find the smallest valid maximum.</p>

<h3>Checking a Candidate Limit</h3>

<p>For a given maximum page limit:</p>

<ul>
<li>Start with one student.</li>
<li>Add books to the current student while the total pages remain within the limit.</li>
<li>If adding the next book exceeds the limit, move to the next student.</li>
<li>Continue until all books are allocated.</li>
<li>If the number of students required is greater than <code>k</code>, the limit is invalid.</li>
</ul>

<p>Because books must remain in their original order and each student receives a contiguous sequence, this greedy allocation gives the minimum number of students needed for a given limit.</p>

<h3>Binary Search Logic</h3>

<pre>
if (studentsRequired &lt;= k):
    high = mid - 1
else:
    low = mid + 1
</pre>

<p>If the current limit is valid, search left because we want a <strong>smaller maximum</strong>.</p>

<p>If the current limit is invalid, search right because we need a larger limit.</p>

<h3>Why Does <code>low</code> Become the Answer?</h3>

<p>At the end of binary search:</p>

<pre>
low &gt; high
</pre>

<p><code>low</code> points to the first maximum page limit that allows all books to be allocated using at most <code>k</code> students.</p>

<pre>
Invalid limits | Valid limits
---------------|--------------------&gt;
                ↑
               low

          Answer = low
</pre>

<h3>Important Concept</h3>

<p>We are not binary searching through the books.</p>

<p>We are binary searching over the <strong>answer space</strong>:</p>

<pre>
max(arr) ---------------- sum(arr)
    ↑                         ↑
Minimum                   Maximum
possible                  possible
maximum                    maximum
pages                       pages
</pre>

<p>For every candidate value, we ask:</p>

<pre>
"Can all books be allocated to k students
such that no student gets more than this many pages?"
</pre>

<p>The answer is either <strong>YES</strong> or <strong>NO</strong>, which creates the monotonic property needed for binary search.</p>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n log S)</code></p>

<p>where <code>n</code> is the number of books and <code>S = sum(arr)</code>.</p>

<p><strong>Space:</strong> <code>O(1)</code></p>

<hr>

<p><strong>Pattern:</strong> Binary Search / Binary Search on Answer / Greedy / Monotonic Search</p>

<p><strong>Key Idea:</strong> Binary search for the minimum possible maximum pages. For each candidate limit, greedily allocate contiguous books and count how many students are required. If the required students are within <code>k</code>, search left; otherwise, search right.</p>
