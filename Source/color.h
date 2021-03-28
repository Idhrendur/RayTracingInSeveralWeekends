#ifndef COLOR_H
#define COLOR_H
#include <ostream>


class Color
{
  public:
	Color();
	Color(float r, float g, float b): r_(r), g_(g), b_(b) {}

	[[nodiscard]] const auto& r() const { return r_; }
	[[nodiscard]] const auto& g() const { return g_; }
	[[nodiscard]] const auto& b() const { return b_; }

  private:
	float r_ = 0.0F;
	float g_ = 0.0F;
	float b_ = 0.0F;
};


std::ostream& operator<<(std::ostream& out, const Color& color);



#endif // COLOR_H