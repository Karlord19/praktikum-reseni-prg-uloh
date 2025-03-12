#include <iostream>
#include <vector>
#include <sstream>


long long N;
long long X, Y;

std::stringstream sresult;
std::vector<long long> vresult;

auto cifry(long long num) {
    std::vector<int> res;
    while (num != 0) {
        res.emplace_back(num % 10);
        num /= 10;
    }
    return res;
}

auto spocitej(decltype(cifry(0)) vr) {
    long long res = 0;
    for (int i = 0; i < vr.size(); i++) {
        for (int j = i + 1; j < vr.size(); j++) {
            if (vr[i] > vr[j]) res++;
        }
    }
    return res;
}

void solve() {
    vresult.emplace_back(0);
    for (auto num = Y; num >= X; num--) {
        auto dec = cifry(num);
        vresult.back() += spocitej(dec);
    }
    sresult << "Case " << vresult.size() << ": " << vresult.back() << std::endl;
}

int main()
{
    std::cin >> N;
    for (long long i = 0; i < N; i++) {
        std::cin >> X >> Y;
        solve();
    }

    std::cout << sresult.str();

    return 0;
}
