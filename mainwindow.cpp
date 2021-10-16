#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->voltage_label->hide();
    ui->Thot_label->hide();
    ui->Tcold_label->hide();
    ui->dT_label->hide();
    ui->couple1_label->hide();
    ui->couple2_label->hide();
    ui->stackedMain->setCurrentWidget(ui->modeling);
    ui->stackedWidget->setCurrentWidget(ui->theory_menu);
    ui->stackedWidget_2->setCurrentWidget(ui->setup);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_actLearning_triggered()
{
    ui->stackedMain->setCurrentWidget(ui->learning);
}

void MainWindow::on_actModeling_triggered()
{
    ui->stackedMain->setCurrentWidget(ui->modeling);
}

void MainWindow::on_actTheory_triggered()
{
    ui->stackedMain->setCurrentWidget(ui->theory);
}

void MainWindow::on_actAbout_triggered()
{
    ui->stackedMain->setCurrentWidget(ui->about);
}


void MainWindow::on_testSetupDone_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->questions);
}

void MainWindow::on_questionsDone_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->stat);
}


void MainWindow::on_voltage_textEdited(const QString &arg1)
{
    ui->voltage_label->show();
    ui->voltage_label->setText(ui->voltage->text());
}

void MainWindow::on_Tcold_textEdited(const QString &arg1)
{
    ui->Tcold_label->show();
    ui->Tcold_label->setText(ui->Tcold->text());
}

void MainWindow::on_Thot_textEdited(const QString &arg1)
{
    ui->Thot_label->show();
    ui->Thot_label->setText(ui->Thot->text());
}

void MainWindow::on_dT_textEdited(const QString &arg1)
{
    ui->dT_label->show();
    ui->dT_label->setText(ui->dT->text());
}


void MainWindow::on_couple1_currentIndexChanged(int index)
{
    ui->couple1_label->show();
    ui->couple1_label->setText(ui->couple1->currentText());
}

void MainWindow::on_couple2_currentIndexChanged(int index)
{
    ui->couple2_label->show();
    ui->couple2_label->setText(ui->couple2->currentText());
}


void MainWindow::on_statDone_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->setup);
}

void MainWindow::on_theory_back_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->theory_menu);
}

void MainWindow::on_history_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->history);
}
