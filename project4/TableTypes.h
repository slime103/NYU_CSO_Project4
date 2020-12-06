/*
*
* Author - Zachary Stephens
*
*/

#pragma once

typedef struct TLB
{
    unsigned char set;
    unsigned char tag;
    unsigned char ppn;
} TLB;

typedef struct Page
{
    unsigned char vpn;
    unsigned char ppn;
} Page;

typedef struct Cache
{
    unsigned char set;
    unsigned char tag;
    unsigned char blk0;
    unsigned char blk1;
    unsigned char blk2;
    unsigned char blk3;
} Cache;

//returns the TLBT
unsigned GetTLBT(unsigned virtualAddress);

//returns TLB index
unsigned GetTLBI(unsigned virtualAddress);

//returns the VPN
unsigned GetVPN(unsigned virtualAddress);

//returns the Offset
unsigned GetOffset(unsigned virtualAddress);

//returns Cache Index
unsigned GetCI(unsigned virtualAddres);

//return Cache Offset
unsigned GetCO(unsigned virtualAddres);

void PrintTLB(TLB tlb);

void PrintPage(Page page);

void PrintCache(Cache cache);

void PrintAddressBreakdown(unsigned virtualAddress);