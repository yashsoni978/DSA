# 678. Valid Parenthesis String

**Difficulty:** Medium

## Problem Statement

Given a string `s` containing only three types of characters: `'('`, `')'`, and `'*'`, return `true` if `s` is valid.

The following rules define a valid string:

- Every `'('` must have a corresponding `')'`.
- Every `')'` must have a corresponding `'('`.
- `'('` must appear before its matching `')'`.
- `'*'` can be treated as:
  - `'('`
  - `')'`
  - an empty string `""`

---

## Examples

### Example 1

**Input:**
```text
s = "()"
```

**Output:**
```text
true
```

### Example 2

**Input:**
```text
s = "(*)"
```

**Output:**
```text
true
```

### Example 3

**Input:**
```text
s = "(*))"
```

**Output:**
```text
true
```

---

## Constraints

- `1 <= s.length <= 100`
- `s[i]` is `'('`, `')'`, or `'*'`.

---

## Approach

The optimal solution uses a **Greedy** approach.

We maintain two counters:

- `minOpen` → Minimum possible unmatched `'('`
- `maxOpen` → Maximum possible unmatched `'('`

### Processing each character

- If the character is `'('`
  - `minOpen++`
  - `maxOpen++`

- If the character is `')'`
  - `minOpen--`
  - `maxOpen--`

- If the character is `'*'`
  - Treat it as `')'` for the minimum count (`minOpen--`)
  - Treat it as `'('` for the maximum count (`maxOpen++`)

After each step:

- `minOpen = max(0, minOpen)`
- If `maxOpen < 0`, return `false` because there are too many closing brackets.

At the end:

- If `minOpen == 0`, the string is valid.
- Otherwise, it is invalid.

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)`

---

## Tags

- Greedy
- String
- Stack
