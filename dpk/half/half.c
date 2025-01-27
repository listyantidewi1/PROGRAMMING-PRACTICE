#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

float half(float bill, float tax, int tip)
{
    float bill_after_tax = bill * ( tax / 100.0 ) + bill;
    float bill_after_tax_tip = bill_after_tax * ( tip / 100.0 ) + bill_after_tax;
    float split = bill_after_tax_tip / 2;
    return split;
}