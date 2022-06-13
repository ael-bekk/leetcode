
int maxProfit(int* prices, int pricesSize)
{
    int i, profit;

    i = profit = 0;
    while (++i < pricesSize)
        if (prices[i] > prices[i - 1])
            profit += prices[i] - prices[i - 1];
    return (profit);
}