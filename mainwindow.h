#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
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
