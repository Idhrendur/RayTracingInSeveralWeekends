#include "vector.h"
#include <cmath>



RayTracer::Vector RayTracer::Vector::operator+(const Vector& rhs) const
{
	return {x_ + rhs.x_, y_ + rhs.y_, z_ + rhs.z_};
}


RayTracer::Vector RayTracer::Vector::operator-(const Vector& rhs) const
{
	return {x_ - rhs.x_, y_ - rhs.y_, z_ - rhs.z_};
}


RayTracer::Vector RayTracer::operator*(const Vector& vector, float scalar)
{
	return {vector.x_ * scalar, vector.y_ * scalar, vector.z_ * scalar};
}


RayTracer::Vector RayTracer::operator*(float scalar, const Vector& vector)
{
	return vector * scalar;
}


RayTracer::Vector RayTracer::Vector::operator/(float scalar) const
{
	return {x_ / scalar, y_ / scalar, z_ / scalar};
}


float RayTracer::Vector::dot(const Vector& rhs) const
{
	return x_ * rhs.x_ + y_ * rhs.y_ + z_ * rhs.z_;
}


RayTracer::Vector RayTracer::Vector::cross(const Vector& rhs) const
{
	return {y_ * rhs.z_ - z_ * rhs.y_, z_ * rhs.x_ - x_ * rhs.z_, x_ * rhs.y_ - y_ * rhs.x_};
}


RayTracer::Vector RayTracer::Vector::unitVector() const
{
	return *this / length();
}


float RayTracer::Vector::lengthSquared() const
{
	return x_ * x_ + y_ * y_ + z_ * z_;
}


float RayTracer::Vector::length() const
{
	return std::sqrt(lengthSquared());
}