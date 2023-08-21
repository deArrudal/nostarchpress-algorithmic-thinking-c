# Unique Snowflakes

### Problem Description

You may have heard that no two snowflakes are alike. Your task is to write a program to determine whether this is really true. Your program will read information about a collection of snowflakes, and search for a pair that may be identical. Each snowflake has six arms. For each snowflake, your program will be provided with a measurement of the length of each of the six arms. Any pair of snowflakes which have the same lengths of corresponding arms should be flagged by your program as possibly identical.

<u>Summary</u>: Given a collection of snowflakes, we have to determine whether any of the snowflakes in the collection are identical. A snowflake is represented by six integers, where each integer gives the length of one of the snowflake’s arms. For example, this is a snowflake:

    3, 9, 15, 2, 1, 10

Snowflakes can also have repeated integers, such as:

    8, 4, 8, 9, 2, 8

We can think of each snowflake as a circle. Two snowflakes are identical if they are the same, if we can make them the same by moving rightward through one of the snowflakes, or if we can make them the same by moving leftward through one of the snowflakes.

### Input

The first line of input is an integer **n**, which gives the number of snowflakes that we’ll be processing. The value **n** will be between 1 and 100,000. Each of the following **n** lines represents one snowflake: each line has six integers, where each integer is at least zero and at most 10,000,000.

    2
    1 2 3 4 5 6
    4 3 2 1 6 5

### Output

The output will be a single line of text:

**If there are no identical snowflakes, print exactly:**

    No two snowflakes are alike.

**If there are at least two identical snowflakes, print exactly:**

    Twin snowflakes found.

<u>Requirement</u>: The time limit for solving the test cases is two seconds.
