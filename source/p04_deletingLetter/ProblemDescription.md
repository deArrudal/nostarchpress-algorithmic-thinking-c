# Deleting a Letter

### Problem Description

Petya has noticed that when he types using a keyboard, he often presses extra buttons and adds extra letters to the words. Of course, the spell-checking system underlines the words for him and he has to click every word and choose the right variant. Petya got fed up with correcting his mistakes himself, that’s why he decided to invent the function that will correct the words itself. Petya started from analyzing the case that happens to him most of the time, when all one needs is to delete one letter for the word to match a word from the dictionary. Thus, Petya faces one mini-task: he has a printed word and a word from the dictionary, and he should delete one letter from the first word to get the second one. And now the very non-trivial question that Petya faces is: which letter should he delete?

<u>**Summary**</u>: In this problem, we are given two strings where the first string has one more character than the second. Our task is to determine the number of ways in which one character can be deleted from the first string to arrive at the second string. For example, there is one way to get from *favour* to *favor*: we can remove the *u* from the first string. There are three ways to get from *abcdxxxef* to *abcdxxef*: we can remove any of the *x* characters from the first string.

### Input

The input data contains two strings, consisting of lower-case *Latin letters*. The length of each string is from **1** to **10<sup>6</sup>** symbols inclusive, the first string contains exactly **1** symbol more than the second one.

    abcdxxxef
    abcdxxef

### Output

In the first line output the number of positions of the symbols in the first string, after the deleting of which the first string becomes identical to the second one. In the second line output space-separated positions of these symbols in increasing order. The positions are numbered starting from **1**. If it is impossible to make the first string identical to the second string by deleting one symbol, output one number **0**.

    3
    5 6 7

<u>**Requirements**</u>: The time limit for solving the test cases is two seconds.
