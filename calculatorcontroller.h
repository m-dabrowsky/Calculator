#ifndef CALCULATORCONTROLLER_H
#define CALCULATORCONTROLLER_H

#include <QObject>

class CalculatorController : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorController(QObject *parent = nullptr);

signals:

};

#endif // CALCULATORCONTROLLER_H
