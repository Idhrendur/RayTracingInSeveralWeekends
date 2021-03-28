#include "sphere.h"
#include <cmath>



std::optional<RayTracer::HitRecord> RayTracer::Sphere::hit(const Ray& ray, float tMin, float tMax) const
{
	const auto originToCenter = ray.origin() - center_;

	const auto a = ray.direction().lengthSquared();
	const auto halfB = originToCenter.dot(ray.direction());
	const auto c = originToCenter.lengthSquared() - radius_ * radius_;

	const auto discriminant = halfB * halfB - a * c;
	if (discriminant < 0)
	{
		return std::nullopt;
	}
	const auto squareRootOfDiscriminant = std::sqrt(discriminant);

	// Find the nearest root that lies in the acceptable range.
	auto root = (-halfB - squareRootOfDiscriminant) / a;
	if (root < tMin || tMax < root)
	{
		root = (-halfB + squareRootOfDiscriminant) / a;
		if (root < tMin || tMax < root)
		{
			return std::nullopt;
		}
	}

	const auto point = ray.at(root);
	const auto normal = (point - center_) / radius_;

	return HitRecord{.point = point, .normal = normal, .t = root};
}