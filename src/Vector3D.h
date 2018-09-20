#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstring>

class Vector3D
{
public:
  double x, y, z;

  Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}
  Vector3D() : x(0), y(0), z(0) {}
  ~Vector3D() {}

  Vector3D operator+(const Vector3D &right) const;
  Vector3D operator-(const Vector3D &vec1) const;
  Vector3D operator*(double right) const;
  friend Vector3D operator*(double left, const Vector3D &right);
  Vector3D operator/(double right) const;
  friend Vector3D operator/(double left, const Vector3D &right);
  Vector3D operator-() const;

  Vector3D &operator+=(const Vector3D &right);
  Vector3D &operator-=(const Vector3D &right);
  Vector3D &operator*=(double right);
  Vector3D &operator/=(double right);

  Vector3D &operator=(const Vector3D &right);
  bool operator==(const Vector3D &right);
  bool operator!=(const Vector3D &right);
  bool operator<(const Vector3D &right);
  bool operator>(const Vector3D &right);

  double dotProduct(const Vector3D &vec) const;
  double squareLength() const;
  double squareDistanteTo(const Vector3D &vec) const;
  double length() const;
  double distanteTo(const Vector3D &vec) const;
  std::string toString() const;
};

#endif