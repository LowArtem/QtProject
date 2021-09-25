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

class ApplicantData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QDate birthDate READ birthDate WRITE setBirthDate)
    Q_PROPERTY(Sex sex READ sex WRITE setSex)
    Q_PROPERTY(bool hasMedal READ hasMedal WRITE setHasMedal)
    Q_PROPERTY(double averageScore READ averageScore WRITE setAverageScore)
    Q_PROPERTY(QList<Language> foreignLanguage READ foreignLanguage WRITE setForeignLanguage)
    Q_PROPERTY(QMap<Lesson, int> examScores READ examScores WRITE setExamScores)
public:
    ApplicantData(QObject *parent);
    ApplicantData(QObject *parent, QString &name, QDate &birthDate, Sex sex, bool hasMedal,
                  double averageScore, QList<Language> foreignLanguage, QMap<Lesson, int> &examScore);
    ApplicantData(QObject *parent, QString &name, QDate &birthDate, Sex sex, bool hasMedal,
                  double averageScore, QList<Language> foreignLanguage);

    QString name() const;
    void setName(const QString &);

    QDate birthDate() const;
    void setBirthDate(const QDate &);

    Sex sex() const;
    void setSex(const Sex &);

    bool hasMedal() const;
    void setHasMedal(const bool &);

    double averageScore() const;
    void setAverageScore(const double &);

    QList<Language> foreignLanguage() const;
    void setForeignLanguage(const QList<Language> &);
    void addForeignLanguage(const Language &);
    void deleteForeignLanguage(const Language &);

    QMap<Lesson, int> examScores() const;
    void setExamScores(const QMap<Lesson, int> &);
    void addExamScore(const Lesson &, const int &);
    void deleteExamScore(const Lesson &);
    int getExamScore(const Lesson &);

private:
    QString _name;
    QDate _birthDate;
    Sex _sex;
    bool _hasMedal;
    double _averageScore;
    QList<Language> _foreignLanguage;
    QMap<Lesson, int> _examScores;
};

#endif // APPLICANTDATA_H
