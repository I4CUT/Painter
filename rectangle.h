#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QPoint>
#include <QColor>


class Rectangle
{
public:
    QPoint start;
    QPoint end;
    QColor color = "black";
    int thickness = 1;
    Rectangle();
};

#endif // RECTANGLE_H
