#include "customtextedit.h"
#include <QMessageBox>
#include <QDebug>

CustomTextEdit::CustomTextEdit(QWidget *parent) :
    exp(new MLF::expression())
{
    Q_UNUSED( parent );
}

CustomTextEdit::~CustomTextEdit()
{
    delete exp;
}

void CustomTextEdit::keyReleaseEvent(QKeyEvent *e)
{
    if(e->text()==L'\u007F' || e->text()=='\b')
        QTextEdit::clear();
}

void CustomTextEdit::input(bool nameVar) try
{
    QString nVar = nameVar ? "x" : "x\u0305",/*name of variable*/
    result("");
    int currentPos(getCurrectPos()),
    maxPos(this->_numVars);

    if(currentPos == 1)
    {
        if(QTextEdit::toPlainText() != "")
        {
            result += (QString)" " + this->_symGrp.visible + (QString)" ";
            this->exp->arrValue.push_back(_symGrp.internal);
        }
        if(this->_brackets)
            result += "(";
        result += nVar;
        this->exp->arrValue.push_back(nameVar ? 0xFF : 0x00);
    }
    else if(currentPos > 1)
    {
        result += (QString)" " + this->_symVar.visible + (QString)" " + nVar;
        this->exp->arrValue.push_back(_symVar.internal);
        this->exp->arrValue.push_back(nameVar ? 0xFF : 0x00);
    }
    if(currentPos == maxPos && this->_brackets)
    {
        result += ")";
    }

    QTextEdit::insertPlainText( result );
}
catch(std::exception &ex)
{
    QMessageBox::warning(this, tr("Error!"), tr(ex.what()), QMessageBox::Ok);
}

int CustomTextEdit::getCurrectPos()
{
    static unsigned int count(0);
    if(count++ >= this->_numVars) count = 1;
    return count;
}

void CustomTextEdit::setPNFtype(bool PNFtype)
{
    if(PNFtype)/*PDNF*/
    {
        this->_symVar.visible = L'\u2227';
        this->_symGrp.visible = 'v';
        this->_symVar.internal = '*';
        this->_symGrp.internal = '+';
        this->_brackets = true;
        this->exp->key = 1;
    }
    else/*PCNF*/
    {
        this->_symVar.visible = 'v';
        this->_symGrp.visible = L'\u2227';
        this->_symVar.internal = '+';
        this->_symGrp.internal = '*';
        this->_brackets = false;
        this->exp->key = 0;
    }
}

void CustomTextEdit::setNumVars(unsigned int numVars)
{
    this->_numVars = numVars;
}

MLF::expression* CustomTextEdit::getExpression()
{
    return exp;
}
