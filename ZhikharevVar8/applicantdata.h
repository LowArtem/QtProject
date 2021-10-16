#ifndef APPLICANTDATA_H
#define APPLICANTDATA_H

#include <QObject>
#include <QDate>
#include <QMap>
#include <QList>

enum Sex
{
    MALE, FEMALE, OTHER
};

enum Language
{
    ENGLISH, GERMANY, FRENCH, KOREAN, CHINA, JAPAN
};

enum Lesson
{
    MATH1, MATH2, PHYSICS, PHYSICS2, RUSSIAN
};

class ApplicantData
{   
public:
    ApplicantData();

    ApplicantData(QString &name, QDate &birthDate, Sex sex, bool hasMedal,
                  double averageScore, QList<Language> foreignLanguages, QMap<Lesson, int> &examScores);

    ApplicantData(QString &name, QDate &birthDate, Sex sex, bool hasMedal,
                  double averageScore, QList<Language> foreignLanguages);

    QString getName() const;
    void setName(const QString &);

    QDate getBirthDate() const;
    void setBirthDate(const QDate &);

    Sex getSex() const;
    void setSex(const Sex &);

    bool getHasMedal() const;
    void setHasMedal(const bool &);

    double getAverageScore() const;
    void setAverageScore(const double &);

    QList<Language> getForeignLanguage() const;
    void setForeignLanguage(const QList<Language> &);
    void addForeignLanguage(const Language &);
    void deleteForeignLanguage(const Language &);

    QMap<Lesson, int> getExamScores() const;
    void setExamScores(const QMap<Lesson, int> &);
    void addExamScore(const Lesson &, const int &);
    void deleteExamScore(const Lesson &);
    int getExamScore(const Lesson &);

    bool getIsReadyForContract() const;
    void setIsReadyForContract(const bool &);

private:
    QString _name;
    QDate _birthDate;
    Sex _sex;
    bool _hasMedal;
    double _averageScore;
    QList<Language> _foreignLanguage;
    QMap<Lesson, int> _examScores;
    bool _isReadyForContract;
};

#endif // APPLICANTDATA_H
