#include "applicantdata.h"

ApplicantData::ApplicantData(QObject *parent) : QObject(parent)
{

}

ApplicantData::ApplicantData(QObject *parent, QString &name, QDate &birthDate, Sex sex, bool hasMedal, double averageScore, QList<Language> foreignLanguage, QMap<Lesson, int> &examScore) : QObject(parent)
{
    this->setName(name);
    this->setBirthDate(birthDate);
    this->setSex(sex);
    this->setHasMedal(hasMedal);
    this->setAverageScore(averageScore);
    this->setForeignLanguage(foreignLanguage);
    this->setExamScores(examScore);
}

ApplicantData::ApplicantData(QObject *parent, QString &name, QDate &birthDate, Sex sex, bool hasMedal, double averageScore, QList<Language> foreignLanguage) : QObject(parent)
{
    this->setName(name);
    this->setBirthDate(birthDate);
    this->setSex(sex);
    this->setHasMedal(hasMedal);
    this->setAverageScore(averageScore);
    this->setForeignLanguage(foreignLanguage);
}

QString ApplicantData::name() const
{
    return this->_name;
}

void ApplicantData::setName(const QString &name)
{
    this->_name = name;
}

QDate ApplicantData::birthDate() const
{
    return this->_birthDate;
}

void ApplicantData::setBirthDate(const QDate &date)
{
    this->_birthDate = date;
}

Sex ApplicantData::sex() const
{
    return this->_sex;
}

void ApplicantData::setSex(const Sex &sex)
{
    this->_sex = sex;
}

bool ApplicantData::hasMedal() const
{
    return this->_hasMedal;
}

void ApplicantData::setHasMedal(const bool &has)
{
    this->_hasMedal = has;
}

double ApplicantData::averageScore() const
{
    return this->_averageScore;
}

void ApplicantData::setAverageScore(const double &score)
{
    this->_averageScore = score;
}

QList<Language> ApplicantData::foreignLanguage() const
{
    return this->_foreignLanguage;
}

void ApplicantData::setForeignLanguage(const QList<Language> &l)
{
    this->_foreignLanguage = l;
}

void ApplicantData::addForeignLanguage(const Language &l)
{
    this->_foreignLanguage.append(l);
}

void ApplicantData::deleteForeignLanguage(const Language &l)
{
    this->_foreignLanguage.removeOne(l);
}

QMap<Lesson, int> ApplicantData::examScores() const
{
    return this->_examScores;
}

void ApplicantData::setExamScores(const QMap<Lesson, int> &es)
{
    this->_examScores = es;
}

void ApplicantData::addExamScore(const Lesson &l, const int &v)
{
    this->_examScores.insert(l, v);
}

void ApplicantData::deleteExamScore(const Lesson &l)
{
    this->_examScores.remove(l);
}

int ApplicantData::getExamScore(const Lesson &l)
{
    return this->_examScores[l];
}




