int main(void)
{
    return 0;
}
int wordlength(void)
{
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++) {
        ;
    }

    return i;
}

unsigned rightrot(unsigned x, int n)
{
    int rbits = (~(~0 << n)) & x;
    
    rbits = rbits << (wordlength() - n);
    x = x >> n;
    return x | rbits;
}
