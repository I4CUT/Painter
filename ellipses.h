#ifndef ELLIPSES_H
#define ELLIPSES_H
#include <QPoint>
#include <QColor>

class Ellipses
{
public:
    QPoint start;
    QPoint end;
    QColor color = "black";
    int thickness = 1;
    Ellipses();
};

#endif // ELLIPSES_H
