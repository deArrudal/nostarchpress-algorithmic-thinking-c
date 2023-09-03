# Compound Words

### Problem Description

You are to find all the two-word compound words in a dictionary. A two-word compound word is a word in the dictionary that is the concatenation of exactly two other words in the dictionary.

<u>**Summary**</u>: We are given a wordlist in which each word is a lowercase string. For example, we might be given the wordlist containing *crea*, *create*, *open*, and *te*. The task is to determine the strings in the wordlist that are compound words: the concatenation of exactly two other strings in the wordlist. For the given example, only the string *create* is such a compound word, because it is the concatenation of *crea* and *te*.

### Input

The input is one string (word) per line, in alphabetical order. We’ll get at most **120,000** strings.

    a
    alien
    born
    less
    lien
    never
    nevertheless
    new
    newborn
    the
    zebra

### Output

The problem requires us to output each compound word on its own line, in alphabetical order.

    alien
    newborn

<u>**Requirements**</u>: The time limit for solving the test cases is three seconds.
