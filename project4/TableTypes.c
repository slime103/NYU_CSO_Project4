/*
*
* Author - Zachary Stephens
*
*/

#include<stdio.h>
#include "TableTypes.h"

//Virtual Address is 14 bits stored in 16 bit short
//returns bits 8-13 inclusive
unsigned GetTLBT(unsigned virtualAddress)
{
    return (virtualAddress >> 8) & 0b111111;
}

//returns bits 6 & 7
unsigned GetTLBI(unsigned virtualAddress)
{
    return (virtualAddress >> 6) & 0b11;
}

//returns bits 6-13 inclusive
unsigned GetVPN(unsigned virtualAddress)
{
    return (virtualAddress >> 6) & 0b11111111;
}

//returns bits 0-5 inclusive
unsigned GetOffset(unsigned virtualAddress)
{
    return virtualAddress & 0b111111;
}

//returns bits 0 and 1
unsigned GetCO(unsigned virtualAddress)
{
    return virtualAddress & 0b11;
}

//returns bits 3-6 inclusive
unsigned GetCI(unsigned virtualAddress)
{
    return (virtualAddress >> 2) & 0b1111;
}

void PrintTLB(TLB tlb)
{
    printf("Set: %x, Tag: %x, PPN: %x\n", tlb.set, tlb.tag, tlb.ppn);
}

void PrintPage(Page page)
{
    printf("VPN: %x, PPN: %x\n", page.vpn, page.ppn);
}

void PrintCache(Cache cache)
{
    printf("Set: %x, Tag: %x, blk0: %x, blk1: %x, blk2: %x, blk3: %x\n", cache.set, cache.tag, cache.blk0, cache.blk1, cache.blk2, cache.blk3);
}

void PrintAddressBreakdown(unsigned virtualAddress)
{
    printf("TLBT: %x, TLBI: %x, TLBO: %x, Page VPN: %x, CI: %x, CO: %x\n", GetTLBT(virtualAddress), GetTLBI(virtualAddress), GetOffset(virtualAddress),
    GetVPN(virtualAddress), GetCI(virtualAddress), GetCO(virtualAddress));
}