#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QObject::connect(ui->comboBox,SIGNAL(currentIndexChanged(const QString& myClass)),this,SLOT(switch_classes()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::switch_classes()
{
    if (c == "PIC 10B")
    {

    }
    else
    {

    }
}*/

void MainWindow::on_radioButton_clicked()
{
    scheme_10c = true;

}

void MainWindow::on_radioButton_2_clicked()
{
    scheme_10c = false;
}

void MainWindow::on_pushButton_clicked()
{
    double scoreTOTAL=0;
    double scoreh1 = 0;
    double scoreh2 = 0;
    double scoreh3 = 0;
    double scoreM = 0;
    double scoreFP = 0;
    double scoreF = 0;
    int numHw = 3;

    QString hw1 = ui->spinBox_2->text();
    QString hw2 = ui->spinBox_3->text();
    QString hw3 = ui->spinBox_4->text();
    QString midterm = ui->spinBox_5->text();
    QString finalProj = ui->spinBox_7->text();
    QString finalExam = ui->spinBox_6->text();

    if (scheme_10c == true || scheme_10c == false){
        if (scheme_10c) //scheme_10c A
        {
            scoreh1 = (hw1.toDouble())/numHw;
            scoreh2 = (hw2.toDouble())/numHw; //these are 20% of the grades
            scoreh3 = (hw3.toDouble())/numHw;
            scoreM = (midterm.toDouble()) * 0.2; //20% of grade
            scoreFP = (finalProj.toDouble()) * 0.3; //30% of grade
            scoreF = (finalExam.toDouble()) * 0.3; //30% of grade
        }
        else //scheme_10c B
        {
            scoreh1 = (hw1.toDouble())/numHw;
            scoreh2 = (hw2.toDouble())/numHw; //these are 20% of the grades
            scoreh3 = (hw3.toDouble())/numHw;
            scoreM = 0; //0% of grade
            scoreFP = (finalProj.toDouble()) * 0.3; //30% of grade
            scoreF = (finalExam.toDouble()) * 0.5; //50% of grade
        }
    }
    /*else //if scheme_10b
    {
        if(scheme_10b){} //scheme_10b A
        else //scheme_10b B
        {}
    }*/
    scoreTOTAL = scoreh1 + scoreh2 + scoreh3 + scoreM + scoreFP + scoreF;
    ui->lineEdit->setText(QString::number(scoreTOTAL));

}

void MainWindow::on_pushButton_2_clicked() //Clear All button
{
    ui->spinBox_2->setValue(0); //hw1
    ui->spinBox_3->setValue(0); //hw2
    ui->spinBox_4->setValue(0); //hw3
    ui->spinBox_5->setValue(0); //midterm
    ui->spinBox_6->setValue(0); //finalProj
    ui->spinBox_7->setValue(0); //finalExam
    ui->lineEdit->setText(0); //TOTAL SCORE
}
