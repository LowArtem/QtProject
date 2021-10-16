#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QList>
#include <QMessageBox>
#include <QException>
#include <QListWidget>

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

    void on_scoreSB_1_valueChanged(int arg1);

    void on_saveBtn_clicked();

    void on_lessonLW_1_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_lessonLW_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_lessonLW_3_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_openBtn_clicked();

private:
    Ui::MainWindow *ui;

    // Объекты записей
    ApplicantData data1;
    ApplicantData data2;

    // Мои функции:
    void ListWidgetItemChanged(QListWidgetItem *current, QListWidgetItem *previous, QListWidget* lw1, QListWidget* lw2);
    Lesson CastListWidgetToLesson(const QListWidget *lw) const;
    QString CastLessonToString(const Lesson lesson) const;
    void saveData(ApplicantData &data);
    void getData(ApplicantData &data);
};
#endif // MAINWINDOW_H
