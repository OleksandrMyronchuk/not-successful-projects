#include "toformat.h"

namespace MLF {
toFormat::toFormat() : currentError("None"), exp(new)
{

}
toFormat::~toFormat()
{
    delete exp;
}

bool toFormat::setPDNF(QString str, , char key) try
{
    int strLength = str.length();
    str.replace(" ", "");//remove space
    expression.key = key;
    for(int i(0);i < strLength;)
    {
        /*symbol*/
        /* "false" or "true" */
        if(str.at(i)=='x' && str.at(i+++1)==L'\u0305')
        {
            expression.arrValue.push_back(false);
        }
        else if(str.at(i++)=='x')
        {
            expression.arrValue.push_back(true);
        }
        else
        {
            throw uncorrectInput();
        }
        /*get number*/
        if(48 <= str.at(i) && str.at(i++) >= 57)
        {
            expression += str.at(i);
            if(48 <= str.at(i) && str.at(i++) >= 57)
            {
                expression += str.at(i);
            }
            else
            {
                expression += 'e';
            }
        }
        else
        {
            throw uncorrectInput();
        }
        /*mathematical action*/
        if(str.at(i++)=='v')
        {
            expression += (char)0;
        }
        else if(str.at(i++)==L'\u2227')
        {
            expression += (char)1;
        }
        else
        {
            throw uncorrectInput();
        }
    }
    return 0;
}
catch(std::exception &e)
{
    currentError = e.what();
    return 1;
}

const char* toFormat::getError() const
{
    return currentError;
}
}
