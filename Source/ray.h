#ifndef RAY_H
#define RAY_H



#include "vector.h"



namespace RayTracer
{

class Ray
{
  public:
	Ray(const Vector& origin, const Vector& direction): origin_(origin), direction_(direction) {}

	const auto& origin() const { return origin_; }
	const auto& direction() const { return direction_; }

	Vector at(float t) const { return origin_ + t * direction_; }

  private:
	Vector origin_;
	Vector direction_;
};

} // namespace RayTracer



#endif // RAY_H