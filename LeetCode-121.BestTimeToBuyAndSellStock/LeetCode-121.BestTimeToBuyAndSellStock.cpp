#include <iostream>
#include <vector>

using namespace std;

class Solution {

    int min = -1;
    int max = 0;
    int best = 0;

public:
    int maxProfit(vector<int>& prices) {
        for (int i = prices.size() - 1; i >= 0; --i)
        {
            if (max < prices[i])
            {
                min = -1;
                max = prices[i];

                continue;
            }

            if (min > prices[i] || min == -1)
            {
                min = prices[i];

                if (best < max - min)
                    best = max - min;
            }
        }

        return best;
    }
};

string ArrayToString(const vector<int>& input)
{
    string output = "";
    char buffer[16] = "";

    for (int i = 0; i < input.size(); ++i)
    {
        if (i != 0)
            output += ", ";

        _itoa_s(input[i], buffer, 10);
        output += buffer;
    }

    return output;
}

int main()
{
    vector<int> prices = { 7,1,5,3,6,4 };

    Solution s;
    int profit = s.maxProfit(prices);

    string input = ArrayToString(prices);

    printf("prices:[%s]\n", input.c_str());
    printf("profig:%d\n", profit);
}
