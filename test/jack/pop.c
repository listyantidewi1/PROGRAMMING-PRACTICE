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
