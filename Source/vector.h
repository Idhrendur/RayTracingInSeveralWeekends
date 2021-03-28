#ifndef VECTOR_H
#define VECTOR_H



namespace RayTracer
{

class Vector
{
  public:
	Vector(float x, float y, float z): x_(x), y_(y), z_(z) {}

	const auto& x() const { return x_; }
	const auto& y() const { return y_; }
	const auto& z() const { return z_; }

	Vector operator+(const Vector& rhs) const;
	Vector operator-(const Vector& rhs) const;
	friend Vector operator*(const Vector& vector, float scalar);
	friend Vector operator*(float scalar, const Vector& vector);
	Vector operator/(float scalar) const;
	float dot(const Vector& rhs) const;
	Vector cross(const Vector& rhs) const;
	Vector unitVector() const;

  private:
	float length() const;

	float x_ = 0.0;
	float y_ = 0.0;
	float z_ = 0.0;
};

} // namespace RayTracer



#endif // VECTOR_H