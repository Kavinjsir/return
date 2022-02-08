#include<iostream>
#include<vector>

class Fib {
  private:
    int betterFibCore(int n, std::vector<int> &memory) {
      if (n == 0 ) { memory[n] = 0; }
      if (n == 1 ) { memory[n] = 1; }

      if (memory[n] == -1) {
        memory[n] = betterFibCore(n - 1, memory) + betterFibCore(n - 2, memory);
      }

      return memory[n];
    }

  public:
    int baseFib(int n) {
      if (n == 0 ) { return 0; }
      if (n == 1 ) { return 1; }
      return baseFib(n - 1) + baseFib(n - 2);
    }

    int betterFib(int n ) {
      std::vector<int> memory = std::vector<int>(n + 1, -1);
      return betterFibCore(n, memory);
    }

    int dynamicFib(int n) {
      std::vector<int> memory = std::vector<int>(n + 1);

      memory[0] = 0;
      memory[1] = 1;

      for (int i  = 2; i <= n; i++) {
        memory[i] = memory[i - 1] + memory[i - 2];
      }

      return memory[n];
    }

    int doFib(int n, std::string option) {
      int result;

      time_t start = clock();

      if (option.compare("dynamicFib") == 0) {
        result = dynamicFib(n);
      } else if (option.compare("betterFib") == 0) {
        result = betterFib(n);
      } else {
        result = baseFib(n);
      }

      time_t end = clock();

      std::cout<< "\"" << option << "(" << n << ") = " << result << " \n";
      std::cout<< "time: " << double(end - start) / CLOCKS_PER_SEC << " s" << " \n";

      return result;
    }
};

int main() {
  int n = 1000;

  Fib fiber = Fib();

  // fiber.doFib(n, "betterFib");
  fiber.doFib(n, "dynamicFib");
  // fiber.doFib(n, "baseFib");
}
