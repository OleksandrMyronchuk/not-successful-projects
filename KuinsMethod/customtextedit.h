#ifndef CUSTOMTEXTEDIT_H
#define CUSTOMTEXTEDIT_H

#include <QTextEdit>
#include <QKeyEvent>
#include <exception>
#include "expression.h"

enum eVar{notX = false, X = true};
enum ePNF{PCNF = false, PDNF = true};

class errorNotInit : public std::exception
{
    const char* what() const noexcept
    {
        return "Error! You did not init \"PNFtype\", \"setNumVars\" or both of them\n";
    }
};

struct sVar
{
    QChar visible;
    char internal;
};

class CustomTextEdit : public QTextEdit
{
public:
    explicit CustomTextEdit(QWidget *parent = 0);
    ~CustomTextEdit();
    void input(bool);
    void setPNFtype(bool);
    void setNumVars(unsigned int);
    MLF::expression* getExpression();
private:
    MLF::expression *exp;
    sVar _symVar;
    sVar _symGrp;
    bool _brackets;
    unsigned int _numVars;
    unsigned char init { 0 };
    int getCurrectPos();
protected:
    void keyReleaseEvent(QKeyEvent *e);
};

#endif // CUSTOMTEXTEDIT_H
