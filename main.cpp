#include <iostream>
#include <chrono>

#include "src/Exponential.h"

int main() {
    std::cout << "Started!" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();

    // v Performance test ---------------------------------
    // for (int i = 0; i < 1000; i++) {
    //     int randInt = 1000;
    //     double randDouble = 3.0;
    //
    //     auto exp1 = expnot::Exponential(randInt, randDouble);
    //     auto exp2 = expnot::Exponential(randInt, randDouble);
    //
    //     auto add = exp1 + exp2;
    //     auto add2 = exp2 + exp1;
    //     auto sub = exp1 - exp2;
    //     auto sub2 = exp2 - exp1;
    //     auto mul = exp1 * exp2;
    //     auto mul2 = exp2 * exp1;
    //     auto div = exp1 / exp2;
    //     auto div2 = exp2 / exp1;
    // }
    // ^ Performance test ---------------------------------

    // v Add test -------------------------------------
    auto expo = expnot::Exponential(1.0, 5);
    auto expo2 = expnot::Exponential(1.0, 5);
    auto expAdd = expo2 + expo;

    std::cout << expAdd.toString() << std::endl;
    // ^ Add test --------------------------------------

    auto now = std::chrono::high_resolution_clock::now();
    auto time = now - start;

    std::cout << time.count() / 1000.0 / 1000.0 << " seconds" << std::endl;

    expnot::Exponential a(1.5, 10);
    expnot::Exponential b(1, 9);
    std::cout << (a / b).toString() << std::endl;

    std::cout << a - 10 << std::endl;

    return 0;
}
