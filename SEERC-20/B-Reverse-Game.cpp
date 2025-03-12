#include <iostream>
#include <string>

using mt = long long;

std::string S;
mt potencial = 0;
mt jednicek = 0;

int main()
{   
    std::cin >> S;
    for (mt i = 0; i < S.size(); i++) {
		switch (S[i])
		{
		case '0':
			potencial += jednicek;
			break;
		case '1':
			jednicek++;
			break;
		default:
			break;
		}
    }
	std::cout << (potencial % 3 == 0 ? "Bob" : "Alice") << std::endl;
}
