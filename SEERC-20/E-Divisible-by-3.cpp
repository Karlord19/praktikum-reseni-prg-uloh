#include <iostream>
#include <string>
#include <vector>

using mt = long long;

mt result = 0;
mt N, a;

struct myprefix {
	mt ones = 0;
	mt twos = 0;
	myprefix(mt jedna, mt dva) : ones(jedna), twos(dva) {}
	void add(mt x) {
		x = x % 3;
		if (x == 1) ones++;
		if (x == 2) twos++;
	}
};

std::vector<myprefix> prefixes;

bool nicearray(mt start, mt end) {
	myprefix endfix = prefixes[end];
	myprefix startfix = prefixes[start - 1];
	myprefix subtracted{ 0, 0 };
	subtracted.ones = endfix.ones - startfix.ones;
	subtracted.twos = endfix.twos - startfix.twos;
	mt weight = 0;
	weight += (subtracted.ones * (subtracted.ones - 1)) / 2;
	weight += (subtracted.twos * (subtracted.twos - 1)) / 2;
	weight += subtracted.ones * subtracted.twos * 2;
	weight = weight % 3;
	if (weight == 0) {
		return true;
	}
	return false;
}

int main()
{   
	std::cin >> N;
	prefixes.reserve(N + 7);
	prefixes.emplace_back(myprefix{0, 0});
	for (mt i = 1; i <= N; i++) {
		std::cin >> a;
		prefixes.emplace_back(prefixes[i - 1]);
		prefixes[i].add(a);
	}
	for (mt start = 1; start <= N; start++) {
		for (mt end = start; end <= N; end++) {
			if (nicearray(start, end)) {
				result++;
			}
		}
	}
	std::cout << result << std::endl;
}
