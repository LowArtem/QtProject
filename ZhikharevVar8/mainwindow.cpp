#include "mainwindow.h"
#include "ui_mainwindow.h"


// список предметов
QList<QString> Lessons;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Настройка валидации textbox'a
    QValidator *validator = new CustomValidator(this);
    ui->nameLine->setValidator(validator);

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
        ui->scoreSB_2->setReadOnly(false);
        ui->scoreSB_3->setReadOnly(false);
    }
}


void MainWindow::on_saveBtn_clicked()
{
    // нажатие на кнопку "Сохранить запись"

    // Сохранение только при условии верного ввода
    if (ui->nameLine->hasAcceptableInput())
    {
        if (ui->dataSelectorCB->currentText().contains("1"))
        { // выбрана запись 1
            saveData(data1);
        }
        else
        { // выбрана запись 2
            saveData(data2);
        }

    }
    else
    {
        QMessageBox::warning(this, "Корректность ввода", "ФИО введено неверно");
    }
}

void MainWindow::on_openBtn_clicked()
{
    // нажатие на кнопку "Отменить"

    // вывод выбраной записи
    if (ui->dataSelectorCB->currentText().contains("1"))
    { // выбрана запись 1
        if (!data1.getName().isNull())
            getData(data1);
        else {
            QMessageBox::warning(this, "Ошибка", "Данная запись пустая");
        }
    }
    else
    { // выбрана запись 2
        if (!data2.getName().isNull())
            getData(data2);
        else {
            QMessageBox::warning(this, "Ошибка", "Данная запись пустая");
        }
    }
}


void MainWindow::on_lessonLW_1_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ListWidgetItemChanged(current, previous, ui->lessonLW_2, ui->lessonLW_3);
}

void MainWindow::on_lessonLW_2_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ListWidgetItemChanged(current, previous, ui->lessonLW_1, ui->lessonLW_3);
}

void MainWindow::on_lessonLW_3_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ListWidgetItemChanged(current, previous, ui->lessonLW_1, ui->lessonLW_2);
}


// Приватные функции:

void MainWindow::ListWidgetItemChanged(QListWidgetItem *current, QListWidgetItem *previous, QListWidget* lw1, QListWidget* lw2)
{
    // Менеджер элементов listWidget: удаляет выбранный элемент из других виджетов, возвращает удаленные ранее, если они больше не выбраны

    if (previous != nullptr)
    {
        lw1->addItem(previous->text());
        lw2->addItem(previous->text());
    }

    auto items = lw1->findItems(current->text(), Qt::MatchExactly);
    if (items.length() == 1)
    {
        delete lw1->takeItem(lw1->row(items[0]));
    }

    items = lw2->findItems(current->text(), Qt::MatchExactly);
    if (items.length() == 1)
    {
        delete lw2->takeItem(lw2->row(items[0]));
    }
}

Lesson MainWindow::CastListWidgetToLesson(const QListWidget *lw) const
{
    // Перевод текста в qlistwidget в объект перечисления Lesson

    if (lw->currentItem()->text() == "Математика I")
        return Lesson::MATH1;
    if (lw->currentItem()->text() == "Математика II")
        return Lesson::MATH2;
    if (lw->currentItem()->text() == "Физика")
        return Lesson::PHYSICS;
    if (lw->currentItem()->text() == "Физика II")
        return Lesson::PHYSICS2;
    if (lw->currentItem()->text() == "Русский язык")
        return Lesson::RUSSIAN;

    else throw new QException();
}

QString MainWindow::CastLessonToString(const Lesson lesson) const
{
    // Перевод объекта перечисления Lesson в текст

    switch (lesson) {
    case Lesson::MATH1: return "Математика I";
    case Lesson::MATH2: return "Математика II";
    case Lesson::PHYSICS: return "Физика";
    case Lesson::PHYSICS2: return "Физика II";
    case Lesson::RUSSIAN: return "Русский язык";
    }

    throw new QException();
}

