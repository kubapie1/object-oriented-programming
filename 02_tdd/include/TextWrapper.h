#ifndef INC_02_TDD_TEXTWRAPPER_H
#define INC_02_TDD_TEXTWRAPPER_H

#include <string>
#include <sstream>
#include <vector>

class TextWrapper
{
private:
    int columnsNumber;
    std::string ourText;
public:
    TextWrapper();
    TextWrapper( int columnsNumber );
    int getColumns() const;
    void textAssign( std::string receivedText );
    std::string getOurText() const;
    void stringSubtraction();
};

#endif //INC_02_TDD_TEXTWRAPPER_H
