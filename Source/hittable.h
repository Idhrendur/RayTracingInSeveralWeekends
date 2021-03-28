#ifndef HITTABLE_H
#define HITTABLE_H



#include "ray.h"
#include "vector.h"
#include <optional>


namespace RayTracer
{


struct HitRecord
{
	Vector point;
	Vector normal;
	float t = 0.0F;
	bool frontFace = true;

	void setFaceNormal(const Ray& ray, const Vector& outwardNormal)
	{
		frontFace = ray.direction().dot(outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};


class Hittable
{
  public:
	Hittable() = default;
	Hittable(const Hittable&) = default;
	Hittable(Hittable&&) = default;
	Hittable& operator=(const Hittable&) = default;
	Hittable& operator=(Hittable&&) = default;
	virtual ~Hittable() = default;

	[[nodiscard]] virtual std::optional<HitRecord> hit(const Ray& ray, float tMin, float tMax) const = 0;
};

} // namespace RayTracer



#endif // HITTABLE_H