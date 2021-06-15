#ifndef MULTITHREADING_TESTER_H
#define MULTITHREADING_TESTER_H

#include <iostream>

#define CHECK_SUCCESS(expr) do { std::cout << "[OK] " #expr << std::endl; } while(0)
#define CHECK_FAILURE(expr) do { std::cout << "[FAILURE] " #expr << std::endl; } while(0)
#define CHECK(expr) do { if (expr) { CHECK_SUCCESS(expr); } else { CHECK_FAILURE(expr); } } while(0)

#endif //MULTITHREADING_TESTER_H
