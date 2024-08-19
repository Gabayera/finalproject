#include <iostream>
#include "Vector.h"
#include "Shape.h"
#include "DPvector.h"
#include "Clock.h"

using namespace std;
void ShowBar(int length, double percent)
{
    std::cout << '\r' << '|';
    int filledLength = static_cast<int>(percent / 100 * length);
    for (int i = 0; i < length; i++) {
    		if (i < filledLength) {
    			std::cout << '\r';
    			for(int j = 0; j < i; j++) {
    				std::cout << '_';
				}
    			if (i % 2 == 0) {
    				std::cout << 'C';
				} else {
					std::cout << 'c';
				}
			} else {
				std::cout << '*';
			}
    }
    std::cout << '|' << percent << '%' << std::flush;
}

int main() {
    Shape th;

    Vector<Shape> a(10000);
    DPvector<Shape> b(10000);

    double singlePointerInsertTime = 0;
    double singlePointerRemoveTime = 0;
    double doublePointerInsertTime = 0;
    double doublePointerRemoveTime = 0;

    int iterations = 50;

    for (int i = 1; i <= iterations; ++i) {
        Clock timer;
        ShowBar(50,(double)i/iterations*100);
        
        timer.start();
        a.insert(0, th);
        timer.stop();
        singlePointerInsertTime += timer.getMilliseconds();

        
        timer.start();
        a.remove(0);
        timer.stop();
        singlePointerRemoveTime += timer.getMilliseconds();

        
        timer.start();
        b.insert(0, th);
        timer.stop();
        doublePointerInsertTime += timer.getMilliseconds();

       
        timer.start();
        b.remove(0);
        timer.stop();
        doublePointerRemoveTime += timer.getMilliseconds();
    }

    
    singlePointerInsertTime /= iterations;
    singlePointerRemoveTime /= iterations;
    doublePointerInsertTime /= iterations;
    doublePointerRemoveTime /= iterations;

    
    cout << "\nAverage Vector with single pointer insert: " << singlePointerInsertTime << " ms\n";
    cout << "Average Vector with single pointer remove: " << singlePointerRemoveTime << " ms\n";
    cout << "Average Vector with double pointer insert: " << doublePointerInsertTime << " ms\n";
    cout << "Average Vector with double pointer remove: " << doublePointerRemoveTime << " ms\n";

    return 0;
}
