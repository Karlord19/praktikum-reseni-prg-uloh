# F. Nesr El Sieve  

**Time Limit:** 1 second  
**Memory Limit:** 256 megabytes  

---

### **Input File:** `sieve.in`  

*"I graduated from Engineering Ain Shams University" - said Omda.*  

As we all know, engineers are the third known gender in Egypt. As an engineer, Omda was trying to add a little engineering to his sick rhymes by finding the greatest common divisor of two rap tracks **A** and **B**.  

A rap track is a string consisting of lowercase English letters.  

A divisor of a track **S** is another track **T** such that **T** can be concatenated some number of times to make **S**.  

More formally, **T** is a divisor of **S** if:  

$$ T_1 + T_2 + T_3 + ... + T_{\frac{|S|}{|T|}} = S $$  

where:  

$$ T_i = T_{i-1} $$  

The greater of the two divisors is the one with the longer length.  

Help Omda find the greatest common divisor of tracks **A** and **B**.  

It is guaranteed that there is always a solution.  

---

## **Input**  

- The first line contains the number of test cases **T** $ (1 \leq T \leq 10^5) $.  
- The first line of each test case contains a string **A** $ (1 \leq |A| \leq 10^3) $.  
- The second line of each test case contains a string **B** $ (1 \leq |B| \leq 10^3) $.  
- The **total length** of both strings over all test cases **does not exceed** $ 2 \times 10^3 $.  

---

## **Output**  

For each test case, print **one integer** representing the **length of the greatest common divisor** of the two given rap tracks.  

---

## **Example**  

### **Input:**  
```
2
abcabc
abc
cccccccc
cc
```

### **Output:**  
```
3
2
```
