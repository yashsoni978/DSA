<h2>37. Sudoku Solver</h2>
<img src="https://img.shields.io/badge/Difficulty-Hard-red" alt="Difficulty: Hard"/>
<hr>

<p>Write a program to solve a Sudoku puzzle by filling the empty cells so that every row, column, and <strong>3 × 3 box</strong> contains the digits <code>1-9</code> exactly once.</p>

<p><strong>Example:</strong></p>
<pre>
<strong>Input:</strong>
A partially filled 9 × 9 Sudoku board

<strong>Output:</strong>
The completed valid Sudoku board </pre>

<p><strong>Approach:</strong></p>
<p>Use <strong>Backtracking</strong>. Find an empty cell and try digits <code>1-9</code>. Place a digit only if it is valid in its row, column, and 3 × 3 box. If the choice leads to an invalid state, undo it and try another digit.</p>

<p><strong>Key Observation:</strong></p>
<p>Sudoku can be solved by making a choice for an empty cell and <strong>backtracking whenever that choice cannot lead to a valid solution</strong>.</p>

<p><strong>Time Complexity:</strong> <code>O(9<sup>m</sup>)</code>, where <code>m</code> is the number of empty cells.</p>

<p><strong>Space Complexity:</strong> <code>O(m)</code> recursion stack.</p>
