#include <chrono>
#include <iostream>
#include <ostream>
#include <string>
#include <thread>

void slowType(std::string toPrint) {
    for (size_t i = 0; i < toPrint.size(); i++) {
        std::cout << toPrint.at(i) << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    slowType(std::string("hello world"));
}
