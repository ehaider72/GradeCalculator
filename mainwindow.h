#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    //void switch_classes();
signals:
   // void currentIndexChanged(const QString& myClass);

private slots:
    void on_pushButton_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    bool scheme_10c = true;
    bool scheme_10b = true;
};

#endif // MAINWINDOW_H
