#include <iostream>
#include "Device.h"
#include "Shapes.h"

int main()
{
    
    Device device;


    device.addShape(new Box(2.0, 3.0, 4.0));
    device.addShape(new Globe(3.3));
    device.addShape(new Tube(5.1, 2.0));
    device.addShape(new Cone(6.0, 4.0));

    Device* subDevice = new Device("SubDevice1");
    subDevice->addShape(new Box(1.0, 1.0, 1.0));
    subDevice->addShape(new Globe(2.0));
    device.addSubDevice(subDevice); 

    Device* anotherSubDevice = new Device();
    device.addSubDevice(anotherSubDevice);


    std::cout << "Total Volume: " << device.EvalVolume() << std::endl;
    std::cout << "Total Surface Area: " << device.EvalSurface() << std::endl;
    std::cout << "Total Mass: " << device.EvalMass() << std::endl;

    return 0;
}
