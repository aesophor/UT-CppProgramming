# Factorial
Write a function to calculate factorial of a given number N.
* If N < 0, throw an exception with message "argument out of bound".
* If the result > INT_MAX, throw an exception with message "number too large".

## Algorithm
Dynamic Programming (bottom-up)

## Result
```
$ ./main
Calculate factorial of n: -1
argument out of bound

$ ./main
Calculate factorial of n: 0
1

$ ./main
Calculate factorial of n: 2
2

$ ./main
Calculate factorial of n: 3
6

$ ./main
Calculate factorial of n: 4
24

$ ./main
Calculate factorial of n: 5
120

$ ./main
Calculate factorial of n: 12
479001600

$ ./main
Calculate factorial of n: 13
number too large
```
