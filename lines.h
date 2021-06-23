#ifndef LINES_H
#define LINES_H
#include <QColor>
#include <QPoint>


class lines
{
public:
    QPoint start;
    QPoint end;
    QColor color = "black";
    int thickness = 1;
public:
    lines();
};

#endif // LINES_H
