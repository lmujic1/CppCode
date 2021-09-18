//
// Created by 38760 on 18. 9. 2021..
//

//TP 2017/2018: ZSR 1, Zadatak 13
#include <iostream>
#include<memory>
#include<functional>
#include<algorithm>
#include <set>
#include<string>

void f(int **p, std::shared_ptr<int> q) { *p = q.get(); }
std::function<int(int)> g(int x) { return [x](double y) { return 2 * x - y; }; }
auto h(int &p, int q, int &r) -> decltype(p) {
    p -= q; q -= r; r += p;
    std::cout << p << " " << q << " " << r << std::endl;
    return p;
}
template <typename T, typename F>
void w(T p, T q, F r) { while(p != q) r(*p++); }
int main() {
    std::shared_ptr<int> u, v;
    std::string str{"a ba"};
    std::set<int> s;
    s.insert(2); s.insert(5); s.insert(2); s.insert(1);
    for(auto i = s.begin(); i != s.end(); i++) std::cout << *i << " ";
    int a[] {4, 1, 5, 2, 3, 6}, *p(a + 2), q(6), r(3);
    u = std::shared_ptr<int>(new int(q)); v = std::make_shared<int>(2);
    w(a, a + 5, [&r](int x) { std::cout << x << "," << r << " "; r += x; });
    std::cout << std::endl << r << std::endl;
    h(*(a + 2), a[4], p[-2]) *= 2;
    for(int p : a) p += 3;
    for(int p : a) std::cout << p << " ";
    std::cout << std::endl;
    int *m(&a[3]), &n(*m);
    auto z(g(q + r)); m += 2;
    f(&p, u); std::cout << p[0] << " " << n << " ";
    f(&p, v); std::cout << str << " ";
    std::remove_copy(str.rbegin(), str.rend(), std::back_inserter(str), ' ');
    std::cout << str << std::endl; std::cout << p[0] << std::endl;
    for(int &k : a) k += 3; for(int k : a) std::cout << k << " ";
    std::cout << std::endl;
    std::cout << z(q - r) << std::endl;
    return 0;
}