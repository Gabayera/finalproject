#include <iostream>
#include "Vector.h"
#include "Shape.h"
#include "DPvector.h"
#include "Clock.h"

using namespace std;

int main() {
    Shape th;

    Vector<Shape> a(10000);
    DPvector<Shape> b(10000);

    double singlePointerInsertTime = 0;
    double singlePointerRemoveTime = 0;
    double doublePointerInsertTime = 0;
    double doublePointerRemoveTime = 0;

    int iterations = 50;

    for (int i = 0; i < iterations; ++i) {
        Clock timer;

        // Timing for single pointer insert
        timer.start();
        a.insert(0, th);
        timer.stop();
        singlePointerInsertTime += timer.getMilliseconds();

        // Timing for single pointer remove
        timer.start();
        a.remove(0);
        timer.stop();
        singlePointerRemoveTime += timer.getMilliseconds();

        // Timing for double pointer insert
        timer.start();
        b.insert(0, th);
        timer.stop();
        doublePointerInsertTime += timer.getMilliseconds();

        // Timing for double pointer remove
        timer.start();
        b.remove(0);
        timer.stop();
        doublePointerRemoveTime += timer.getMilliseconds();
    }

    // Calculating average times
    singlePointerInsertTime /= iterations;
    singlePointerRemoveTime /= iterations;
    doublePointerInsertTime /= iterations;
    doublePointerRemoveTime /= iterations;

    // Displaying average results
    cout << "Average Vector with single pointer insert: " << singlePointerInsertTime << " ms\n";
    cout << "Average Vector with single pointer remove: " << singlePointerRemoveTime << " ms\n";
    cout << "Average Vector with double pointer insert: " << doublePointerInsertTime << " ms\n";
    cout << "Average Vector with double pointer remove: " << doublePointerRemoveTime << " ms\n";

    return 0;
}
