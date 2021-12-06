#ifndef CALCULATORCONTROL_H
#define CALCULATORCONTROL_H

#include <QObject>

class CalculatorControl : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int userInput READ getUserInput WRITE setUserInput NOTIFY userInputChanged)
    Q_PROPERTY(int result READ getResult WRITE setResult NOTIFY resultChanged)
    Q_PROPERTY(QChar sign READ getSign WRITE setSign NOTIFY signChanged)
    Q_PROPERTY(CalculatorSymbol calculatorSymbol READ getCalculatorSymbol WRITE setCalculatorSymbol NOTIFY calculatorSymbolChanged)
public:
    explicit CalculatorControl(QObject *parent = nullptr);
    ////////////////////////////////////////////////////////////////////////
    enum CalculatorSymbol{
        NONE,
        ADDITION,
        SUBTRACTION,
        MULTIPLICATION,
        DIVISIN,
        CLEAR,
        EQUAL
    };
    Q_ENUM(CalculatorSymbol);
    //CalculatorSymbol calculatorSymbol() const;
    CalculatorSymbol getCalculatorSymbol() const;
    void setCalculatorSymbol(CalculatorSymbol newCalculatorSymbol); // powoduje ustawienie znaku
    ////////////////////////////////////////////////////////////////////////
    // Wybrana Liczba
    Q_INVOKABLE int getUserInput() const;
    Q_INVOKABLE void setUserInput(int newUserInput);

    ////////////////////////////////////////////////////////////////////////
    // Wynik
    Q_INVOKABLE int getResult() const;
    Q_INVOKABLE void setResult(int newResult);


    Q_INVOKABLE void handleOperation(CalculatorSymbol newCalculatorSymbol);

    const QChar &getSign() const;
    Q_INVOKABLE void setSign(const QChar &newSign);

signals:

    void calculatorSymbolChanged();
    void userInputChanged();
    void resultChanged();

    void signChanged();

public slots:


private:
    CalculatorSymbol m_calculatorSymbol;
    int m_userInput;
    int m_result;

    /**
     * A simple addition method
     */
    int add( int A, int B);

    /**
     * A simple subtraction method
     */
    int subtract( int A, int B);
    QChar m_sign;
};

#endif // CALCULATORCONTROL_H
