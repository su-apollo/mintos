#include "types.h"
#include "page.h"

void kPrintString(int iX, int iY, const char* pcString);
BOOL kIsMemoryEnough();
BOOL kInitializeKernel64Area();

void main()
{
    kPrintString(0, 3, "Protected kernel start.");

    kPrintString(0, 4, "Minimum memory size check. [    ]");
    if( kIsMemoryEnough() == FALSE )
    {
        kPrintString(28, 4, "Fail");
        kPrintString(0, 5, "Not enough memory. Beaver-OS requires over 64Mbyte memory.");
        while( 1 ) ;
    }
    else
    {
        kPrintString(28, 4, "Pass");
    }
    
    kPrintString(0, 5, "Long kernel area initialize. [    ]");
    if( kInitializeKernel64Area() == FALSE )
    {
        kPrintString(30, 5, "Fail");
        kPrintString(0, 6, "Kernel area initialization fail.");
        while(1) ;
    }
    kPrintString(30, 5, "Pass");

    kPrintString( 0, 6, "Long page tables initialize. [    ]" );
    kInitializePageTables();
    kPrintString( 30, 6, "Pass" );

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

BOOL kIsMemoryEnough()
{
    DWORD* pdwCurrentAddress;
   
    pdwCurrentAddress = (DWORD*) 0x100000;
    
    while((DWORD) pdwCurrentAddress < 0x4000000)
    {
        *pdwCurrentAddress = 0x12345678;
        
        if( *pdwCurrentAddress != 0x12345678)
        {
           return FALSE;
        }
        
        pdwCurrentAddress += (0x100000 / 4);
    }
    return TRUE;
}

BOOL kInitializeKernel64Area()
{
    DWORD* pdwCurrentAddress;
    
    pdwCurrentAddress = (DWORD*) 0x100000;
    
    while((DWORD) pdwCurrentAddress < 0x600000)
    {        
        *pdwCurrentAddress = 0x00;

        if(*pdwCurrentAddress != 0)
        {
            return FALSE;
        }
        
        pdwCurrentAddress++;
    }
    
    return TRUE;
}