#include "Point3D.h"
#include "Vector3D.h"
#include <iostream>

void Point3D::print()
{
		std::cout << "Point(" << m_x << " , " << m_y << " , " << m_z << ")\n";
}

void Point3D::moveByVector(const Vector3D &v)
{
		// Реализуйте эту функцию как дружественную классу Vector3D
        this->m_x += v.m_x;
        this->m_y += v.m_y;
        this->m_z += v.m_z;
}