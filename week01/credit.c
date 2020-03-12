#include <cs50.h>
#include <stdio.h>

// Sum all of the digits in n
int sum_nums(int n) {
    int sum = 0;
    while(n > 0) {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

// Return the number of digits in n
int number_size(long n) {
    int len = 0;
    while(n > 0) {
        len ++;
        n = n / 10;
    }
    return len;
}

// Return what type of card it is
string card_type(long n) {
    int div12 = n / 1000000000000l;
    int div13 = n / 10000000000000l;
    int div14 = n / 100000000000000l;
    int div15 = n / 1000000000000000l;
    if (div13 == 37 || div13 == 37)
        return "AMEX";
    if (div14 > 50 && div14 < 56)
        return "MASTERCARD";
    if (div12 == 4 || div15 == 4)
        return "VISA";
    return "INVALID";
}

int main() {
    long ccnum = get_long("Enter credit card number: ");
    int len = number_size(ccnum);
    if(len < 13 || len > 16 || len == 14) {
        printf("INVALID\n");
        return 0;
    }
    char mult = 0;
    long sum = 0;
    long ccnum_orig = ccnum;
    while(ccnum > 0) {
        if(mult) {
            sum += sum_nums(ccnum % 10 * 2);
        }
        else {
            sum += ccnum % 10;
        }
        ccnum = ccnum / 10;
        mult = !mult;
    }
    if (sum % 10 == 0) {
        printf("%s\n", card_type(ccnum_orig));
    }
    else {
        printf("INVALID\n");
    }
}
