int main(void)
{
    return 0;
}

static int invert(int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p - n + 1));
}
