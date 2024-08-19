#pragma once
#include "Shapes.h"
#include <vector>
#include <string>

class Device {
private:
    std::vector<Shapes*> m_shapes;       
    std::vector<Device*> m_subDevices;   
    std::string m_name;

public:
    
    Device() = default;
    Device(const std::string& name) : m_name(name) {}

    
    ~Device() {
        
        for (auto shape : m_shapes) {
            delete shape;
        }

        
        for (auto device : m_subDevices) {
            delete device;
        }
    }

    
    void addShape(Shapes* shape) {
        m_shapes.push_back(shape);
    }

    
    void addSubDevice(Device* device) {
        m_subDevices.push_back(device);
    }

    double EvalVolume() const {
        double totalVolume = 0.0;
        for (const auto& shape : m_shapes)
            totalVolume += shape->volume();
        for (const auto& device : m_subDevices)
            totalVolume += device->EvalVolume();
        return totalVolume;
    }

    double EvalSurface() const {
        double totalSurface = 0.0;
        for (const auto& shape : m_shapes)
            totalSurface += shape->surfaceArea();
        for (const auto& device : m_subDevices)
            totalSurface += device->EvalSurface();
        return totalSurface;
    }

    double EvalMass() const {
        double totalMass = 0.0;
        for (const auto& shape : m_shapes)
            totalMass += shape->mass();
        for (const auto& device : m_subDevices)
            totalMass += device->EvalMass();
        return totalMass;
    }
};
