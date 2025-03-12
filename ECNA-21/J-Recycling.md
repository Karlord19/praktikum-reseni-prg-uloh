# J. Recycling  

**Time Limit:** 1 second  
**Memory Limit:** 1024 megabytes  

Heck S. Quincy (or Hex as his friends call him) is in charge of recycling efforts in the Quad Cities within the greater Tri-state area as well as the Twin Cities in the Lone Star State. One of the programs he oversees is the placement of large recycling bins at various locations in the cities. Transporting these bins is very expensive, so he tries to keep them at any given location for as long as possible, emptying them once a week. He's willing to keep a bin at a given location **as long as it is full at the end of each week**.  

Hex has very reliable estimates of the amount of recyclable materials (in cubic meters) that he can expect each week at each location. Given this information, he would like to know when to install the recycling bin of an appropriate size to **maximize the amount of material recycled**. He will keep the bin at that location **up to (but not including) the week when they don't expect it to be filled to capacity**.  

For example, suppose Hex has the following estimates for the next **seven** weeks:  

```
2 5 7 3 5 10 2
```

Hex has several options for placing bins, including:  

- A **capacity-2** bin from **week 1** until **week 7**, recycling **14m³**  
- A **capacity-5** bin from **week 2** until **week 3**, recycling **10m³**  
- A **capacity-3** bin from **week 2** until **week 6**, recycling **15m³** (**this is the maximum possible**)  

Hex **would not** place a **capacity-5** bin from **week 2** until **week 6**, since it would not be filled in **week 4**.  

## Input  

Input starts with a line containing a single positive integer $n$ $(n \leq 100000)$ indicating the number of weeks for which Hex has estimates. Weeks are numbered **1** to **n**.  

Following this are $n$ non-negative integers listing, in order, the amount of recycling expected for each of the $n$ weeks. These values may be over multiple lines.  

## Output  

Output three integers $s \ e \ r$ where:  

- $s$ and $e$ are the **start and end weeks** for when to place the bin to maximize the total recycling.  
- $r$ is the **maximum amount** of recycled material.  
- If there are **two or more time periods** that lead to the same maximum amount, output the **one with the smallest $s$** value.  

## Examples  

### Input  
```
7
2 5 7 3 5
10 2
```
### Output  
```
2 6 15
```

### Input  
```
8
2 5 7 3 5
10 2 4
```
### Output  
```
1 8 16
```  
