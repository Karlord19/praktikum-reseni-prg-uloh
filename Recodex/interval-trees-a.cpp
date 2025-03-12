#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

struct myStruct {
    double val = 0;
    double quad = 0;
    double ival = 0;
    double iquad = 0;
    double inorm = 0;
};

myStruct plus(const myStruct& a, const myStruct& b) {
    myStruct c;
    c.val = a.val + b.val;
    c.ival = a.ival + b.ival;
    c.quad = a.quad + b.quad;
    c.iquad = a.iquad + b.iquad;
    c.inorm = a.inorm + b.inorm;
    return c;
}

myStruct pole[400007];
size_t n;
size_t v;

void computeFromVal(size_t position) { // position in posloupnost
    position--;
    pole[v + position].ival = (position + 1) * pole[v + position].val;
    pole[v + position].quad = pole[v + position].val * pole[v + position].val;
    pole[v + position].iquad = (position + 1) * (position + 1);
    pole[v + position].inorm = (position + 1);
}

void updateFromSons(size_t position) { // position in pole
    pole[position] = plus(pole[2 * position], pole[2 * position + 1]);
}

void change(size_t i, int val) {
    size_t bad = v + i - 1;
    pole[bad].val = val;
    computeFromVal(i);
    while (bad != 1) {
        bad /= 2;
        updateFromSons(bad);
    }
}

myStruct sum(size_t start, size_t end) {
    if (start == end) return pole[start + v - 1];
    start += v - 1;
    end += v - 1;
    myStruct res = plus(pole[start], pole[end]);
    while (start != end - 1) {
        if (start % 2 == 0) {
            res = plus(res, pole[start + 1]);
        }
        start /= 2;
        if (end % 2 == 1) {
            res = plus(res, pole[end - 1]);
        }
        end /= 2;
    }
    return res;
}

int main()
{



    std::cin >> n;
    v = 1;
    while (v < n) {
        v *= 2;
    }
    for (size_t i = 0; i < n; i++) {
        std::cin >> pole[v + i].val;
        computeFromVal(i + 1);
    }
    for (size_t i = v - 1; i > 0; i--) {
        updateFromSons(i);
    }

    char cd = 'F';
    size_t a, b;
    double c, d;
    std::cout << std::fixed << std::setprecision(2);
    while (std::cin >> cd) {
        std::cin >> a >> b;
        if (cd == 'C') {
            change(a, b);
        }
        if (cd == 'D') {
            std::cin >> c >> d;
            myStruct sums = sum(a, b);
            double res = sums.quad - c * 2 * sums.ival - d * 2 * sums.val + c * d * 2 * sums.inorm + c * c * sums.iquad + d * (b - a + 1) * d;
            res /= (b - a + 1);
            if (res < 0) break;
            res = std::sqrt(res);
            std::cout << res << std::endl;
        }
    }
    

    return 0;
}