void MainWindow::saveData(ApplicantData &data)
{
    QString name = ui->nameLine->text();
    QDate birthDate = ui->birthdateEdit->date();

    Sex sex;
    if (ui->maleRB->isEnabled())
        sex = Sex::MALE;
    else if (ui->femaleRB->isEnabled())
        sex = Sex::FEMALE;
    else
        sex = Sex::OTHER;

    bool hasMedal = ui->medalCheckB->isChecked();
    double averageScore = ui->averageScoreDB->value();

    QList<Language> foreignLanguages;
    if (ui->engCB->isChecked())
        foreignLanguages.append(Language::ENGLISH);
    if (ui->gerCB->isChecked())
        foreignLanguages.append(Language::GERMANY);
    if (ui->frCB->isChecked())
        foreignLanguages.append(Language::FRENCH);
    if (ui->korCB->isChecked())
        foreignLanguages.append(Language::KOREAN);
    if (ui->chinCB->isChecked())
        foreignLanguages.append(Language::CHINA);
    if (ui->japCB->isChecked())
        foreignLanguages.append(Language::JAPAN);


    data.setName(name);
    data.setBirthDate(birthDate);
    data.setSex(sex);
    data.setHasMedal(hasMedal);
    data.setAverageScore(averageScore);
    data.setForeignLanguage(foreignLanguages);

    Lesson lesson = CastListWidgetToLesson(ui->lessonLW_1);
    int score = ui->scoreSB_1->value();

    data.addExamScore(lesson, score);

    lesson = CastListWidgetToLesson(ui->lessonLW_2);
    score = ui->scoreSB_2->value();

    data.addExamScore(lesson, score);

    lesson = CastListWidgetToLesson(ui->lessonLW_3);
    score = ui->scoreSB_3->value();

    data.addExamScore(lesson, score);

    data.setIsReadyForContract(ui->contractCheckB->isChecked());
}

void MainWindow::getData(ApplicantData &data)
{
    ui->nameLine->setText(data.getName());
    ui->birthdateEdit->setDate(data.getBirthDate());

    Sex sex = data.getSex();
    if (sex == Sex::MALE)
        ui->maleRB->setChecked(true);
    else if (sex == Sex::FEMALE)
        ui->femaleRB->setChecked(true);
    else
        ui->otherRB->setChecked(true);

    ui->medalCheckB->setChecked(data.getHasMedal());
    ui->averageScoreDB->setValue(data.getAverageScore());

    QList<Language> foreignLanguages = data.getForeignLanguage();

    ui->engCB->setChecked(foreignLanguages.contains(Language::ENGLISH));
    ui->gerCB->setChecked(foreignLanguages.contains(Language::GERMANY));
    ui->frCB->setChecked(foreignLanguages.contains(Language::FRENCH));
    ui->korCB->setChecked(foreignLanguages.contains(Language::KOREAN));
    ui->chinCB->setChecked(foreignLanguages.contains(Language::CHINA));
    ui->japCB->setChecked(foreignLanguages.contains(Language::JAPAN));

    QMap<Lesson, int> examScores = data.getExamScores();
    QMapIterator<Lesson, int> score(examScores);
    score.next();

    QList<QListWidgetItem *> founded = ui->lessonLW_1->findItems(CastLessonToString(score.key()), Qt::MatchExactly);
    if (founded.length() == 1)
    {
        ui->lessonLW_1->setCurrentItem(founded[0]);
    }
    ui->scoreSB_1->setValue(score.value());

    score.next();
    founded = ui->lessonLW_2->findItems(CastLessonToString(score.key()), Qt::MatchExactly);
    if (founded.length() == 1)
    {
        ui->lessonLW_2->setCurrentItem(founded[0]);
    }
    ui->scoreSB_2->setValue(score.value());

    score.next();
    founded = ui->lessonLW_3->findItems(CastLessonToString(score.key()), Qt::MatchExactly);
    if (founded.length() == 1)
    {
        ui->lessonLW_3->setCurrentItem(founded[0]);
    }
    ui->scoreSB_3->setValue(score.value());

    ui->contractCheckB->setChecked(data.getIsReadyForContract());
}































