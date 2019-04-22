#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
 protected: // protected ctor -> abstract class
  Shape() = default;
  virtual ~Shape() = default;

 public:
  virtual double area() const = 0;
};

class Circle : public Shape {
 public:
  Circle(double radius);
  virtual ~Circle() = default;
 
  virtual double area() const override;

 private:
  double radius_;
};

class Rectangle : public Shape {
 public:
  Rectangle(double width, double height);
  virtual ~Rectangle() = default;
 
  virtual double area() const override;

 private:
  double width_;
  double height_;
};

class Trapezoid : public Shape {
 public:
  Trapezoid(double upper_width, double lower_width, double height);
  virtual ~Trapezoid() = default;
 
  virtual double area() const override;

 private:
  double upper_width_;
  double lower_width_;
  double height_;
};

#endif // SHAPE_H_
