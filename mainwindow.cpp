#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMouseEvent>
#include <QPainter>
#include <QColorDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form();
     connect(form, &Form::signal, this, &MainWindow::set_thickness);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(event == nullptr) return;
             start_point = event->pos();

             switch(shape)
             {
             case line:
                 current.start = start_point;
                 break;
             case rectangle:
                 rect.start = start_point;
                 break;
             case ellipse:
                 ell.start = start_point;
                 break;
             case triangle:
                 trl.start = start_point;
                 break;

             }


}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     if(event == nullptr) return;

     switch(shape)
     {
     case line:
          lines.push_back(current);
         break;
     case rectangle:
          rects.push_back(rect);
         break;
     case ellipse:
         ells.push_back(ell);
         break;
     case triangle:
         QPoint mid_point(trl.start.x()-(trl.end.x()-trl.start.x()), trl.end.y());
         trl.mid = mid_point;
         tris.push_back(trl);
         break;

     }


     update();
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(event == nullptr) return;


        end_point = event->pos();

        switch(shape)
        {
        case line:
             current.end = end_point;;
            break;
        case rectangle:
             rect.end = end_point;
            break;
        case ellipse:
            ell.end = end_point;
            break;
        case triangle:
            trl.end = end_point;
            break;

        }




     update();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);


    switch(shape)
    {
    case line:
       // painter.setPen(QPen(QBrush(QColor(current.color)),current.thickness));
          painter.drawLine(current.start, current.end);
        break;
    case rectangle:
        painter.drawRect(QRect(rect.start, rect.end));
        break;
    case ellipse:

      painter.drawEllipse(QRect(ell.start, ell.end));

        break;
    case triangle:
         QPoint mid_point(trl.start.x()-(trl.end.x()-trl.start.x()), trl.end.y());
         trl.mid = mid_point;
        const QPoint points[3] = {trl.start, trl.mid, trl.end};
              painter.drawPolygon(points, 3);
        break;
    }





    for (const auto& el : rects) {

         painter.setPen(QPen(QBrush(QColor(el.color)),el.thickness));
       //  painter.setBrush(QBrush(el.color));

         painter.drawRect(QRect(el.start, el.end));
        }
    for (const auto& el : ells) {

         painter.setPen(QPen(QBrush(QColor(el.color)),el.thickness));

        // painter.setBrush(QBrush(el.color));

            painter.drawEllipse(QRect(el.start, el.end));

        }

    for (const auto& el : tris) {

         painter.setPen(QPen(QBrush(QColor(el.color)),el.thickness));
         //painter.setBrush(QBrush(el.color));


         const QPoint points[3] = {el.start, el.mid, el.end};
         painter.drawPolygon(points, 3);
        }

    for (const auto& el : lines) {

         painter.setPen(QPen(QBrush(QColor(el.color)),el.thickness));
        // painter.setBrush(QBrush(el.color));

            painter.drawLine(el.start, el.end);
        }

    QMainWindow::paintEvent(event);



}

void MainWindow::set_thickness(QString string)
{
    thickness = string.toInt();
    current.thickness = rect.thickness = ell.thickness = trl.thickness = thickness;

}



void MainWindow::on_colorButton_clicked()
{
    color = QColorDialog::getColor(Qt::white, this);
    current.color = rect.color = ell.color = trl.color = color;
}

void MainWindow::on_pushButton_clicked()
{
    form->show();
}

void MainWindow::on_lineButton_clicked()
{
    shape = line;
}

void MainWindow::on_rectButton_clicked()
{
    shape = rectangle;
}

void MainWindow::on_circleButton_clicked()
{
    shape = ellipse;
}

void MainWindow::on_triangleButton_clicked()
{
    shape = triangle;
}
