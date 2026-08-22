<h2>Infix to Postfix</h2>

<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>

<hr>

<p>Given a string <code>s</code> representing an infix expression, convert it into a postfix expression.</p>

<p>An <strong>infix expression</strong> has the operator between operands, such as <code>a+b</code>.</p>

<p>A <strong>postfix expression</strong> has the operator after the operands, such as <code>ab+</code>.</p>

<p>The operator precedence and associativity are:</p>

<ul>
<li><code>^</code> has the highest precedence and is <strong>right-associative</strong>.</li>
<li><code>*</code> and <code>/</code> have the next highest precedence and are <strong>left-associative</strong>.</li>
<li><code>+</code> and <code>-</code> have the lowest precedence and are <strong>left-associative</strong>.</li>
</ul>

<h3>Example 1</h3>

<pre>
Input: s = "a*(b+c)/d"

Output: "abc+*d/"

Explanation:
First, b+c becomes bc+.
Then a is multiplied with the result, giving abc+*.
Finally, the result is divided by d, giving abc+*d/.
</pre>

<h3>Example 2</h3>

<pre>
Input: s = "a+b*c+d"

Output: "abc*+d+"

Explanation:
Multiplication has higher precedence than addition,
so b*c is processed first. The expression is then
combined with a and d.
</pre>

<h3>Example 3</h3>

<pre>
Input: s = "(a+b)*(c+d)"

Output: "ab+cd+*"

Explanation:
The expressions inside both parentheses are converted
first, and then their results are multiplied.
</pre>

<h3>Approach</h3>

<ul>
<li>Use a <code>stack</code> to store operators and parentheses temporarily.</li>
<li>Traverse the infix expression from left to right.</li>
<li>If the current character is an operand, directly add it to the answer.</li>
<li>If the character is <code>'('</code>, push it onto the stack.</li>
<li>If the character is <code>')'</code>, pop operators from the stack and add them to the answer until <code>'('</code> is found.</li>
<li>Remove the <code>'('</code> from the stack.</li>
<li>If the current character is an operator, compare its precedence with the operator at the top of the stack.</li>
<li>Pop the stack operator if it has higher precedence.</li>
<li>If both operators have equal precedence, pop the stack operator when the current operator is left-associative.</li>
<li>Do not pop for equal-precedence <code>^</code> operators because <code>^</code> is right-associative.</li>
<li>Push the current operator onto the stack.</li>
<li>After traversing the expression, pop all remaining operators from the stack and add them to the answer.</li>
</ul>

<h3>Operator Precedence</h3>

<pre>
Operator        Precedence       Associativity

^               3                Right
* /             2                Left
+ -             1                Left
</pre>

<h3>Key Condition</h3>

<pre>
Pop the stack operator when:

1. Stack operator has higher precedence
   OR
2. Both have equal precedence AND current operator is left-associative

Exception:
^ is right-associative, so equal-precedence ^ operators are not popped.
</pre>

<h3>Complexity</h3>

<p><strong>Time:</strong> <code>O(n)</code></p>
<p><strong>Space:</strong> <code>O(n)</code></p>

<hr>

<p><strong>Pattern:</strong> Stack / Expression Conversion / Operator Precedence</p>

<p><strong>Key Idea:</strong> Add operands directly to the result and use a stack for operators. Pop operators according to precedence and associativity before pushing the current operator.</p>
