#define MAX(X,Y) ((X > Y) ? X : Y)
int mem[5001][2] = {0};

int max(int* prices, int i, int s, int buy)
{
    int op1 = 0, op2 = 0;
    if (i >= s)
        return (0);
    if (!mem[i][buy])
    {
        if (buy)
        {
            op2 = max(prices, i + 1, s, 1);
            op1 = max(prices, i + 1, s, 0) - prices[i];
        }
        else
        {
            op2 = max(prices, i + 1, s, 0);
            op1 = max(prices, i + 2, s, 1) + prices[i];
        }
        mem[i][buy] = MAX(op1, op2);
    }
    return (mem[i][buy]);
}


int maxProfit(int* prices, int s)
{
    memset(mem, 0, sizeof(mem));
    return (max(prices, 0, s, 1));
}