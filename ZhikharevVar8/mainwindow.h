#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>

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

private:
    Ui::MainWindow *ui;

    // Мои функции:
    void ComboBoxChanged(const QComboBox* currentBox, QComboBox* box1, QComboBox* box2, const int currentTextIndex);
};
#endif // MAINWINDOW_H
