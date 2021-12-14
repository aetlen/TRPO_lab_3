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