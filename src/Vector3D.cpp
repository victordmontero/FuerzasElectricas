#include "Vector3D.h"

Vector3D Vector3D::operator+(const Vector3D &right) const
{
	return Vector3D(x + right.x, y + right.y, z + right.z);
}

Vector3D Vector3D::operator-(const Vector3D &right) const
{
	return Vector3D(x - right.x, y - right.y, z - right.z);
}

Vector3D Vector3D::operator*(double right) const
{
	return Vector3D(x * right, y * right, z * right);
}

Vector3D operator*(double left, const Vector3D &right)
{
	return right * left;
}

Vector3D Vector3D::operator/(double right) const
{
	return Vector3D(x / right, y / right, z / right);
}

Vector3D operator/(double left, const Vector3D &right)
{
	return right / left;
}

Vector3D Vector3D::operator-() const
{
	return Vector3D(-x, -y, -z);
}

Vector3D &Vector3D::operator+=(const Vector3D &right)
{
	this->x += right.x;
	this->y += right.y;
	this->z += right.z;
	return *this;
}

Vector3D &Vector3D::operator-=(const Vector3D &right)
{
	this->x -= right.x;
	this->y -= right.y;
	this->z -= right.z;
	return *this;
}

Vector3D &Vector3D::operator*=(double right)
{
	this->x *= right;
	this->y *= right;
	this->z *= right;
	return *this;
}

Vector3D &Vector3D::operator/=(double right)
{
	this->x /= right;
	this->y /= right;
	this->z /= right;
	return *this;
}

Vector3D &Vector3D::operator=(const Vector3D &right)
{
	x = right.x;
	y = right.y;
	z = right.z;

	return *this;
}

bool Vector3D::operator==(const Vector3D &right) const
{
	return right.x == x &&
		   right.y == y &&
		   right.z == z;
}

bool Vector3D::operator!=(const Vector3D &right) const
{
	return !(*this == right);
}

bool Vector3D::operator<(const Vector3D &right) const
{
	return this->x < right.x &&
		   this->y < right.y &&
		   this->z < right.z;
}

bool Vector3D::operator>(const Vector3D &right) const
{
	return this->x > right.x &&
		   this->y > right.y &&
		   this->z > right.z;
}

bool Vector3D::operator<=(const Vector3D& right) const
{
	return *this < right || *this == right;	
}

bool Vector3D::operator>=(const Vector3D& right) const
{
	return *this > right || *this == right;	
}

double Vector3D::dotProduct(const Vector3D &vec) const
{
	return vec.x * x + vec.y * y + vec.z * z;
}

double Vector3D::squareLength() const
{
	return dotProduct(*this);
}

double Vector3D::squareDistanteTo(const Vector3D &vec) const
{
	return (*this - vec).squareLength();
}

double Vector3D::length() const
{
	return sqrt(squareLength());
}

double Vector3D::distanteTo(const Vector3D &vec) const
{
	return (*this-vec).length();
}

std::string Vector3D::toString() const
{
	std::string result;
	char buffer[512 + 1] = {0};

	// std::cout << x << std::endl;
	result.push_back('(');
	sprintf(buffer, "%lf", x);
	result += buffer;
	result.push_back(',');
	memset(buffer, 0, 513);

	// std::cout << y << std::endl;
	sprintf(buffer, "%lf", y);
	result += buffer;
	result.push_back(',');
	memset(buffer, 0, 513);

	// std::cout << z << std::endl;
	sprintf(buffer, "%lf", z);
	result += buffer;
	result.push_back(')');
	memset(buffer, 0, 513);

	// std::cout << result.c_str() << std::endl;
	return result;
}