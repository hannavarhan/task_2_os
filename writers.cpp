#include <iostream>
#include <thread>

int main() {
  clock_t start = clock();
  std::thread worker1([] {
    for (int i = 0; i < 12345; i++) {
      std::cout << "a";
    }
  });
  std::thread worker2([] {
    for (int i = 0; i < 12345; i++) {
      std::cout << "b";
    }
  });
  std::thread worker3([] {
    for (int i = 0; i < 12345; i++) {
      std::cout << "c";
    }
  });
  worker1.join();
  worker2.join();
  worker3.join();
  clock_t end = clock();
  std::cout << std::endl;
  std::cout << "Finished in " << (double) (end - start) / 1000 << " seconds";
}
