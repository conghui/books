#include <stdio.h>
#include <string.h>
#include <assert.h>

static int strend(const char *s, const char *t);

int main(void)
{
    assert(strend("helloworld", "world") == 1);
    assert(strend("helloworld", "wordl") == 0);

    return 0;
}

static int strend(const char *s, const char *t)
{
    const char *se = s + strlen(s) - 1;
    const char *te = t + strlen(t) - 1;

    for (; *se == *te; se--, te--)
    {
        if (te == t || se == s)
        {
            break;
        }
    }

    if (*te == *se && te == t && *se != '\0')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
