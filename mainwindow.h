#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class couple
{
public:
    QString name;
    float alpha;
    float r0;
    float tm;
    float price;
    float dens;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    couple currentCouple1;
    couple currentCouple2;
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:  


    void set(QString obj, float value);

    float get(QString obj);

    void calculating();

    void  checkSt();

    void setParamMode();

    void setFindParam();

    void calculateRvn();

    void calculateRn();

    void calculateVoltage();

    void calculateCurrent();

    void calculatePower();

    void calculateT();

    void calculateAlpha();

    void setCurrentCouple();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
