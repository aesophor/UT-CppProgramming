#ifndef SHAPE_H_
#define SHAPE_H_

class Shape {
 public:
  virtual ~Shape() = default;
  virtual void setDrag() = 0;

 protected:
  Shape() = default;
};


class Triangle : public Shape {
 public:
  Triangle() = default;
  virtual ~Triangle() = default;
  virtual void setDrag() override;
};

class Circle : public Shape {
 public:
  Circle() = default;
  virtual ~Circle() = default;
  virtual void setDrag() override;
};

class Rectangle : public Shape {
 public:
  Rectangle() = default;
  virtual ~Rectangle() = default;
  virtual void setDrag() override;
};

#endif // SHAPE_H_
