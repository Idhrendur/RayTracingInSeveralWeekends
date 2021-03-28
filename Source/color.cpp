#include "color.h"



RayTracer::Color RayTracer::Color::operator+(const Color& rhs) const
{
	return {r_ + rhs.r_, g_ + rhs.g_, b_ + rhs.b_};
}


RayTracer::Color RayTracer::operator*(const Color& color, float scalar)
{
	return {color.r_ * scalar, color.g_ * scalar, color.b_ * scalar};
}


RayTracer::Color RayTracer::operator*(float scalar, const Color& color)
{
	return color * scalar;
}


constexpr float color_translation = 255.999F;
std::ostream& RayTracer::operator<<(std::ostream& out, const Color& color)
{
	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(color_translation * color.r()) << ' ' << static_cast<int>(color_translation * color.g())
		 << ' ' << static_cast<int>(color_translation * color.b()) << '\n';

	return out;
}