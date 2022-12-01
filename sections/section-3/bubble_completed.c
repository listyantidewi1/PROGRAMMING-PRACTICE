#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get input
    int n = get_int("How many values? ");
    int values[n];
    for (int i = 0; i < n; i++)
    {
        values[i] = get_int("Value %i: ", i);
    }

    // Large passes left to right
    for (int i=0; i<n; i++)
    {
        // Pairwise comparisons
        for(int j=0; j<n-1; j++)
        {
            // Detect an out-of-order pair
            if (values[j+1] < values[j])
            {
                // Swap the two elements
                int tmp = values[j];
                values[j] = values[j+1];
                values[j+1] = tmp;
            }
        }
    }

    // Print sorted values
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", values[i]);
    }
}