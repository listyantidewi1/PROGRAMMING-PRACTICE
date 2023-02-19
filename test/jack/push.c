// #include <stdbool.h>


// const int CAPACITY = 50;

// typedef struct
// {
//     int numbers[CAPACITY];
//     int size;
// } stack;

// stack s;
// s.size = 0;


bool push(int n)
{
    // TODO
    // check if stack is already full, return false if true
    if (s->size == CAPACITY)
    {
        return false;
    }

    //else, push n
    s->numbers[s->size] = n;
    s->size++;
    return true;
}
