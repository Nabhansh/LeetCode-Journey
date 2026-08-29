int maximumSaleItems(int** items, int itemsSize, int* itemsColSize, int budget) {
    int dp[1501] = {0};
    int minPrice = 1000000000;

    for (int i = 0; i < itemsSize; i++) {
        if (items[i][1] < minPrice)
            minPrice = items[i][1];
    }

    for (int i = 0; i < itemsSize; i++) {
        int factor = items[i][0];
        int price = items[i][1];
        int freeCount = 0;

        for (int j = 0; j < itemsSize; j++) {
            if (items[j][0] % factor == 0)
                freeCount++;
        }

        for (int b = budget; b >= price; b--) {
            int value = dp[b - price] + freeCount;

            if (value > dp[b])
                dp[b] = value;
        }
    }

    int ans = 0;

    for (int spent = 0; spent <= budget; spent++) {
        int value = dp[spent] + (budget - spent) / minPrice;

        if (value > ans)
            ans = value;
    }

    return ans;
}