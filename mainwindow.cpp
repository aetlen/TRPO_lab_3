#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <cmath>
couple alumel;
couple volfram;
couple gold;
couple consta;
couple kopel;
couple copper;
couple molib;
couple plat;
couple chromel;
couple tellur;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Расчет параметров термопар");


    ui->voltage_label->hide();
    ui->Thot_label->hide();
    ui->Tcold_label->hide();
    ui->dT_label->hide();
    ui->couple1_label->hide();
    ui->couple2_label->hide();
    ui->stackedMain->setCurrentWidget(ui->modeling);
    ui->stackedWidget->setCurrentWidget(ui->theory_menu);
    ui->stackedWidget_2->setCurrentWidget(ui->setup);

     alumel.name = "Алюмель"; alumel.alpha = -10.2; alumel.r0 = 0.33; alumel.tm = 1400;
     volfram.name = "Вольфрам"; volfram.alpha = 7.9; volfram.r0 = 0.05; volfram.tm = 3422;
     gold.name = "Золото"; gold.alpha = 8; gold.r0 = 0.023; gold.tm = 1064;
     consta.name = "Константан"; consta.alpha = -35; consta.r0 = 0.5; consta.tm = 1260;
     kopel.name = "Копель"; kopel.alpha = -40; kopel.r0 = 0.47; kopel.tm = 1220;
     copper.name = "Медь"; copper.alpha = 7.6; copper.r0 =  0.0172; copper.tm = 1083;
     molib.name = "Молибден"; molib.alpha = 1.3; molib.r0 = 0.05; molib.tm = 2623;
     plat.name = "Платинородий"; plat.alpha = 6.46; plat.r0 = 0.1; plat.tm = 1768;
     chromel.name = "Хромель"; chromel.alpha = 31.3; chromel.r0 = 0.68; chromel.tm = 1500;
     tellur.name = "Теллур"; tellur.alpha = 500; tellur.r0 = 0.29; tellur.tm = 722;

    ui->couple1->addItem(alumel.name);
    ui->couple1->addItem(volfram.name);
    ui->couple1->addItem(gold.name);
    ui->couple1->addItem(consta.name);
    ui->couple1->addItem(kopel.name);
    ui->couple1->addItem(copper.name);
    ui->couple1->addItem(molib.name);
    ui->couple1->addItem(plat.name);
    ui->couple1->addItem(chromel.name);
    ui->couple1->addItem(tellur.name);


    ui->couple2->addItem(alumel.name);
    ui->couple2->addItem(volfram.name);
    ui->couple2->addItem(gold.name);
    ui->couple2->addItem(consta.name);
    ui->couple2->addItem(kopel.name);
    ui->couple2->addItem(copper.name);
    ui->couple2->addItem(molib.name);
    ui->couple2->addItem(plat.name);
    ui->couple2->addItem(chromel.name);
    ui->couple2->addItem(tellur.name);

    ui->param_mode->addItem("Выберите режим");
    ui->param_mode->addItem("Выбрать готовую");
    ui->param_mode->addItem("Через параметры");

    ui->find_param->addItem("Выберите параметр");
    ui->find_param->addItem("U");
    ui->find_param->addItem("I");
    ui->find_param->addItem("P");
    ui->find_param->addItem("Rн");
    ui->find_param->addItem("T");
    ui->find_param->addItem("alpha");
    ui->find_param->addItem("Rвн");

    QButtonGroup *buttonGroup2 = new QButtonGroup;
        buttonGroup2->addButton(ui->Tcold_button, 0);
        buttonGroup2->addButton(ui->Thot_button, 1);
        buttonGroup2->addButton(ui->dT_button, 2);
        connect(buttonGroup2, SIGNAL(buttonClicked(int)), this, SLOT(hideTemp()));

        connect(ui->Tcold, SIGNAL(textChanged(QString)), this, SLOT(calculateTemp()));
        connect(ui->Thot, SIGNAL(textChanged(QString)), this, SLOT(calculateTemp()));
        connect(ui->dT, SIGNAL(textChanged(QString)), this, SLOT(calculateTemp()));
        connect(ui->couple1, SIGNAL(currentIndexChanged(int)), this, SLOT(setCurrentCouple()));
        connect(ui->couple2, SIGNAL(currentIndexChanged(int)), this, SLOT(setCurrentCouple()));
        connect(ui->param_mode, SIGNAL(currentIndexChanged(int)), this, SLOT(setParamMode()));
        connect(ui->find_param, SIGNAL(currentIndexChanged(int)), this, SLOT(setFindParam()));
        connect(ui->voltage, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->current, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->power, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->rn, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->Tcold, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->Thot, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->dT, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->alpha, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        connect(ui->rvn, SIGNAL(textEdited(QString)), this, SLOT(calculating()));
        checkSt();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::set(QString obj, float value)
{
    if(obj == "voltage")
        ui->voltage->setText(QString::number(value));
    if(obj == "current")
        ui->current->setText(QString::number(value));
    if(obj == "power")
        ui->power->setText(QString::number(value));
    if(obj == "rn")
        ui->rn->setText(QString::number(value));
    if(obj == "Tcold")
        ui->Tcold->setText(QString::number(value));
    if(obj == "Thot")
        ui->Thot->setText(QString::number(value));
    if(obj == "dT")
        ui->dT->setText(QString::number(value));
    if(obj == "alpha")
        ui->alpha->setText(QString::number(value));
    if(obj == "rvn")
        ui->rvn->setText(QString::number(value));
}



float MainWindow::get(QString obj)
{
    if(obj == "voltage")
        return ui->voltage->text().toFloat();
    if(obj == "current")
        return ui->current->text().toFloat();
    if(obj == "power")
        return ui->power->text().toFloat();
    if(obj == "rn")
        return ui->rn->text().toFloat();
    if(obj == "Tcold")
        return ui->Tcold->text().toFloat();
    if(obj == "Thot")
        return ui->Thot->text().toFloat();
    if(obj == "dT")
        return ui->dT->text().toFloat();
    if(obj == "alpha")
        return ui->alpha->text().toFloat();
    if(obj == "rvn")
        return ui->rvn->text().toFloat();
}

void MainWindow::calculating()
{
    if(ui->find_param->currentIndex() == 1) calculateVoltage();
    if(ui->find_param->currentIndex() == 2) calculateCurrent();
    if(ui->find_param->currentIndex() == 3) calculatePower();
    if(ui->find_param->currentIndex() == 4) calculateRn();
    if(ui->find_param->currentIndex() == 5) calculateT();
    if(ui->find_param->currentIndex() == 6) calculateAlpha();
    if(ui->find_param->currentIndex() == 7) calculateRvn();
}

void MainWindow::checkSt()
{
    if(ui->find_param->currentIndex() == 0 || ui->param_mode->currentIndex() == 0)
    {
        ui->voltage->setEnabled(false);
        ui->current->setEnabled(false);
        ui->power->setEnabled(false);
        ui->rn->setEnabled(false);
        ui->dT_button->setEnabled(false);
        ui->Tcold_button->setEnabled(false);
        ui->Thot_button->setEnabled(false);
        ui->dT->setEnabled(false);
        ui->Tcold->setEnabled(false);
        ui->Thot->setEnabled(false);
        ui->alpha->setEnabled(false);
        ui->rvn->setEnabled(false);
        ui->couple1->setEnabled(false);
        ui->couple2->setEnabled(false);
        ui->statusbar->showMessage("Задайте настройки",5000);
    }
    else
    {
        ui->voltage->setEnabled(true);
        ui->current->setEnabled(true);
        ui->power->setEnabled(true);
        ui->rn->setEnabled(true);
        ui->dT_button->setEnabled(true);
        ui->Tcold_button->setEnabled(true);
        ui->Thot_button->setEnabled(true);
        ui->dT->setEnabled(true);
        ui->Tcold->setEnabled(true);
        ui->Thot->setEnabled(true);
        ui->alpha->setEnabled(true);
        ui->rvn->setEnabled(true);
        ui->couple1->setEnabled(true);
        ui->couple2->setEnabled(true);
        ui->dT_button->click();
        hideTemp();
        setParamMode();
        setFindParam();
    }

}

void MainWindow::setParamMode()
{
    ui->statusbar->showMessage(QString::number(ui->param_mode->currentIndex()),2000);
    ui->couple1->setEnabled(true);
    ui->couple2->setEnabled(true);
    ui->alpha->setEnabled(true);
    ui->rvn->setEnabled(true);
    if(ui->param_mode->currentIndex() == 1)
    {
        ui->alpha->setEnabled(false);
        ui->rvn->setEnabled(false);
    }
    if(ui->param_mode->currentIndex() == 2)
    {
        ui->couple1->setEnabled(false);
        ui->couple2->setEnabled(false);
    }
}

void MainWindow::setFindParam()
{
    ui->voltage->setEnabled(true);
    ui->current->setEnabled(true);
    ui->power->setEnabled(true);
    ui->rn->setEnabled(true);
    ui->dT_button->setEnabled(true);
    ui->dT->setEnabled(true);
    ui->alpha->setEnabled(true);
    ui->rvn->setEnabled(true);
    ui->dT_button->click();

   if(ui->find_param->currentIndex() == 1) ui->voltage->setEnabled(false);
   if(ui->find_param->currentIndex() == 2) ui->current->setEnabled(false);
   if(ui->find_param->currentIndex() == 3) ui->power->setEnabled(false);
   if(ui->find_param->currentIndex() == 4) ui->rn->setEnabled(false);
   if(ui->find_param->currentIndex() == 5) {
       if(ui->dT_button->isChecked())
           ui->Tcold_button->click();
       ui->dT_button->setEnabled(false);
       ui->dT->setEnabled(false);
   }
   if(ui->find_param->currentIndex() == 6) ui->alpha->setEnabled(false);
   if(ui->find_param->currentIndex() == 7) ui->rvn->setEnabled(false);
}

void MainWindow::calculateRvn()
{
    set("rvn", get("voltage") / get("current") - get("rn"));
}

void MainWindow::calculateRn()
{
    set("rn", get("voltage") / get("current"));
}

void MainWindow::calculateVoltage()
{
    float m = get("rn") / get("rvn");
    if(ui->param_mode->currentIndex() == 1)
    {
        set("voltage", 2 * (abs(this->currentCouple1.alpha - this->currentCouple2.alpha)) / 1000000 * get("dT") * (m / (1 + m)));
    }
    if(ui->param_mode->currentIndex() == 2)
    {
        set("voltage", 2 * get("alpha") / 1000000 * get("dT") * (m / (1 + m)));
    }
}

void MainWindow::calculateCurrent()
{
    set("current", get("voltage") / get("rn"));
}

void MainWindow::calculatePower()
{
    set("power", get("voltage") * get("current"));
}

void MainWindow::calculateT()
{
     set("alpha", get("current") * (get("rvn") + get("rn")) / get("alpha"));
}

void MainWindow::calculateAlpha()
{
    set("alpha", get("current") * (get("rvn") + get("rn")) / get("dT"));
}

void MainWindow::setCurrentCouple()
{
    switch(ui->couple1->currentIndex())
    {
        case 0: this->currentCouple1 = alumel; break;
        case 1: this->currentCouple1 = volfram; break;
        case 2: this->currentCouple1 = gold; break;
        case 3: this->currentCouple1 = consta; break;
        case 4: this->currentCouple1 = kopel; break;
        case 5: this->currentCouple1 = copper; break;
        case 6: this->currentCouple1 = molib; break;
        case 7: this->currentCouple1 = plat; break;
        case 8: this->currentCouple1 = chromel; break;
        case 9: this->currentCouple1 = tellur; break;
    }
    switch(ui->couple2->currentIndex())
    {
        case 0: this->currentCouple2 = alumel; break;
        case 1: this->currentCouple2 = volfram; break;
        case 2: this->currentCouple2 = gold; break;
        case 3: this->currentCouple2 = consta; break;
        case 4: this->currentCouple2 = kopel; break;
        case 5: this->currentCouple2 = copper; break;
        case 6: this->currentCouple2 = molib; break;
        case 7: this->currentCouple2 = plat; break;
        case 8: this->currentCouple2 = chromel; break;
        case 9: this->currentCouple2 = tellur; break;
    }
    calculating();
    
}


void MainWindow::calculateTemp()
{
    if(!ui->Tcold->isEnabled())
        set("Tcold", get("Thot") - get("dT"));
    if(!ui->Thot->isEnabled())
        set("Thot", get("Tcold") + get("dT"));
    if(!ui->dT->isEnabled())
        set("dT", get("Thot") - get("Tcold"));
}

void MainWindow::hideTemp()
{
    if(ui->Thot_button->isChecked())
        ui->Thot->setEnabled(false);
    else
        ui->Thot->setEnabled(true);
    if(ui->Tcold_button->isChecked())
        ui->Tcold->setEnabled(false);
    else
        ui->Tcold->setEnabled(true);
    if(ui->dT_button->isChecked())
        ui->dT->setEnabled(false);
    else
        ui->dT->setEnabled(true);
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


void MainWindow::on_param_mode_currentIndexChanged(int index)
{

}

void MainWindow::on_find_param_currentIndexChanged(int index)
{

}

void MainWindow::on_theory_back_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->theory_menu);
}

void MainWindow::on_seebeck_button_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->seebeck_effect);
}
