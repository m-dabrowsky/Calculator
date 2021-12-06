#include "calculatorcontrol.h"
#include <QDebug>
CalculatorControl::CalculatorControl(QObject *parent) : QObject(parent),
    m_userInput(0),
    m_result(0),
    m_calculatorSymbol()
{

}

CalculatorControl::CalculatorSymbol CalculatorControl::getCalculatorSymbol() const
{

}

void CalculatorControl::setCalculatorSymbol(CalculatorSymbol newCalculatorSymbol)
{

}


////////////////////////////////////////////////////////////////////////
// Wybierany przycisk
int CalculatorControl::getUserInput() const
{
    return m_userInput;
}

void CalculatorControl::setUserInput(int newUserInput)
{
    if (m_userInput == newUserInput)
        return;
    m_userInput = newUserInput;
    emit userInputChanged();
}

////////////////////////////////////////////////////////////////////////
// Wynik wyświetlany na wyświetlaczu
int CalculatorControl::getResult() const
{
    return m_result;
}

void CalculatorControl::setResult(int newResult)
{
    if (m_result == newResult)
        return;
    m_result = newResult;
    emit resultChanged();
}


//////////////////////////////////////////////////////////////////////////////////////
int CalculatorControl::add( int A, int B)
{
    return A + B;
}

//////////////////////////////////////////////////////////////////////////////////////
int CalculatorControl::subtract( int A, int B)
{
    return A - B;
}



void CalculatorControl::handleOperation(CalculatorSymbol newCalculatorSymbol)
{
    qDebug() << "UserInput "<<m_userInput;
    qDebug() << "Result "<<m_result;

    if (newCalculatorSymbol == ADDITION){
        m_result = m_result + m_userInput;
        emit resultChanged();
    }else {
        m_result = m_result + m_userInput;
        m_userInput = 0;
        emit resultChanged();
    }
    qDebug() << "UserInput2"<<m_userInput;
    qDebug() << "Result2 "<< m_result;
    emit userInputChanged();
}

const QChar &CalculatorControl::getSign() const
{
    return m_sign;
}

void CalculatorControl::setSign(const QChar &newSign)
{
    if (m_sign == newSign)
        return;
    m_sign = newSign;
    emit signChanged();
}
