int main(void)
{
    return 0;
}
int bitcount(int x)
{
    int i;
    for (i = 0; x != 0; x &= (x-1)) {
        i++;
    }

    return i;
}
