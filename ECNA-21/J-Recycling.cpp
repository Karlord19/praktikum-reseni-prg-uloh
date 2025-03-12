#include <algorithm>
#include <iostream>
#include <array>
#include <functional>

std::pair<int, int> pole[100007];
int n = 0;
bool zito[100007];
int psenice[100007];

int opts = 0;
int opte = 0;
int optr = 0;

int main()
{
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> pole[i].first;
        pole[i].second = i;
    }
    std::sort(pole + 1, pole + n + 1, [](auto a, auto b)
        {
            return a.first > b.first;
        });
    int lend = 0;
    int rend = 0;
    for (int i = 1; i <= n; i++) {
        zito[pole[i].second] = true;
        psenice[pole[i].second] = pole[i].second;
        lend = pole[i].second;
        rend = pole[i].second;
        if (zito[pole[i].second - 1] == true) {
            lend = psenice[pole[i].second - 1];
        }
        if (zito[pole[i].second + 1] == true) {
            rend = psenice[pole[i].second + 1];
        }
        psenice[lend] = rend;
        psenice[rend] = lend;
        if (((rend - lend + 1) * pole[i].first > optr) || (((rend - lend + 1) * pole[i].first == optr) && lend < opts)) {
            optr = (rend - lend + 1) * pole[i].first;
            opts = lend;
            opte = rend;
        }
    }
    std::cout << opts << " " << opte << " " << optr << std::endl;
    return 0;
}
