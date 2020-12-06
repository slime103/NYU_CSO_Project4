/*
*
* Author - Zachary Stephens
*
* Run with -
* gcc -Wall project4.c TableTypes.c
* ./a.out < Project4Input.txt
*/

#include<stdio.h>
#include "TableTypes.h"

//unsigned int for set index in all
//TLB Array of unsigned short ints (two bytes are tag and ppn)
//Page Array of unsigned chars (one byte ppn)
//Cache Array of chache block data types (5 chars, tag and 4 data offset blocks)
int main()
{
//Step 0 Create arrays

TLB aTLB[50];
Page aPage[50];
Cache aCache[50];

int tlbi = 0;
int pagei = 0;
int cachei = 0;

char temp;

char input;

//Step 1 read in from file
while (scanf("%c", &input))
{
    if (input == 'T')
    {
        printf("TLB - ");
        TLB tlb;
        scanf("LB, %hhx %c %hhx %c %hhx\n", &tlb.set, &temp, &tlb.tag, &temp, &tlb.ppn);
        PrintTLB(tlb);
        aTLB[tlbi] = tlb;
        tlbi++;
    }
    else if (input == 'P')
    {
        printf("Page - ");
        Page page;
        scanf("age, %hhx %c %hhx\n", &page.vpn, &temp, &page.ppn);
        PrintPage(page);
        aPage[pagei] = page;
        pagei++;
    }
    else if (input == 'C')
    {
        printf("Cache - ");
        Cache cache;
        scanf("ache, %hhx %c %hhx %c %hhx %c %hhx %c %hhx %c %hhx\n", &cache.set, &temp, &cache.tag, &temp, &cache.blk0, &temp, &cache.blk1, &temp, &cache.blk2, &temp, &cache.blk3);
        PrintCache(cache);
        aCache[cachei] = cache;
        cachei++;
    }
    else if (input == 'D')
    {
        printf("DONE DONE\n\n");
        scanf("ONE DONE\n");
        break;
    }
}

    //Clear input buffer
    freopen("/dev/tty", "r", stdin);
    //while ((getchar()) != '\n');

    //Step 2 Recieve input and retrieve result
    unsigned entry = 0;
    unsigned char validPPN = 0;
    unsigned char byteFound = 0;

    for (int i = 0; i < 3; i++)
    {
        printf("Enter Virtual Address: ");
        scanf("%x", &entry);
        //printf("You entered: %x\n", entry);
        PrintAddressBreakdown(entry);


        //Check Table
        for (int j = 0; j < tlbi; j++)
        {
            //Find Set
            if (aTLB[j].set == GetTLBI(entry))
            {
                //Find Tag
                if (aTLB[j].tag == GetTLBT(entry))
                {
                    printf("PPN %x found in TLB.\n", aTLB[j].ppn);
                    validPPN = aTLB[j].ppn;
                    break;
                }
            }
        }

        if (!validPPN)
        {
            //Check Page
            for (int k = 0; k < pagei; k++)
            {
                //Check VPN
                if (aPage[k].vpn == GetVPN(entry))
                {
                    printf("PPN %x found in Page.\n", aPage[k].ppn);
                    validPPN = aPage[k].ppn;
                    break;
                }
            }
        }

        if (validPPN)
        {
            for (int m = 0; m < cachei; m++)
            {
                if (aCache[m].set == GetCI(entry))
                {
                    if (aCache[m].tag == validPPN)
                    {
                        switch (GetCO(entry))
                        {
                            case 0: printf("Cache hit: %x\n", aCache[m].blk0);
                            break;
                            case 1: printf("Cache hit: %x\n", aCache[m].blk1);
                            break;
                            case 2: printf("Cache hit: %x\n", aCache[m].blk2);
                            break;
                            case 3: printf("Cache hit: %x\n", aCache[m].blk3);
                            break;
                        }
                        byteFound = 1;
                    }
                }
            }
        }
        if (!byteFound)
        {
            printf("Can not be determined\n");
        }

        validPPN = 0;
        byteFound = 0;

    }
}