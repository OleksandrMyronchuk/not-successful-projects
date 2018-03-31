#ifndef KUINSMETHOD_H
#define KUINSMETHOD_H

#include "expression.h"
namespace MLF {

class kuinsMethod
{
private:
    expression *newExp;
    expression *currentExp;
public:
    kuinsMethod(expression *exp);
    ~kuinsMethod();
};

/**

**/

}
#endif // KUINSMETHOD_H
