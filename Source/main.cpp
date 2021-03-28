#include <iostream>


constexpr int imageWidth = 256;
constexpr int imageHeight = 256;

int main()
{
	std::cout << "P3\n";
	std::cout << imageWidth << ' ' << imageHeight << "\n";
	std::cout << "255\n";
	for (int j = imageHeight - 1; j >= 0; --j)
	{
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < imageWidth; ++i)
		{
			const auto r = static_cast<float>(i) / (imageWidth - 1);
			const auto g = static_cast<float>(j) / (imageHeight - 1);
			const auto b = 0.25;

			const int ir = static_cast<int>(255.999 * r);
			const int ig = static_cast<int>(255.999 * g);
			const int ib = static_cast<int>(255.999 * b);

			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
}