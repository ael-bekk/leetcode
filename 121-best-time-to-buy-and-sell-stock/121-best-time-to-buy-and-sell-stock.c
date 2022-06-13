

int maxProfit(int* prices, int pricesSize)
{
    int i = -1, min = prices[0], max = 0;

    while (++i < pricesSize)
    {
        if (max < prices[i] - min)
            max = prices[i] - min;
        else if (prices[i] < min)
            min = prices[i];
    }
    return (max);
}