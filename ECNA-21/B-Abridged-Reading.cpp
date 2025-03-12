#include <vector>
#include <iostream>

struct chapter {
    int stranek = 0;
    int zavislost = 0;
    bool culminating = true;
    int hloubka = 0;
    int suma = 0;
};

chapter pole[1007];
int n, m;
int opt = INT32_MAX;

int pagesOfTwo(int a, int b) {
    int res = pole[a].suma + pole[b].suma;
    while (pole[a].hloubka != pole[b].hloubka) {
        if (pole[a].hloubka < pole[b].hloubka) {
            b = pole[b].zavislost;
        }
        else {
            a = pole[a].zavislost;
        }
    }
    while (a != 0) {
        if (a == b) {
            res -= pole[a].stranek;
        }
        a = pole[a].zavislost;
        b = pole[b].zavislost;
    }
    return res;
}

int nextCul(int a) {
    a++;
    while (a <= n) {
        if (pole[a].culminating == true) return a;
        a++;
    }
    return -1;
}

int main()
{
    std::cin >> n >> m;
    for (int i = 1; i < (n + 1); i++) {
        std::cin >> pole[i].stranek;
    }
    int a, b;
    for (int i = 0; i < m; i++) {
        std::cin >> a >> b;
        pole[b].zavislost = a;
        pole[a].culminating = false;
    }
    for (int i = 1; i <= n; i++) {
        pole[i].hloubka = pole[pole[i].zavislost].hloubka + 1;
        pole[i].suma = pole[pole[i].zavislost].suma + pole[i].stranek;
    }
    for (int i = nextCul(0); i != -1; i = nextCul(i)) {
        for (int j = nextCul(i); j != -1; j = nextCul(j)) {
            opt = std::min(opt, pagesOfTwo(i, j));
        }
    }
    std::cout << opt << std::endl;
    return 0;
}
