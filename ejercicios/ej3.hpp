#ifndef EJ3_HPP
#define EJ3_HPP

class Point {

protected:
    int x, y;

public:
    Point();
    Point(int x, int y);
    virtual ~Point();

    int getX();
    int getY();

    virtual void print();

    void suma1(Point p);
    void suma2(Point& p);
    void suma3(Point* p);

    void swap1(Point p);
    void swap2(Point& p);
    void swap3(Point* p);

};

#endif //EJ3_HPP
