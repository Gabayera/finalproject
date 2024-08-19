#pragma once
#include <ctime>
#include <iostream>

class Clock {
private:
    std::clock_t start_time;
    std::clock_t end_time;

public:
    Clock() : start_time(0), end_time(0) {}

    void clear() {
        start_time = end_time = std::clock();
    }

    void start() {
        start_time = std::clock();
    }

    void stop() {
        end_time = std::clock();
    }

    friend std::ostream& operator<<(std::ostream& os, const Clock& Clock) {
        return os << Clock.getMilliseconds();
    }

    double getMilliseconds() const {
        if (end_time <= start_time) {
            return 0.0;
        }
        return 1000.0 * (end_time - start_time) / CLOCKS_PER_SEC;
    }
};
