<h2>29. Divide Two Integers</h2>
<img src="https://img.shields.io/badge/Difficulty-Medium-orange" alt="Difficulty: Medium"/>
<hr>

<h3>Problem Statement</h3>

<p>
Given two integers <b>dividend</b> and <b>divisor</b>, divide the two integers
without using multiplication, division, or the modulo operator.
</p>

<p>
Return the quotient obtained by dividing the dividend by the divisor.
The fractional part of the quotient should be truncated toward zero.
</p>

<p>
If the quotient overflows a signed 32-bit integer, return
<b>INT_MAX = 2<sup>31</sup> - 1</b>.
</p>

<h3>Example 1</h3>

<pre>
Input: dividend = 10, divisor = 3
Output: 3
</pre>

<p>
Explanation: 10 / 3 = 3.333..., which is truncated toward zero to give 3.
</p>

<h3>Example 2</h3>

<pre>
Input: dividend = 7, divisor = -3
Output: -2
</pre>

<p>
Explanation: 7 / -3 = -2.333..., which is truncated toward zero to give -2.
</p>

<h3>Example 3</h3>

<pre>
Input: dividend = -2147483648, divisor = -1
Output: 2147483647
</pre>

<p>
Explanation: The actual quotient is 2147483648, which exceeds the maximum
signed 32-bit integer. Therefore, return 2147483647.
</p>

<h3>Approach</h3>

<p>
Use <b>Bit Manipulation</b> to calculate the quotient efficiently.
Repeatedly subtracting the divisor would be too slow for large inputs.
Instead, use bit shifts to subtract the largest possible multiples of the
divisor.
</p>

<ol>
    <li>
        Handle the overflow case where the dividend is INT_MIN and the divisor
        is -1.
    </li>
    <li>
        Determine whether the result should be positive or negative.
    </li>
    <li>
        Convert both numbers to a wider integer type and work with their
        absolute values to avoid overflow when handling INT_MIN.
    </li>
    <li>
        Starting from bit position 31 and moving downward, check whether
        the divisor shifted left by that position can be subtracted from
        the remaining dividend.
    </li>
    <li>
        When possible, subtract that shifted value and set the corresponding
        bit in the quotient.
    </li>
    <li>
        Apply the correct sign to the quotient and return the result.
    </li>
</ol>

<h3>Complexity</h3>

<pre>
// TC: O(1) — at most 32 bit positions are checked
// SC: O(1)
</pre>

<h3>Key Point</h3>

<p>
Left shifting the divisor by <b>i</b> positions multiplies it by
<b>2<sup>i</sup></b>. By subtracting the largest possible shifted values,
we calculate the quotient using binary representation instead of repeated
subtraction.
</p>
