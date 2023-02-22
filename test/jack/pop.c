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

bool pop(int *n)
{
    // TODO
    if (s->size == 0) {
        return false;
    }
    s->size--;
    *n = s->numbers[s->size];
    return true;
}
