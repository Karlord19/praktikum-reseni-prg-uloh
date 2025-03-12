#include <iostream>
#include <vector>
#include <algorithm>

struct hrana {
    int odkud = -1;
    int kam = -1;
    int hmotnost = -1;
    hrana(int o, int k, int h) : odkud(o), kam(k), hmotnost(h) {}
};

bool porovnani_hran(hrana a, hrana b) {
    return a.hmotnost > b.hmotnost;
}

std::vector<hrana> Zito; // serazene hrany od nejhmotnejsi
int Parents[1000007];
int Ranks[1000007];
bool has_cyklus[1000007];

int N;
int M;
long long MAX = 0;

void init_parents() {
    for (int i = 1; i <= N; i++) {
        Parents[i] = -1;
        Ranks[i] = 1;
    }
}

int find_root(int i) {
    if (Parents[i] == -1) {
        return i;
    }
    Parents[i] = find_root(Parents[i]);
    return Parents[i];
}

void zkus_pridat_hranu(hrana h) {
    int odkud_root = find_root(h.odkud);
    int kam_root = find_root(h.kam);

    if (odkud_root == kam_root) {
        if (has_cyklus[odkud_root] == true) {
            return;
        }
        MAX += h.hmotnost;
        has_cyklus[odkud_root] = true;
        return;
    }

    if (has_cyklus[odkud_root] && has_cyklus[kam_root]) {
        return;
    }

    if (Ranks[odkud_root] < Ranks[kam_root]) {
        Parents[odkud_root] = kam_root;
        has_cyklus[kam_root] = (has_cyklus[kam_root] || has_cyklus[odkud_root]);
        MAX += h.hmotnost;
        return;
    }

    if (Ranks[odkud_root] > Ranks[kam_root]) {
        Parents[kam_root] = odkud_root;
        has_cyklus[odkud_root] = (has_cyklus[odkud_root] || has_cyklus[kam_root]);
        MAX += h.hmotnost;
        return;
    }

    Parents[kam_root] = odkud_root;
    Ranks[odkud_root]++;
    has_cyklus[odkud_root] = (has_cyklus[odkud_root] || has_cyklus[kam_root]);
    MAX += h.hmotnost;
}

int main()
{
    std::cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        int u, v, d;
        std::cin >> u >> v >> d;
        Zito.emplace_back(hrana{ u, v, d });
    }
    std::sort(Zito.begin(), Zito.end(), porovnani_hran);
    init_parents();
    for (auto i : Zito) {
        zkus_pridat_hranu(i);
    }
    std::cout << MAX << std::endl;
}

