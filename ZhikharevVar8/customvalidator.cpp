#include "customvalidator.h"

CustomValidator::CustomValidator(QObject *parent) : QValidator(parent)
{

}

CustomValidator::~CustomValidator()
{

}

QValidator::State CustomValidator::validate(QString &string, int &pos) const
{
    // Не больше 45 символов
    if (string.length() > 45)
    {
        return QValidator::Invalid;
    }

    int spaceCounter = 0; // счетчик пробелов

    for (int i = 0; i < string.length(); i++)
    {
        // Только буквы и пробелы
        if (!string[i].isLetter() && string[i] != ' ')
        {
            return QValidator::Invalid;
        }

        // Первая буква каждого слова заглавная
        if (i == 0 || string[i-1] == ' ')
        {
            if (!string[i].isUpper())
            {
                return QValidator::Invalid;
            }
        }

        // Подсчет кол-ва пробелов
        if (string[i] == ' ')
        {
            spaceCounter++;
        }
    }

    // Должно быть 3 слова
    if (spaceCounter != 2)
    {
        return QValidator::Intermediate;
    }


    return QValidator::Acceptable;
}
