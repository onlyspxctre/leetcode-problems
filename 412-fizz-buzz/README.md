# 412: Fizz Buzz

Ah, the classic "FizzBuzz".

Given an integer `n`, return a string array answer **(1-indexed)** where:

`answer[i] == "FizzBuzz"` if `i` is divisible by `3` and `5`.
`answer[i] == "Fizz"` if `i` is divisible by `3`.
`answer[i] == "Buzz"` if `i` is divisible by `5`.
`answer[i] == i` (as a string) if none of the above conditions are true.

The hardest part about doing this question in C was honestly manipulating strings.

We will first `malloc` the string array `ret` with size `n * sizeof(char*)`. We will then iterate from `0` to `n` and check if `(i + 1) % 15` (a common multiple of `3` and `5`) is a multiple of `3`, `5`, or both.

For the cases `3`, `6`, `9`, and `12`, these are only multiples of `3`, so we will `malloc` a string buffer at `ret[i]` of length `5` and copy `"Fizz"` into the buffer.

For the cases `5` and `10`, these are only multiples of `5`, so we will `malloc` a string buffer at `ret[i]` of length `5` and copy `"Buzz"` into the buffer.

For the case `0`, `15` is divisible by `(i + 1)`, which means that `(i + 1)` is a multiple of both `3` and `5`. We will `malloc` a string buffer at `ret[i]` of length `9` and copy `"FizzBuzz"` into the buffer.

After we are done, we will return the string array `ret`.

The time complexity is O(n), and the space complexity is O(n) since we have to create a new array of Fizzes and Buzzes.
