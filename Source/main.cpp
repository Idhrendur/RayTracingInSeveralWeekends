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
				const auto r = static_cast<float>(i) / (imageWidth - 1);
				const auto g = static_cast<float>(j) / (imageHeight - 1);
				const auto b = 0.25;

				const auto ir = static_cast<int>(255.999F * r);
				const auto ig = static_cast<int>(255.999F * g);
				const auto ib = static_cast<int>(255.999F * b);

				std::cout << ir << ' ' << ig << ' ' << ib << '\n';
			}
		}
	}
	catch (...)
	{
	}
}