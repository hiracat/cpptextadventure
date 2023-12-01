#include <chrono>
#include <cstdint>
#include <iostream>
#include <random>
#include <string>
#include <thread>
#include <vector>

#include "locations.h"

struct printSettings {
    static constexpr int32_t MIN_DELAY = 20;
    static constexpr int32_t MAX_DELAY = 150;
};

printSettings settings;

int32_t generateRandomNumber(int32_t min, int32_t max) {
    thread_local std::random_device rd;
    thread_local std::mt19937 generator(rd());

    std::uniform_int_distribution<int32_t> distribution(min, max);

    return distribution(generator);
}

void slowType(const std::string& toPrint, const printSettings& settings) {
    for (size_t i = 0; i < toPrint.size(); i++) {
        std::cout << toPrint.at(i) << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(generateRandomNumber(settings.MIN_DELAY, settings.MAX_DELAY)));
    }
    std::cout << std::endl;
}
void printLocationDescription(const Location& location) {
    if (location.visited) {
        slowType(location.descriptions.visitedDescription, settings);
    } else {
        slowType(location.descriptions.description, settings);
    }
}

int main() {
    std::vector<Location> locations;
    Location location{.visited = false, .descriptions = {"this is the description", "this is the visited description"}};
    printLocationDescription(location);
    location.visited = true;
    printLocationDescription(location);
}
