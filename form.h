#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QString>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT
    QString thickness;

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

signals:
    void signal(QString string);

private slots:
    void on_pushButton_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
