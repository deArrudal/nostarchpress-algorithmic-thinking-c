# Food Lines

### Problem Description

There are **n** lines of people waiting for food, and the number of people waiting in each line is known. Then, each of **m** new people will arrive, and they will join the shortest line (the line with the fewest number of people). Our task is to determine the number of people in each line that each of the **m** people joins.

### Input

The first line contains two positive integers, **n** and **m**, giving the number of lines and number of new people, respectively. **n** and **m** are at most 100. The second line contains **n** positive integers, giving the number of people in each line before the new people arrive. Each of these integers is at most 100.


    3 4
    3 2 5

### Output

For each of the **m** new people, output a line containing the number of people in the line that they join.


    2
    3
    3
    4

<ins>**Requirement:**</ins> The time limit for solving the test case is three seconds.