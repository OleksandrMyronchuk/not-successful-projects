#include "kuinsmethod.h"

#include <QDebug>

namespace MLF {

kuinsMethod::kuinsMethod(expression *exp) :
    currentExp(exp),
    newExp(new expression())
{
}

kuinsMethod::~kuinsMethod()
{
    //delete newExp;
}

}
