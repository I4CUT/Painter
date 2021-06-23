#ifndef FIGURE_H
#define FIGURE_H
#include <QPoint>
#include <QColor>

class Figure
{
public:
    QPoint start;
    QPoint end;
    QColor color = "black";
    unsigned int thickness = 1;
    Figure();
};

#endif // FIGURE_H
