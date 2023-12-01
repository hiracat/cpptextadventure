#pragma once

#include <string>
#include <vector>

struct LocationDescriptions {
    const std::string description;
    const std::string visitedDescription;
};

struct Location {
    bool visited;
    const LocationDescriptions descriptions;
};

enum class Locations {
    startingRoom,
    room2,
};
