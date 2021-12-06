#include "calculatorlogic.h"
#include <QDebug>
CalculatorLogic::CalculatorLogic(QObject *parent) : QObject(parent),
    mStoredValue( "" ),
    mLeftArg( "" ),
    mRightArg( "" ),
    mOutput( "" ),
    mOperationType( NONE_OPERATION_TYPE )
{

}


QString CalculatorLogic::setOperationType( const QString pType ) noexcept
{
    qDebug() << "setOperationtype";
    // Cancel, if Arguments are empty.
    if ( mLeftArg.size( ) < 1 && mRightArg.size( ) < 1 )
        return( mOutput );

    if ( pType == "-" )
        mOperationType = SUB_OPERATION_TYPE;
    else if ( pType == "+" )
        mOperationType = SUM_OPERATION_TYPE;
    else if ( pType == "/" )
        mOperationType = DIV_OPERATION_TYPE;
    else if ( pType == "*" )
        mOperationType = MUL_OPERATION_TYPE;

    // Switch Arguments
    mLeftArg = mRightArg; // Copy-Construct
    mRightArg = ""; // Clear/Reset

    // Update Output
    onUpdateOutput( );

    // Return output
    return( mOutput );
}

// ===========================================================
// METHODS
// ===========================================================

/**
  * Updates Output-string.
  *
  * @thread_safety - not thread-safe.
  * @throws - no exceptions.
**/
void CalculatorLogic::onUpdateOutput( ) noexcept
{
    qDebug() << "onUpdate";
    // Reset Output-string.
    mOutput = "";

    // Left Argument
    if ( mLeftArg.size( ) > 0 )
        mOutput += mLeftArg;

    // Operation-Type
    if ( mOperationType != NONE_OPERATION_TYPE )
    {

        // Dodanie symbolu na wyświetlaczu.
        switch( mOperationType )
        {
            case DIV_OPERATION_TYPE:
            {
                mOutput += " / ";
                break;
            }
            case MUL_OPERATION_TYPE:
            {
                mOutput += " * ";
                break;
            }
            case SUB_OPERATION_TYPE:
            {
                mOutput += " - ";
                break;
            }
            default:
                case SUM_OPERATION_TYPE:
                {
                    mOutput += " + ";
                    break;
                }
        }

    } /// Operation-Type

    // Right Argument
    if ( mRightArg.size( ) > 0 )
        mOutput += mRightArg;

    // 0
    if ( mOutput.size( ) < 1 )
        mOutput = "0";
}


void CalculatorLogic::onCalculationDone( ) noexcept
{
    qDebug() << "onCalcuationDone";
    // Reset Left-Argument.
    mLeftArg.clear( );

    // Reset Right-Argument
    mRightArg.clear( );

    // Reset Operation-Type.
    mOperationType = NONE_OPERATION_TYPE;

} /// CalculatorLogic::onCalculationDone

//QString CalculatorLogic::onKeyboardInput( const QString pValue ) noexcept
//{

//    // Filter Number Input
//    if ( pValue == "0" || pValue == "1" || pValue == "2"
//         || pValue == "3" || pValue == "4" || pValue == "5"
//         || pValue == "6" || pValue == "7" || pValue == "8"
//         || pValue == "9" )
//        return( onNumberInput( pValue ) );

//    // Return Output
//    return( mOutput );

//} /// CalculatorLogic::onKeyboardInput

// WYŚWIETLENIE NA EKRANIE LICZB
QString CalculatorLogic::onNumberInput( const QString pVal ) noexcept
{
    qDebug() << "onNumberInput";
    // Dodanie liczby pod danym przyciskiem do mRightArg
    mRightArg += pVal;

    // Update output
    onUpdateOutput( );

    // Return Output
    return( mOutput );

}


QString CalculatorLogic::doMath( ) noexcept
{
    qDebug() << "doMath";
    // Anuluj, jeśli nie wybrano żadnej liczby i nie wybrano żadnego znaku
    if ( mOperationType == NONE_OPERATION_TYPE || mLeftArg.size( ) < 1 )
        return( mOutput );

    // Zamiana lewego argumentu na liczbę
    const double arg1_d( mLeftArg.toDouble(  ) );


    // Zamiana prawego argumentu na liczbę
    const double arg2_d( mRightArg.toDouble( ) );

    // Obliczenia
    switch( mOperationType )
    {
        // Jeśli wybrano odejmowanie
        case SUB_OPERATION_TYPE:
        {
            // Odjęcie
            const auto result_( arg1_d - arg2_d );

            // Konwersja liczby na QString
            mOutput = QString::number( result_ );

            // Reset
            onCalculationDone( );

            // Stop
            break;

        }
        case MUL_OPERATION_TYPE:
        {


            // Mnożenie
            const auto result_( arg1_d * arg2_d );

            // Konwersja liczby na QString
            mOutput = QString::number( result_ );

            // Reset
            onCalculationDone( );

            // Stop
            break;

        }
        case DIV_OPERATION_TYPE:
        {


            // Dzielenie
            const auto result_( arg1_d / arg2_d );

            // Konwersja liczby na QString
            mOutput = QString::number( result_ );

            // Reset
            onCalculationDone( );

            // Stop
            break;

        }
        case SUM_OPERATION_TYPE:
            default:
            {

                // Suma
                const auto result_( arg1_d + arg2_d );

                // Konwersja liczby na QString
                mOutput = QString::number( result_ );

                // Reset
                onCalculationDone( );

                // Stop
                break;

            }
    } /// Calculate

    // Zwrócenie Output
    return( mOutput );

}

// Po naciśnięciu CLEAR
void CalculatorLogic::resetLogic( ) noexcept
{
    qDebug() << "reset";
    // Reset wartości
    mLeftArg = "";
    mRightArg = "";
    mOutput = "0";
    mOperationType = NONE_OPERATION_TYPE;
}
