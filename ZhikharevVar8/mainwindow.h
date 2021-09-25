#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QMessageBox>
#include <QException>

#include "customvalidator.h"
#include "applicantdata.h"

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
    void on_medalCheckB_stateChanged(int arg1);

    void on_lessonCB_1_currentIndexChanged(int index);

    void on_lessonCB_2_currentIndexChanged(int index);

    void on_lessonCB_3_currentIndexChanged(int index);

    void on_scoreSB_1_valueChanged(int arg1);

    void on_saveBtn_clicked();

private:
    Ui::MainWindow *ui;

    // Объекты записей
    ApplicantData data1 = new ApplicantData(this);
    ApplicantData data2 = new ApplicantData(this);

    // Мои функции:
    void ComboBoxChanged(const QComboBox* currentBox, QComboBox* box1, QComboBox* box2, const int currentTextIndex);
    Lesson CastLessonType(const QComboBox* cb) const;
    void saveData(ApplicantData &data);
};
#endif // MAINWINDOW_H
