#include "color.h"



constexpr float color_translation = 255.999F;
std::ostream& operator<<(std::ostream& out, const Color& color)
{
	// Write the translated [0,255] value of each color component.
	out << static_cast<int>(color_translation * color.r()) << ' ' << static_cast<int>(color_translation * color.g())
		 << ' ' << static_cast<int>(color_translation * color.b()) << '\n';

	return out;
}