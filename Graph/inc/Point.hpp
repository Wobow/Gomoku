#ifndef POINT_HPP__
# define POINT_HPP__

class		Point
{
private:
  int		_x;
  int		_y;
public:
  Point(int x, int y)
  {
    _x = x;
    _y = y;
  }
  ~Point() {}
  int		getX()
  {
    return (_x);
  }
  int		getY()
  {
    return (_y);
  }
  void		setX(int x)
  {
    _x = x;
  }
  void		setY(int y)
  {
    _y = y;
  }
  Point		operator+(Point end)
  {
    this->setX(this->getX() + end.getX());
    this->setY(this->getY() + end.getY());
    return (*this);
  }
  Point		operator=(Point end)
  {
    this->setX(end.getX());
    this->setY(end.getY());
    return (*this);
  }
};

#endif
