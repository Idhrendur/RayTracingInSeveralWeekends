#ifndef COLOR_H
#define COLOR_H
#include <ostream>



namespace RayTracer
{

class Color
{
  public:
	Color(float r, float g, float b): r_(r), g_(g), b_(b) {}

	[[nodiscard]] const auto& r() const { return r_; }
	[[nodiscard]] const auto& g() const { return g_; }
	[[nodiscard]] const auto& b() const { return b_; }

	Color operator+(const Color& rhs) const;
	friend Color operator*(const Color& color, float scalar);
	friend Color operator*(float scalar, const Color& color);

  private:
	float r_ = 0.0F;
	float g_ = 0.0F;
	float b_ = 0.0F;
};


Color operator*(const Color& color, float scalar);
Color operator*(float scalar, const Color& color);
std::ostream& operator<<(std::ostream& out, const Color& color);

} // namespace RayTracer



#endif // COLOR_H