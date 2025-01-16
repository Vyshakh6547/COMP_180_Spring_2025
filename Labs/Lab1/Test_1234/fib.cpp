#include <iostream>
#include <vector>
using namespace std;

int fib(int n) {
  if (n <= 1) return 1;
  return fib(n - 1) + fib(n - 2);
}

int main() {
  std::cout << fib(0) << " " << fib(1) << " " << fib(2) << " " << fib(3) << " " << fib(4) << " " << fib(5) << " " << fib(6) << " " << fib(7) << " " << fib(8)
   << endl;
   vector<pair<string, string>> dictionary;
   dictionary.push_back(std::make_pair("hello", "world"));
   dictionary.push_back(std::make_pair("why", "not"));
   dictionary.push_back(std::make_pair("hi", "there"));
  for (const auto& entry : dictionary) {
      cout << entry.first << ": " << entry.second << endl;
  }
  return 0;
}
