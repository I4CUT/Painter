#ifndef TRIANGLES_H
#define TRIANGLES_H
#include <QPoint>
#include <QColor>


class Triangles
{
public:
    QPoint start;
    QPoint end;
    QPoint mid;

    QColor color = "black";
    int thickness = 1;


    Triangles();
};

#endif // TRIANGLES_H
