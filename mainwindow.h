#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QPoint>
#include <QLine>
#include "lines.h"
#include "form.h"
#include "rectangle.h"
#include <QColor>
#include "ellipses.h"
#include "triangles.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


    QPoint start_point;
    QPoint end_point;

    QVector<lines> lines;
    class lines current;

    QVector<Rectangle> rects;
    Rectangle rect;

    QVector<Ellipses> ells;
    Ellipses ell;

    QVector<Triangles> tris;
    Triangles trl;

    enum figures { line, rectangle, ellipse, triangle};
    figures shape;


int thickness = 1;
QColor color = "black";


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui = nullptr;
    Form *form;








    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
private slots:
    void on_colorButton_clicked();
     void set_thickness(QString string);
     void on_pushButton_clicked();
     void on_lineButton_clicked();
     void on_rectButton_clicked();
     void on_circleButton_clicked();
     void on_triangleButton_clicked();
};


#endif // MAINWINDOW_H
