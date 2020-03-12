#include <stdio.h>
#include <cs50.h>

int main() {
    float input;
    do {
        input = get_float("Enter amount: ");
    } while(input < 0);
    int count = 0;
    int amount = (int)((input + 0.005) * 100);
    while (amount > 0) {
        if (amount >= 25)
            amount -= 25;
        else if (amount >= 10)
            amount -= 10;
        else if (amount >= 5)
            amount -= 5;
        else amount -= 1;
        count ++;
    }
    printf("%d\n", count);
}
