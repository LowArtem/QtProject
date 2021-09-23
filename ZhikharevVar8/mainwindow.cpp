#include "mainwindow.h"
#include "ui_mainwindow.h"


// список предметов
QList<QString> Lessons;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // установка допустимых значений averageScoreDB при запуске программы
    // если медаль есть
    if (ui->medalCheckB->isChecked())
    {
        this->on_medalCheckB_stateChanged(1);
    }
    // если медали нет
    else
    {
        this->on_medalCheckB_stateChanged(0);
    }



    // заполнение списка предметов
    Lessons << "Математика I" << "Математика II" << "Физика" << "Физика II" << "Русский язык";
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_medalCheckB_stateChanged(int arg1)
{
    // установка допустимых значений averageScoreDB при изменении состояния наличия медали

    // нет медали
    if (arg1 == 0)
    {
        ui->averageScoreDB->setMinimum(3.0);
        ui->averageScoreDB->setMaximum(4.5);                
    }
    // есть медаль
    else
    {
        ui->averageScoreDB->setMinimum(4.6);
        ui->averageScoreDB->setMaximum(5.0);        
    }

    this->on_scoreSB_1_valueChanged(ui->scoreSB_1->value());
}


void MainWindow::on_lessonCB_1_currentIndexChanged(int index)
{
    // обеспечения отсутствия повторений предметов из lessonCB_1 в остальных lesson combobox'ах
    ComboBoxChanged(ui->lessonCB_1, ui->lessonCB_2, ui->lessonCB_3, index);
}


void MainWindow::on_lessonCB_2_currentIndexChanged(int index)
{
    // обеспечения отсутствия повторений предметов из lessonCB_2 в остальных lesson combobox'ах
    ComboBoxChanged(ui->lessonCB_2, ui->lessonCB_1, ui->lessonCB_3, index);
}


void MainWindow::on_lessonCB_3_currentIndexChanged(int index)
{
    // обеспечения отсутствия повторений предметов из lessonCB_3 в остальных lesson combobox'ах
    ComboBoxChanged(ui->lessonCB_3, ui->lessonCB_1, ui->lessonCB_2, index);
}


void MainWindow::on_scoreSB_1_valueChanged(int arg1)
{
    // есть медаль и оценка за первый экзамен >= 90
    if (ui->medalCheckB->isChecked() && arg1 >= 90)
    {
        ui->scoreSB_2->setValue(100);
        ui->scoreSB_2->setReadOnly(true);

        ui->scoreSB_3->setValue(100);
        ui->scoreSB_3->setReadOnly(true);
    }
    // нет медали или оценка за первый экзамен < 90
    else
    {
        ui->scoreSB_2->setValue(0);
        ui->scoreSB_2->setReadOnly(false);

        ui->scoreSB_3->setValue(0);
        ui->scoreSB_3->setReadOnly(false);
    }
}






// Приватные функции:

void MainWindow::ComboBoxChanged(const QComboBox* currentBox, QComboBox* box1, QComboBox* box2, const int currentTextIndex)
{
    // обеспечения отсутствия повторений предметов в lesson combobox'ах

    if (currentTextIndex > -1)
    {
        QString currentText = currentBox->currentText();
        QString currentBox1Text = box1->currentText();
        QString currentBox2Text = box2->currentText();

        int foundItemIndex = box1->findText(currentText);
        box1->removeItem(foundItemIndex);

        foundItemIndex = box2->findText(currentText);
        box2->removeItem(foundItemIndex);

       foreach (QString lesson, Lessons)
       {
           if (box1->findText(lesson) == -1 && lesson != currentText && lesson != currentBox2Text)
           {
               box1->addItem(lesson);
           }
           if (box2->findText(lesson) == -1 && lesson != currentText && lesson != currentBox1Text)
           {
               box2->addItem(lesson);
           }
       }
    }
}


