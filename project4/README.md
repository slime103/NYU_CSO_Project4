# Project 4

__Due date: Saturday , December 5 at 11:55pm.__

---
**You may discuss any of the assignments with your classmates and instructors (or anyone else) but
all work for all assignments must be entirely your own.
Any sharing or copying of assignments will be considered cheating (this includes posting of partial or complete solutions on
Piazza, GitHub public repositories or any other public forum). If you get significant help
from anyone, you should acknowledge it in your submission (and your grade will be proportional to the part
that you completed on your own).
You are responsible for every line in your program: you need to know what it does and why.**


## Programming requirements:

- The programs should be leak-free: any memory that is allocated should be freed before the program terminates. (Although in this project, there should not be a need to allocate any memory. )
- __The programs have to be documented! Any file that you edit should have preamble
 including your name as the author, description of the purpose of the program and
 inline comments in the functions that you implement. All functions except for `main()` should
 have descriptions of function parameters, returned value and a summary of what the function does.__

- The code has to follow C programming conventions.
- The code has to be formatted properly.  

The program should automate the work we did in working with the TLB. The example below are from the VPNCaching powerpoint on NYU Classes. You can map the few examples below 
that presentation. Assume all entries are Valid, so do not implement a Valid Flag in either cache.

Your program should be able to read information about an existing Translation Lookaside Buffer (TLB), the Virtual Address Page table, and Physical Memory Direct Memory cacing.
Based on storing this information, your program will prompt the user a virtual address (in hex) and output the byte at that location.
Your program may als print out "Can not be determined", if the data is not available.
The first part of your program will be to read in 3 types of data - TLB, Page Table and Physical Memory Cache
A format sample is below:
```
Format of Record Type 2: TLB Contents
TLB,Set index, Tag, PPN
Examples
TLB,0,09,0D   - this means the TLB holds PPN 0D at set index 0 with a tag of 09
TLB,0,07,02   - this means the TLB holds VPN 02 at set index 0 with a tag of 07
```
Format of Record Type 2: Virtual Page Table
Page, Virtual Page Number, Physical Page Number
Examples:
Page,0,28
Page,2,33
Page,3,02

Format of Record Type 3: Physical Page Cache
Cache,Cache Index,Tag,ByteOffset0, ByteOffset1,ByteOffset2, ByteOffet3
Cache,0,19,99,11,23,11
Cache,2,1B,02,04,06,08
Cache,4,32,43,6D,8F,09
Cache,5,0D,36,72,F0,1D

Format of Record Type 4:  DONE
DONE
Indicates no more input of the TLB, Page Table or Cache. It is now time to prompt the user for a Virtual Address and output the byte (or can not be determined) at that location.

3 Times do the following;
Print out "Enter Virtual Address:", then input the Virtual Address in Hex
Output the byte found in Hex, or " Can not be determined"


__Deliverables__
Implementation of the program in `Project4.c` file.





