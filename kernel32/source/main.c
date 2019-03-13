#include "types.h"

void kPrintString(int iX, int iY, const char* pcString);

void main(void)
{
    kPrintString(0, 3, "Kernel Start");

    while(1);
}

void kPrintString(int iX, int iY, const char* pcString)
{
    CHARACTER* psScreen = (CHARACTER*) 0xB8000;
    int i;

    psScreen += (iY * 80) + iX;
    for (i = 0; pcString[i] != 0; ++i)
    {
        psScreen[i].bCharactor = pcString[i];
    }
}