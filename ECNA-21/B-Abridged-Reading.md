# B. Abridged Reading  

**Time Limit:** 4 seconds  
**Memory Limit:** 1024 megabytes  

Miss Othmar is a grade school teacher who uses a very interesting textbook in her science class. All of the chapters in the book have material that depends on at most one previous chapter's material, while several chapters are labeled **"Culminating Concept"** chapters that have no chapters depending on them. These chapters represent the culmination of all the prerequisite material that must be read before them.  

Chapters that are **not** Culminating Concept chapters are referred to as **"prerequisite chapters."**  

Because of various delays caused by the pandemic, Miss Othmar is far behind where she wants to be in the class. It's too late to cover **all** of the Culminating Concept chapters (and their required prerequisite chapters), so she has decided to cover **just two** of them. To minimize the workload for her students, she wants to pick the **two Culminating Concept chapters that require the least amount of reading**—including both the chapters themselves and their prerequisite chapters.  

## Input  

The first line contains two integers $n$ and $m$:  

- $n$ $(2 \leq n \leq 1000)$ — the number of chapters (numbered **1** to **n**)  
- $m$ $(0 \leq m < n)$ — the number of chapter dependencies  

The next $n$ values represent the **number of pages** in each chapter. These values will be on one or more lines, and the number of pages in any chapter is at most **1000**.  

The next $m$ lines each contain two integers $a \ b$ $(1 \leq a < b \leq n)$, indicating that **chapter $a$ must be read before chapter $b$**.  

No chapter appears as the second integer in these lines more than once. There will always be **at least two** Culminating Concept chapters.  

## Output  

Print a single integer: the **minimum number of pages** that need to be read in order to complete **two** Culminating Concept chapters.  

## Examples  

### Input  
```
7 6
10 9 6 4 2 10 12
1 2
1 3
2 4
2 5
3 6
3 7
```
### Output  
```
25
```

### Input  
```
4 2
10 7 4 6
1 4
2 3
```
### Output  
```
27
```
