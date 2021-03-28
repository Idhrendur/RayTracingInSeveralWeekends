#include "color.h"
#include <iostream>


constexpr int imageWidth = 256;
constexpr int imageHeight = 256;

int main()
{
	try
	{
		std::cout << "P3\n";
		std::cout << imageWidth << ' ' << imageHeight << "\n";
		std::cout << "255\n";
		for (auto j = imageHeight - 1; j >= 0; --j)
		{
			std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
			for (auto i = 0; i < imageWidth; ++i)
			{
				RayTracer::Color color(static_cast<float>(i) / (imageWidth - 1), static_cast<float>(j) / (imageHeight - 1), 0.25F);

				std::cout << color;
			}
		}
	}
	catch (...)
	{
	}
}