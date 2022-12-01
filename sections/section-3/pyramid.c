#include <stdio.h>
#include <cs50.h>

// Function definition
void draw(int h);


// Main function
int main(void)
{
    draw(get_int("Size of Pyramid: "));
}


// Draws a pyramid of height h
void draw(int h)
{
    if (h == 0)                // The “Base Case”
            return;

    draw(h - 1);                // The “Recursive Call”

    for (int i = 0; i < h; i++)        // Add one layer to the pyramid
    {
            printf("#");
    }
    printf("\n");
}
