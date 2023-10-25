#include "Calculate.h"

int main()
{
    printf("\n");

    int ncb;
    int *ncBands = &ncb;

    printf("--------------------RESISTOR COLOR CODE CALCULATOR-----------------\n\n");

    //Ask user to input number of color bands for the resistor.
    printf("Number of Color Bands: ");
    scanf("%d", ncBands);

    //clear the stdin buffer after "scanf()".
    clearBuffer();

    //Call the "calculation" function.
    calculation(ncBands);

    printf("\n");
    return(0);
}

