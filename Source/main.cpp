#include "color.h"
#include "ray.h"
#include "sphere.h"
#include "vector.h"
#include <cmath>
#include <iostream>
#include <optional>



namespace RayTracer
{

Color rayColor(const Ray& ray)
{
	const auto hitRecord = Sphere(Vector(0, 0, -1), 0.5).hit(ray, 0.0F, 100.0F);
	if (hitRecord)
	{
		const auto normal = (ray.at(hitRecord->t) - Vector(0, 0, -1)).unitVector();
		return 0.5F * Color(normal.x() + 1, normal.y() + 1, normal.z() + 1);
	}

	const auto unitDirection = ray.direction().unitVector();
	const auto background = 0.5F * (unitDirection.y() + 1.0F);
	return (1.0F - background) * Color(1.0F, 1.0F, 1.0F) + background * Color(0.5F, 0.7F, 1.0F);
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