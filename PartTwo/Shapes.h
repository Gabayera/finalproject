#pragma once
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

class Shapes 
{
public:
    virtual ~Shapes() = default;


    virtual double volume() const = 0;
    virtual double surfaceArea() const = 0;
    virtual double mass() const = 0;
    
    virtual Shapes* clone() const = 0;

    void setDensity(double density) { m_density = density; }
    double getDensity() const { return m_density; }

protected:
    double m_density{1.0}; 
};

class Box : public Shapes {
public:
    Box(double l = 0, double w = 0, double h = 0) {
        setDimensions(l, w, h);
    }

    double volume() const override {
        return m_len * m_wid * m_hei;
    }

    double surfaceArea() const override {
        return 2 * (m_len * m_wid + m_wid * m_hei + m_len * m_hei);
    }

    double mass() const override {
        return m_density * volume();
    }

    void setDimensions(double l, double w, double h) {
        m_len = l;
        m_wid = w;
        m_hei = h;
    }

    Box* clone() const override {
        return new Box(*this); 
    }

private:
    double m_len{0}, m_wid{0}, m_hei{0};
};

class Globe : public Shapes {
public:
    Globe(double r = 0) : m_rad(r) {}

    double volume() const override {
        return (4.0 * M_PI / 3.0) * m_rad * m_rad * m_rad;
    }

    double surfaceArea() const override {
        return 4 * M_PI * m_rad * m_rad;
    }

    double mass() const override {
        return m_density * volume();
    }

    Globe* clone() const override {
        return new Globe(*this);
    }

private:
    double m_rad{0};
};

class Tube : public Shapes {
public:
    Tube(double h = 0, double r = 0) : m_hei(h), m_rad(r) {}

    double volume() const override {
        return M_PI * m_rad * m_rad * m_hei;
    }

    double surfaceArea() const override {
        return 2 * M_PI * m_rad * (m_rad + m_hei);
    }

    double mass() const override {
        return m_density * volume();
    }

    Tube* clone() const override {
        return new Tube(*this);
    }

private:
    double m_hei{0}, m_rad{0};
};

class Cone : public Shapes {
public:
    Cone(double h = 0, double bw = 0) : m_hei(h), m_baseW(bw) {}

    double volume() const override {
        return (M_PI * m_baseW * m_baseW * m_hei) / 3.0;
    }

    double surfaceArea() const override {
        return M_PI * m_baseW * (m_baseW + sqrt(m_hei * m_hei + m_baseW * m_baseW));
    }

    double mass() const override {
        return m_density * volume();
    }

    Cone* clone() const override {
        return new Cone(*this);
    }

private:
    double m_hei{0}, m_baseW{0};
};
