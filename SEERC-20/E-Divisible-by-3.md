# E. Divisible by 3

**Time Limit:** 2 seconds  
**Memory Limit:** 256 megabytes  

For an array $[b_1,b_2,\dots,b_m]$ of integers, let's define its weight as the sum of pairwise products of its elements, namely as the sum of $b_i b_j$ over $1 \leq i < j \leq m$.  

You are given an array of $n$ integers $[a_1,a_2,\dots,a_n]$, and are asked to find the number of pairs of integers $(l,r)$ with $1 \leq l \leq r \leq n$, for which the weight of the subarray $[a_l,a_{l+1},\dots,a_r]$ is divisible by $3$.  

## Input  

The first line of the input contains a single integer $n$ $(1 \leq n \leq 5 \cdot 10^5)$ — the length of the array.  

The second line contains $n$ integers $a_1,a_2,\dots,a_n$ $(0 \leq a_i \leq 10^9)$ — the elements of the array.  

## Output  

Output a single integer — the number of pairs of integers $(l,r)$ with $1 \leq l \leq r \leq n$, for which the weight of the corresponding subarray is divisible by $3$.  

## Examples  

### Input  
```
3
5 23 2021
```
### Output  
```
4
```

### Input  
```
5
0 0 1 3 3
```
### Output  
```
15
```

### Input  
```
10
0 1 2 3 4 5 6 7 8 9
```
### Output  
```
20
```

## Note  

In the first sample, the weights of exactly $4$ subarrays are divisible by $3$:  

- $weight([5]) = weight([23]) = weight([2021]) = 0$  
- $weight([5,23,2021]) = 56703 = 3 \cdot 41 \cdot 461$  
