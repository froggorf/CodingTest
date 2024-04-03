#include <iostream>
#include <vector>
#include <numeric>

int main() {
    int k{};
    int n{};
    std::vector<int> cables;

    std::cin >> k;
    std::cin >> n;
    for (int i = 0; i < k; ++i)
    {
        int LineLength{};
        std::cin >> LineLength;
        cables.push_back(LineLength);
    }

    long left = 1;
    long right = std::numeric_limits<int>::max();

    long long count, mid;

    while (left <= right) {
        count = 0;
        mid = (left + right) / 2;
        for (int i = 0; i < k; i++) count += cables[i] / mid;
        if (count < n) right = mid - 1;
        else left = mid + 1;
    }

    std::cout << right;
    return 0;
}
