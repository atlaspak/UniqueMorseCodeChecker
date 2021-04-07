# Unique Morse Code Words Solution

This particular code library is a solution to the Unique Code conversion with
avoiding cache misses. Using minimum memory and cpu is the first goal of the
solution instead of quick solution.

## Problem

Every letter of the basic Latin Alphabet has a matching morse word. These words have at most four chars and at least two.
The problem is to check whether given words have the same morse sequence on the
given word array and eliminate them.

### Morse Array (a - z)
```C++
[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
```

## Solution
Every letter is a key to a morse word that stored on a fixed array.
Comparator function has two iterators that adressed on a latin word index.
Latin chars considered as indexes so every comparision can be done at fixed
morse word array. Hence string operations are avoided.

### Note
Please feel free to send feedback or review the code to improve efficiency. Every contribution is appreciated.

### Leetcode link:
<https://leetcode.com/problems/unique-morse-code-words/>