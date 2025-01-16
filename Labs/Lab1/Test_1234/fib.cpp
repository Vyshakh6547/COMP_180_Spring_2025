#include <iostream>
using namespace std;

int fib(int n) {
  if (n <= 1) return 1;
  return fib(n - 1) + fib(n - 2);
}
int main() {
  std::cout << fib(0) << " " << fib(1) << " " << fib(2) << " " << fib(3) << " " << fib(4) << " " << fib(5) << " " << fib(6) << " " << fib(7) << " " << fib(8)
   << endl;
  return 0;
}
