#include <iostream>
#include <unordered_map>
#include <vector>

using mt = long long;

mt N, M, K;
std::unordered_map<mt, std::vector<mt>> zavislosti;
std::vector<mt> fronty;
std::vector<bool> start;

int main()
{   
    std::cin >> N >> K >> M;
    start.resize(N+7, true);
    for (mt i = 0; i < M; i++) {
        mt a, b;
        std::cin >> a >> b;
        zavislosti[a].push_back(b);
        start[b] = false;
    }
    fronty.resize(N + 7, 1);
    for (mt i = 0; i < N * K; i++) {
        mt a, b;
        std::cin >> a;
        b = fronty[a];
        fronty[a]++;
        std::cout << b << " ";
    }
}
