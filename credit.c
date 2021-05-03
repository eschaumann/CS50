
#include <cs50.h>
#include <stdio.h>
#include <math.h>

long getdigit(int len, int place, long num) {

    long modularVar = pow(10, (len - place));

    //printf("\n function: modularVar = %ld", modularVar);

    long digit = num % modularVar;
    digit = (digit * 10) / (modularVar);

    //printf("\n function: dig = %ld", dig);

    return digit;
}

//define funcction to multiply every other digit by 2 and add digits together
long multiplyadddigs(int len, bool startLastDig, bool multiply2, long num) {

    long runTotal = 0;
    //bool startLastDig = false;
    int startDig;

    if (startLastDig == true){
        startDig = len - 1;
    }
    else {
        startDig = len - 2;

    }
    //printf("startdig is %i", startDig);

    for (int i = startDig; i >= 0; i = i - 2){
            //printf("\ni = %i", i);

            long dig = getdigit(len, i, num);
            //printf("\ndig = %ld", dig);

            if (multiply2 == true){
                dig = dig * 2;
            }

            if (dig > 10){
                int sum = getdigit(2, 1, dig);
                sum = sum + getdigit (2, 0, dig);

                runTotal = runTotal + sum;
            }
            else{
                runTotal = runTotal + dig;
            }
    }
    //printf("\nTask multiplyadddigs total = %ld", runTotal);

    return runTotal;
}


int main(void)
{
    //define booleans
    // bool mastercard = false;
    // bool visa = false;
    // bool amex = false;

    char cardtype;
    bool shortvisa = false;

    int len;

    //get number, check length
    long num;
    do {
    num = get_long("Number: ");
    //printf("number is");
    }
    while (num >= 5600000000000000 || (num < 340000000000000 && num >= 5000000000000) || num < 4000000000000);


    //test for mastercard
    if (num >= 5100000000000000 && num < 5600000000000000)
    {
        cardtype = 'm';

        //printf("this is a mastercard");
    }

    //test for visa
    if ( (num >= 4000000000000000 && num < 5000000000000000) || (num >= 4000000000000 && num < 5000000000000) )
    {
        cardtype = 'v';
        //printf("this is a visa");
    }

    //test for short visa
    if (num >= 4000000000000 && num < 5000000000000){

        shortvisa = true;
        cardtype = 'v';
    }


    //test for amex
    if ( (num >= 340000000000000 && num < 350000000000000) || (num >= 370000000000000 && num < 380000000000000) )
    {
        //amex = true;
        cardtype = 'a';
        //printf("this is a amex");
    }

    //find length
    if (shortvisa)
    {
        len = 13;
        long numtest = 1234567890123;

        //int dig12 = numtest%

        int dig11 = numtest%100;
        dig11 = dig11 / 10;

        printf("\n dig 11 = %i", dig11);
    }
    else if(cardtype == 'a')
    {
        len = 15;
    }
    else{
        len = 16;
    }

    //num = 4003600000000014;
    // multiply every other digit by 2 and add digits together, starting with second last digit
    long runTotal = multiplyadddigs (len, false, true, num);

    // multiply every other digit by 2 and add digits together, starting with second last digit
    runTotal = runTotal + multiplyadddigs (len, true, false, num);

    //printf("\nfinaltotal = %ld\n", runTotal);

    //check final digit
    if (runTotal % 10 == 0){
        //printf("\nthis is a credit card");

        switch(cardtype){
            case 'v' :
                printf("VISA\n" );
                break;
            case 'a' :
                printf("AMEX\n" );
                break;
            case 'm' :
                printf("MASTERCARD\n" );
                break;
            default :
                printf("INVALID FROM SWITCH\n");
        }
    }

    else {
        printf("INVALID\n");
    }

}


// Number: 4003-6000-0000-0014
// Number: foo
// Number:
// VISA
// 378282246310005
// 4003600000000014
