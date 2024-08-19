#pragma once
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

class Shapes
{
public:
    virtual ~Shapes() = default;
    virtual auto volume() const -> double = 0;
    virtual auto surfaceArea() const -> double = 0;  // New method for surface area
    virtual auto mass() const -> double = 0;         // New method for mass
    void setDensity(double density) { m_density = density; }
    double getDensity() const { return m_density; }

protected:
    double m_density{1.0};  // Default density set to 1.0
};

class Box : public Shapes
{
public:
    Box(double l = 0, double w = 0, double h = 0)
    {
        setDimensions(l, w, h);
    }

    auto volume() const -> double override
    {
        return m_len * m_wid * m_hei;
    }

    auto surfaceArea() const -> double override
    {
        return 2 * (m_len * m_wid + m_wid * m_hei + m_len * m_hei);
    }

    auto mass() const -> double override
    {
        return m_density * volume();
    }

    void setDimensions(double l, double w, double h)
    {
        m_len = l;
        m_wid = w;
        m_hei = h;
    }

    friend auto operator<<(std::ostream& out, const Box& box) -> std::ostream&
    {
        return out << "Box(" << box.m_len << ", " << box.m_wid << ", " << box.m_hei << ")";
    }

private:
    double m_len{0}, m_wid{0}, m_hei{0};
};

class Globe : public Shapes
{
public:
    Globe(double r = 0) : m_rad(r) {}

    auto volume() const -> double override
    {
        return (4.0 * M_PI / 3.0) * m_rad * m_rad * m_rad;
    }

    auto surfaceArea() const -> double override
    {
        return 4 * M_PI * m_rad * m_rad;
    }

    auto mass() const -> double override
    {
        return m_density * volume();
    }

    void setRadius(double r)
    {
        m_rad = r;
    }

    friend auto operator<<(std::ostream& out, const Globe& globe) -> std::ostream&
    {
        return out << "Globe(" << globe.m_rad << ")";
    }

private:
    double m_rad{0};
};

class Tube : public Shapes
{
public:
    Tube(double h = 0, double r = 0) : m_hei(h), m_rad(r) {}

    auto volume() const -> double override
    {
        return M_PI * m_rad * m_rad * m_hei;
    }

    auto surfaceArea() const -> double override
    {
        return 2 * M_PI * m_rad * (m_rad + m_hei);
    }

    auto mass() const -> double override
    {
        return m_density * volume();
    }

    void setDimensions(double h, double r)
    {
        m_hei = h;
        m_rad = r;
    }

    friend auto operator<<(std::ostream& out, const Tube& tube) -> std::ostream&
    {
        return out << "Tube(" << tube.m_hei << ", " << tube.m_rad << ")";
    }

private:
    double m_hei{0}, m_rad{0};
};

class Cone : public Shapes
{
public:
    Cone(double h = 0, double bw = 0) : m_hei(h), m_baseW(bw) {}

    auto volume() const -> double override
    {
        return (M_PI * m_baseW * m_baseW * m_hei) / 3.0;
    }

    auto surfaceArea() const -> double override
    {
        return M_PI * m_baseW * (m_baseW + sqrt(m_hei * m_hei + m_baseW * m_baseW));
    }

    auto mass() const -> double override
    {
        return m_density * volume();
    }

    void setDimensions(double h, double bw)
    {
        m_hei = h;
        m_baseW = bw;
    }

    friend auto operator<<(std::ostream& out, const Cone& cone) -> std::ostream&
    {
        return out << "Cone(" << cone.m_hei << ", " << cone.m_baseW << ")";
    }

private:
    double m_hei{0}, m_baseW{0};
};
