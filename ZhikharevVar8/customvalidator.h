#ifndef CUSTOMVALIDATOR_H
#define CUSTOMVALIDATOR_H

#include <QValidator>

class CustomValidator : public QValidator
{
    Q_OBJECT
public:
    CustomValidator(QObject *parent);
    ~CustomValidator();

    QValidator::State validate(QString & string, int & pos) const;
};

#endif // CUSTOMVALIDATOR_H
