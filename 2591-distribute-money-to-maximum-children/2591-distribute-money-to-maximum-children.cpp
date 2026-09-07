class Solution {
public:
    int distMoney(int money, int children) {
        if (money < children)
            return -1;

        money -= children;

        int ans = min(money / 7, children);

        money -= ans * 7;
        children -= ans;

        if (children == 0)
            return money == 0 ? ans : ans - 1;

        if (money == 3 && children == 1)
            return ans - 1;

        return ans;
    }
};