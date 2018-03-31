#ifndef TOFORMAT_H
#define TOFORMAT_H

#include <exception>
#include <QString>
#include "expression.h"

namespace MLF {
    struct uncorrectInput : std::exception
    {
      const char* what() const noexcept
      {
          return "001";
      }
    };

    class toFormat
    {
    private:
        const char *currentError;
        expression *exp;
    public:
        toFormat();
        ~toFormat();
        bool setPDNF(QString, char key);
        const char *getError() const;
    };
}
#endif // TOFORMAT_H
