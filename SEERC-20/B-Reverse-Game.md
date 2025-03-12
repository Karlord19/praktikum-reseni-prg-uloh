# B. Reverse Game

**Time Limit:** 1 second  
**Memory Limit:** 256 megabytes  

Alice and Bob are playing a turn-based game. The rules of the game are as follows:  

- At the beginning of the game, some binary string $s$ is chosen.  
- On their turn, a player has to choose some substring $t$ of $s$, equal to one of **10, 110, 100, 1010**. Then the player has to reverse $t$. For example, if $s = 010101$, the player can select substring $t = 1010$ and reverse it, obtaining $s = 001011$.  
- The player who **can't** make a move (who can't choose an appropriate substring $t$) loses.  
- The players **cannot** skip a turn.  

Which player has the winning strategy, if Alice moves first?  

A string $a$ is a **substring** of a string $b$ if $a$ can be obtained from $b$ by deletion of several (possibly, zero or all) characters from the beginning and several (possibly, zero or all) characters from the end.  

## Input  

The only line of the input contains a binary string $s$ $(1 \leq |s| \leq 10^6)$ — the string with which Alice and Bob play.  

## Output  

If Alice wins, output `Alice`. Otherwise, output `Bob`.  

## Examples  

### Input  
```
010
```
### Output  
```
Alice
```

### Input  
```
1111
```
### Output  
```
Bob
```

### Input  
```
1010
```
### Output  
```
Bob
```

### Input  
```
1010001011001
```
### Output  
```
Alice
```

## Note  

In the first sample, Alice can choose substring `10` of `010` and reverse it, obtaining string `001`. Bob can't make any move with this string and loses.  

In the second sample, Alice can't make a single move and loses.  
