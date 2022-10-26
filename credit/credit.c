#include <stdio.h>
#include <cs50.h>
int main (void){
    long creditcardnum, cc;
    int sixteen, fifteen, fourteen, thirteen, twelve, eleven, ten, nine, eight, seven, six, five, four, three, two, one;
    do {
    creditcardnum = get_long("Give me your credit card number 0_0 \n");
    }
    while (creditcardnum > 5599999999999999 || creditcardnum < 3400000000000);
    cc = creditcardnum;

    one = cc % 10;
    two = cc % 100 / 10;
    three = cc % 1000/100;
    four = cc % 10000/1000;
    five = cc % 100000/10000;
    six = cc % 1000000/100000;
    seven = cc % 10000000/1000000;
    eight = cc % 100000000/10000000;
    nine = cc % 1000000000/100000000;
    ten = cc % 10000000000/1000000000;
    eleven = cc % 100000000000/10000000000;
    twelve = cc % 1000000000000/100000000000;
    thirteen = cc % 10000000000000/1000000000000;
    fourteen = cc % 100000000000000/10000000000000;
    fifteen = cc % 1000000000000000/100000000000000;
    sixteen = cc % 10000000000000000/1000000000000000;

    int sum1, sum2, luhn;
    do{
        sum1 = sixteen+fourteen+twelve+ten+eight+six+four+two;
        sum2 = one+three+five+seven+nine+eleven+thirteen+fifteen;
        luhn = (sum1*2) + sum2;
    }
    while (cc <= 0);

    if (luhn % 10 == 0){
    if (sixteen == false && fifteen == 3) {
            if (fourteen == 4 || fourteen == 7){
        printf("AMEX\n");}
    }

    if (sixteen == 5){
        if (fifteen <= 1 || fifteen >= 5){
            printf("MASTERCARD\n");}
        }

    if (sixteen == 4) {
        printf("VISA\n");
        }

    if (sixteen == false && fifteen == false && fourteen == false && thirteen == 4){
        printf("VISA\n");
    }
    }
    else {
        printf("INVALID\n");
    }

}