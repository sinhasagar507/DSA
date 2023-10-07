/* 
1. How the Dutch National Flag algorithm is applied to QuickSort?
2. Sort around a given range
3. Focus on algorithms - don't use the OOPs concept now

DSA:
1. Python Regex question - hackerrank - Round-2

Notes to be referred and Questions posed:
2. In-built sorting algorithms in sorting algorithms
3. HeapSort is not used as a standard algorithm in library funtions
4. Memory stack vs.memory heap
5. An in-place algorithm to solve the separation of two types of arrays problem 
6. Binary Coefficients question on LeetCode
7. When to use the goto statement?
8. If not learnt templates and STL, then what have you learnt?

1-D arrays:
1. Kadane's Algorithm - maximum subarray 	
4. Minimum Flips for same elements AND maximum subarray sum PI 


Web/Data Scraping Tools used: 
1. Scrappy.io 
2. WebScraping.io 
3. Octoparse 
4. Email Extractor and related stuff 
5. Google Dorking: Oh yeah..., I can try this stuff in pastime - It seems interesting 
*/


/*Why 2s complement is used 

Arithmetic operations are easier to perform using 2's complement representation in binary for several reasons:
 - Simplicity: In 2's complement representation, addition and subtraction can be performed with the same binary addition operation used for unsigned (positive) numbers. This consistency simplifies the hardware and software used to implement arithmetic operations.
 - No Special Cases: There are no special cases or additional rules required for handling negative numbers. Positive and negative numbers are treated uniformly in arithmetic operations.
 - Overflow Handling: In 2's complement, overflow conditions are easily detectable and can be handled consistently. Overflow occurs when the result of an addition or subtraction operation exceeds the representational limits of the given number of bits. Detecting overflow is straightforward, and it allows for proper error handling.
 - Efficient Hardware: The use of 2's complement simplifies the design of digital circuits and hardware for arithmetic operations. Hardware can be designed to perform binary addition and subtraction operations without needing to differentiate between positive and negative numbers.

Cancellation Property: In 2's complement, subtracting a number is equivalent to adding its 2's complement. This cancellation property simplifies subtraction operations. For example, A - B is equivalent to A + (-B), where -B is the 2's complement of B.

Range and Symmetry: The range of representable integers is symmetric around zero. In an n-bit 2's complement representation, you can represent integers from -2^(n-1) to 2^(n-1)-1. This symmetry makes it easier to reason about the range of values.

Negative Sign Bit: The most significant bit (leftmost bit) in a 2's complement number serves as the sign bit. It clearly indicates whether the number is positive or negative, simplifying the interpretation of results.

Conversion Between Signed and Unsigned: It's relatively easy to convert between signed and unsigned representations by changing the interpretation of the most significant bit. This allows for flexibility in how data is represented and manipulated.

Complement Operations: 2's complement has useful properties, such as the ability to negate a number by taking its 2's complement. This simplifies operations like negation and bitwise NOT.

Overall, the 2's complement representation strikes a balance between simplicity, efficiency, and consistency in arithmetic operations. It is widely used in computer systems and digital hardware because it simplifies both the design and implementation of arithmetic operations, making them easier to perform and understand
*/

/*
MAX value of N                       Time complexity
   10^9                              O(logN) or Sqrt(N)
   10^8                              O(N) Border case
   10^7                              O(N) Might be accepted
   10^6                              O(N) Perfect
   10^5                              O(N * logN)
   10^4                              O(N ^ 2)
   10^2                              O(N ^ 3)
   <= 160                            O(N ^ 4)
   <= 18                             O(2N*N2) 
   <= 10                             O(N!), O(2N)
*/