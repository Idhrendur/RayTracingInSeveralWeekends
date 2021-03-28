#ifndef SPHERE_H
#define SPHERE_H



#include "hittable.h"



namespace RayTracer
{

class Sphere final: public Hittable
{
  public:
	Sphere(const Vector& center, float radius): center_(center), radius_(radius) {}

	[[nodiscard]] std::optional<HitRecord> hit(const Ray& ray, float tMin, float tMax) const override;

  private:
	const Vector center_;
	float radius_ = 0.0F;
};


} // namespace RayTracer



#endif // SPHERE_H