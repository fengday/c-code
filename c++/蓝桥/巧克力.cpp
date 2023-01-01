#include <stdio.h>

int CanDivide(int len);

int choLn[100001], choCol[100001];
int n, k;

int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &choLn[i], &choCol[i]);
    }
    int left = 1, right = 100001, middle;
    while (left < right)
    {
        middle = left + right + 1,
        middle /= 2;
        if (CanDivide(middle))
            left = middle;
        else
            right = middle - 1;
    }
    printf("%d\n", right);
    return 0;
}

int CanDivide(int len)
{
    int sum = 0, result = 0;
    // int square = len * len;
    for (int i = 0; i < n; i++)
    {
        // sum += choLn[i] / square * choCol[i];
        sum += (choLn[i] / len) * (choCol[i] / len);
        if (sum >= k)
        {
            result = 1;
            break;
        }
    }
    return result;
}
