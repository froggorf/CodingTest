#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int k{};
    int n{};
    std::vector<int> cables;
    std::vector<int> values;

    std::cin >> k;
    std::cin >> n;
    for (int i = 0; i < k; ++i)
    {
        int LineLength{};
        std::cin >> LineLength;
        cables.push_back(LineLength);
        values.push_back(LineLength);
    }

    while(true)
    {
        auto max_ele = std::max_element(cables.begin(), cables.end());
        *max_ele = *max_ele / 2;
        long long value{};
        for(const auto& cable : cables)
        {
            value += cable / *max_ele;
        }

    }
    return 0;
}
