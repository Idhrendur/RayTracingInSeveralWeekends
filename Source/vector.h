#ifndef VECTOR_H
#define VECTOR_H



namespace RayTracer
{

class Vector
{
  public:
	Vector(float x, float y, float z): x_(x), y_(y), z_(z) {}

	[[nodiscard]] const auto& x() const { return x_; }
	[[nodiscard]] const auto& y() const { return y_; }
	[[nodiscard]] const auto& z() const { return z_; }

	[[nodiscard]] Vector operator+(const Vector& rhs) const;
	[[nodiscard]] Vector operator-(const Vector& rhs) const;
	[[nodiscard]] friend Vector operator*(const Vector& vector, float scalar);
	[[nodiscard]] friend Vector operator*(float scalar, const Vector& vector);
	[[nodiscard]] Vector operator/(float scalar) const;
	[[nodiscard]] float dot(const Vector& rhs) const;
	[[nodiscard]] Vector cross(const Vector& rhs) const;
	[[nodiscard]] Vector unitVector() const;
	[[nodiscard]] float lengthSquared() const;

  private:
	[[nodiscard]] float length() const;

	float x_ = 0.0;
	float y_ = 0.0;
	float z_ = 0.0;
};


[[nodiscard]] Vector operator*(const Vector& vector, float scalar);
[[nodiscard]] Vector operator*(float scalar, const Vector& vector);

} // namespace RayTracer



#endif // VECTOR_H