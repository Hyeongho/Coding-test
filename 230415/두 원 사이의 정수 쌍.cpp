#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int r1, int r2)
{
    long long answer = 0;

    long long lr2 = r2;
    long long lr1 = r1;

    for (long long x = 1; x <= r2; x++)
    {
        std::cout << "x : " << x << std::endl;

        long long maxY = (long long)std::floor(std::sqrt(lr2 * lr2 - x * x));
        long long minY = x > r1 ? 0 : (long long)std::ceil(std::sqrt(lr1 * lr1 - x * x));

        std::cout << "y : " << minY << " ~ " << maxY << std::endl;

        answer += (maxY - minY + 1);

        std::cout << "count : " << (maxY - minY + 1) << std::endl << std::endl;;
    }

    answer *= 4;

    return answer;
}

int main()
{
    solution(2, 3);

    return 0;
}