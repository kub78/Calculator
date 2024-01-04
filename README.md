# Calculator in C

This is my university project - a calculator that can perform normal operations {+, -, *, %}, as well as the bitwise operations {&, |, ^, ~} on numbers in binary, octal and hexadecimal number systems.

## Usage examples

### Example 1:

**Input:**
```c
0xdf4 + 0x31c
```

**Output:**
```c
0x1110 (4368)
```

### Example 2:
**Input:**
```c
0xdf4 + 100011
```
**Output:**
```c
Error: the number systems do not match
```

### Example 3:
**Input:**
```c
10 | 101
```

**Output:**
```c
111 (7)
```

### Notes

- Writing numbers in hexadecimal notation always starts with 0x.
- Writing numbers in the octal number system always starts with 0.