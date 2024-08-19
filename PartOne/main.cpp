#include<iostream>
#include"Vector.h"
#include"Shape.h"
#include"DPvector.h"
#include"Clock.h"

using namespace std;



int main(){
    Shape th;
    Vector<Shape> a(100);
    //DPvector<Shape> b(100);
    Clock timer;
    timer.start();
     a.insert(0,th);
    timer.stop();
    //a.show_elements();
    cout<<"Vetor with single pointer insert:"<< timer << "ms\n" ;
    
    return 0;


}