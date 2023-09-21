# Money Grubbers

### Problem Description

It is sometimes tricky to gure out the cheapest way to buy things, even in the supermarket where the price of all goods are listed clearly. Having a sharp mind (a consequence of regularly taking part in online programming contests), you should have no problem in seeing through those schemes. But what about your Mum? It is your responsibility as her son/daughter to write her a program that computes the lowest price to buy things in the supermarket, thus helps her to save money.

<u>**Summary**</u>: You want to buy apples, so you go to an apple store. The store has a price for buying one apple - for example, $1.75. The store also has **m** pricing schemes, where each pricing scheme gives a number **n** and a price **p** for buying **n** apples. For example, one pricing scheme might state that three apples cost a
total of $4.00; another might state that two apples cost a total of $2.50. You want to buy at least **k** apples and to do so as cheaply as possible.

### Input

The input consists of more than a hundred test cases, each concerning a different item. The first line of each case gives the unit price of buying an item, then a non-negative integer **m** (≤ 20). This is followed by **m** lines each containing two numbers **n** and **p** (1 < n ≤ 100), which means that you can buy **n** such items for $**p**. Finally there is a line containing a list of positive integers **k** (≤ 100).

Each price in the input is a floating-point number with exactly **two decimal digits**.

Sample Input:

    22.00 2
    2 22.00
    4 60.00
    2 4
    25.00 2
    2 48.00
    2 46.00
    2

### Output

For each of them your program should print the lowest price you need to get **k** items. Note that you do not have to buy exactly **k** items; you may consider buying more than **k** items, and giving the unneeded items to your dear neighbours, if you can save money in this way. Note that all prices **p** given in the input are floating-point numbers in exactly 2 decimal places, with 0 < **p** < 1000.

Sample output:

    Case 1:
    Buy 2 for $22.00
    Buy 4 for $44.00
    Case 2:
    Buy 2 for $46.00

<u>**Requirements**</u>: The time limit for solving the test cases is **three** seconds.
