// #include <stdbool.h>


// const int CAPACITY = 50;

// typedef struct
// {
//     int numbers[CAPACITY];
//     int size;
// } stack;

// stack s;
// s.size = 0;

// but why is s undefined?

bool push(int n)
{
    // TODO
    // check if stack is already full, return false if true
    if (s->size == CAPACITY)
    {
        return false;
    }

    if (s->size == sizeof(s->numbers) /  sizeof(int))
    {
        int new_capacity = sizeof(s->numbers) / sizeof(int) * 2;
        int* new_numbers = realloc(s->numbers, new_capacity * sizeof(int));
        if (new_numbers == NULL)
        {
            return false;
        }
        s->numbers = new_numbers;
    }

    //else, push n
    s->numbers[s->size] = n;
    s->size++;
    return true;
}
