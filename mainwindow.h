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
    
    void calculateTemp();

    void hideTemp();
    
    void on_actTheory_triggered();

    void on_actLearning_triggered();

    void on_actModeling_triggered();

    void on_actAbout_triggered();
    
    void on_testSetupDone_clicked();

    void on_questionsDone_clicked();

    void on_voltage_textEdited(const QString &arg1);

    void on_Tcold_textEdited(const QString &arg1);

    void on_Thot_textEdited(const QString &arg1);

    void on_dT_textEdited(const QString &arg1);

    void on_couple1_currentIndexChanged(int index);

    void on_couple2_currentIndexChanged(int index);
    
    void on_statDone_clicked();

    void on_theory_back_clicked();

    void on_history_button_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
