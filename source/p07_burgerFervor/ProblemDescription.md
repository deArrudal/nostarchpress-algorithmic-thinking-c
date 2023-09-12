# Burger Fervor

### Problem Description

Homer Simpson, a very smart guy, likes eating Krusty-burgers. It takes Homer **m** minutes to eat a Krusty-burger. However, there’s a new type of burger in Apu’s Kwik-e-Mart. Homer likes those too. It takes him **n** minutes to eat one of these burgers. Given **t** minutes, you have to find out the maximum number of burgers Homer can eat without wasting any time. If he must waste time, he can have beer.

<u>**Summary**</u>: Homer wolud like to spend the entire **t** minutes eating burgers. However, doing so isn’t always possible. For example, if *m = 4*, *n = 9*, and *t = 15*, then no combination of the 4-minute and 9-minute burgers can take him exactly 15 minutes to eat. If that’s the case, he’ll spend as much time as possible eating burgers and then fill the rest of the time drinking beer. Our task is to determine the number of burgers that Homer can eat.

### Input

We read test cases until there is no more input. Each test case is represented by a line of three integers: **m**, the number of minutes it takes to eat the first kind of burger; **n**, the number of minutes it takes to eat the second kind of burger; and **t**, the number of minutes that Homer will spend eating burgers and drinking beer. Each **m**, **n**, and **t** value is less than **10,000**. Input is terminated by **EOF**.

Sample Input:

    3 5 54
    3 5 55

### Output

For each test case, print in a single line:

* If Homer can spend exactly **t** minutes eating burgers, then output the maximum number of burgers that he can eat.
* Otherwise, output the maximum number of burgers that Homer can eat when maximizing his time eating burgers, a space, and the number of remaining minutes (during which he’ll drink beer).

Sample output:

    18
    17

<u>**Requirements**</u>: The time limit for solving the test cases is **three** seconds.
