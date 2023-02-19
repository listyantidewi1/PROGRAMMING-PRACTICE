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
