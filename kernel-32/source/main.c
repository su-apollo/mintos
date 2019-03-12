#include "types.h"

void kPrintString(int iX, int iY, cont char* pcString);

void main(void)
{
    kPrintString(0, 3, "Kernel Start");
}

void kPrintString(int iX, int iY, const char* pcString)
{
    CHARACTER* psScreen = (CHARACTER*) 0xB8000;
    int i;

    pstScreen += (iY * 80)  iX;
    for (i = 0; pcString[i] != 0; ++i)
    {
        pstScreen[i].bCharactor = pcString[i];
    }
}