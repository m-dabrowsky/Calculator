#ifndef CALCULATORLOGIC_H
#define CALCULATORLOGIC_H

#include <QObject>

class CalculatorLogic : public QObject
{
    Q_OBJECT
public:
    explicit CalculatorLogic(QObject *parent = nullptr);

    // ===========================================================
    // GETTERS & SETTERS
    // ===========================================================
    /**
      * Called when operation (div, sub, sum, etc) called.
      *
      * @thread_safety - not thread-safe.
      * @param pType - operation-type in string-format ("+", "/", etc).
      * @returns - output-string to be displayed.
      * @throws - no exceptions.
    **/
    Q_INVOKABLE QString setOperationType( const QString pType ) noexcept;

    // ===========================================================
    // METHODS
    // ===========================================================
//    /**
//      * Called when QML Keyboard Inuput-Event handled.
//      *
//      * @thread_safety - not thread-safe.
//      * @returns - output-string to be displayed.
//      * @throws - no exceptions.
//    **/
//    Q_INVOKABLE QString onKeyboardInput( const QString pValue ) noexcept;


    /**
      * Called when number added to argument.
      *
      * @thread_safety - not thread-safe.
      * @param pNumber - number to add.
      * @returns - output-string to be displayed.
      * @throws - no exceptions.
    **/
    Q_INVOKABLE QString onNumberInput( const QString pNumber ) noexcept;

    /**
      * Calculates result using two arguments & operation-type.
      *
      * @thread_safety - not thread-safe.
      * @return - result in string-type.
      * @throws - no exceptions.
    **/
    Q_INVOKABLE QString doMath( ) noexcept;

    /**
      * Reset Calculator Logic State.
      *
      * @thread_safety - not thread-safe.
      * @throws - no exceptions.
    **/
    Q_INVOKABLE void resetLogic( ) noexcept;

private:
    // ===========================================================
    // CONSTANTS
    // ===========================================================

    /** NONE **/
    static const unsigned char NONE_OPERATION_TYPE = 0;

    /** + **/
    static const unsigned char SUM_OPERATION_TYPE = 1;

    /** - **/
    static const unsigned char SUB_OPERATION_TYPE = 2;

    /** / **/
    static const unsigned char DIV_OPERATION_TYPE = 3;

    /** * **/
    static const unsigned char MUL_OPERATION_TYPE = 4;


    // ===========================================================
    // FIELDS
    // ===========================================================

    /** Stored Value. **/
    QString mStoredValue;

    /** First argument. **/
    QString mLeftArg;

    /** Right Argument **/
    QString mRightArg;

    /** Cached Output-String. **/
    QString mOutput;

    /** Operation-Type **/
    unsigned char mOperationType;

    // ===========================================================
    // METHODS
    // ===========================================================

    /**
      * Updates Output-string.
      *
      * @thread_safety - not thread-safe.
      * @throws - no exceptions.
    **/
    void onUpdateOutput( ) noexcept;

    /**
      * Called to clear (reset) state after calculation.
      *
      * (?) Unlikely #resetLogic() this method doesn't resets
      * stored items & output.
      *
      * @thread_safety - not thread-safe.
      * @throws - no exceptions.
    **/
    void onCalculationDone( ) noexcept;


signals:

};

#endif // CALCULATORLOGIC_H
