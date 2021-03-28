#include "color.h"
#include "ray.h"
#include "vector.h"
#include <iostream>



namespace RayTracer
{

bool hitSphere(const Vector& center, float radius, const Ray& ray)
{
	const auto originToCenter = ray.origin() - center;

	const auto a = ray.direction().dot(ray.direction());
	const auto b = 2.0F * originToCenter.dot(ray.direction());
	const auto c = originToCenter.dot(originToCenter) - radius * radius;
	const auto discriminant = b * b - 4 * a * c;
	return discriminant > 0;
}


Color rayColor(const Ray& ray)
{
	if (hitSphere(Vector(0, 0, -1), 0.5, ray))
	{
		return {1, 0, 0};
	}

	const auto unitDirection = ray.direction().unitVector();
	const auto t = 0.5F * (unitDirection.y() + 1.0F);
	return (1.0F - t) * Color(1.0F, 1.0F, 1.0F) + t * Color(0.5F, 0.7F, 1.0F);
}

} // namespace RayTracer


int main()
{
	try
	{
		// Image
		constexpr auto aspectRatio = 16.0F / 9.0F;
		constexpr auto imageWidth = 400;
		constexpr auto imageHeight = static_cast<int>(imageWidth / aspectRatio);

		// Camera
		constexpr auto viewportHeight = 2.0F;
		constexpr auto viewportWidth = aspectRatio * viewportHeight;
		constexpr auto focalLength = 1.0F;

		const auto origin = RayTracer::Vector(0, 0, 0);
		const auto horizontal = RayTracer::Vector(viewportWidth, 0, 0);
		const auto vertical = RayTracer::Vector(0, viewportHeight, 0);
		const auto lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - RayTracer::Vector(0, 0, focalLength);

		// Render
		std::cout << "P3\n";
		std::cout << imageWidth << ' ' << imageHeight << "\n";
		std::cout << "255\n";
		for (auto j = imageHeight - 1; j >= 0; --j)
		{
			std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
			for (auto i = 0; i < imageWidth; ++i)
			{
				const auto u = static_cast<float>(i) / (imageWidth - 1);
				const auto v = static_cast<float>(j) / (imageHeight - 1);
				RayTracer::Ray ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
				const auto pixelColor = rayColor(ray);
				std::cout << pixelColor;
			}
		}
	}
	catch (...)
	{
	}
}