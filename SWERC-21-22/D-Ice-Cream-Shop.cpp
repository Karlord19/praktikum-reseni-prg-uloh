#include <iostream>
#include <algorithm>

int N, M;
long long int pole[200007];
long long int psenice[200007];
struct iceInterval {
	long long int left = 0;
	long long int right = 0;
};
iceInterval zito[200007];

long long int vzdalenost(long long int hut, long long int ice) {
	return (std::abs(hut * 100 - psenice[ice]));
}

long long int nearIce = 0;
bool deb = false;

int main()
{
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> pole[i];
		if (deb) std::cout << pole[i] << std::endl;
	}
	for (int i = 0; i < M; i++) {
		std::cin >> psenice[i];
		if (deb) std::cout << psenice[i] << std::endl;
	}
	std::sort(psenice, psenice + M);
	if (deb) std::cout << psenice[0] << std::endl;
	for (int i = 0; i < N; i++) {
		while (vzdalenost(i, nearIce) > vzdalenost(i, nearIce + 1)) {
			if (nearIce + 1 == M) break;
			nearIce++;
		}
		if ((i * 100) - psenice[nearIce] > 0) {
			zito[i].left = psenice[nearIce];
			zito[i].right = (i * 100) + vzdalenost(i, nearIce);
		}
		else {
			zito[i].left = (i * 100) - vzdalenost(i, nearIce);
			zito[i].right = psenice[nearIce];
		}
		if (deb) std::cout << "hut " << i << " " << zito[i].left << " " << zito[i].right << std::endl;
	}
	zito[N].left = INT_MAX;
	zito[N].right = INT_MAX;
	long long int maxcus = 0;
	long long int customers = 0;
	long long int position = zito[0].left - 10;
	int from = 0; // including
	int to = 0; // except
	while (from < N) {
		if (deb) std::cout << "position " << position << std::endl;
		while ((zito[from].right <= position) && from <= N) {
			if (deb) std::cout << "removed number " << from << std::endl;
			customers -= pole[from];
			from++;
		}
		while ((zito[to].left <= position) && to <= N) {
			if (deb) std::cout << "added number " << to << std::endl;
			customers += pole[to];
			to++;
		}
		if (deb) std::cout << "customers " << customers << std::endl;
		if (customers > maxcus) {
			maxcus = customers;
		}
		position = std::min(zito[from].right, zito[to].left);
	}
	std::cout << maxcus << std::endl;
}
