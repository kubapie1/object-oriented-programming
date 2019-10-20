#include "TextWrapper.h"

TextWrapper::TextWrapper() { this->columnsNumber = 10;}
TextWrapper::TextWrapper( int columnsNumber ) { this->columnsNumber = columnsNumber; }
int TextWrapper::getColumns() const { return columnsNumber; }
void TextWrapper::textAssign( std::string receivedText ) { this->ourText = receivedText; }
std::string TextWrapper::getOurText() const { return ourText; }

void TextWrapper::stringSubtraction()
{
    std::string modifiedString = getOurText();

    std::istringstream iss(modifiedString);
    std::vector<std::string> splitedText;

    for (std::string word; iss >> word;)
        splitedText.push_back(word);

    std::string ourFinalText;

    int spaceLeft = getColumns();

    int moreThanOne = 0;
    if( getColumns() > 2 )
        moreThanOne = 1;

    for (std::string eachElement : splitedText)
    {
        if( spaceLeft > 0 && spaceLeft < getColumns() )
        {
            ourFinalText += " ";
            spaceLeft--;
        }
        if( spaceLeft == 0 )
        {
            ourFinalText += "\n";
            spaceLeft = getColumns();
        }

        if( eachElement.length() > spaceLeft )
        {
            int elementLength = eachElement.length();

            int letterSavedCounter  = 0;
            while (elementLength > 0) {

                while(elementLength > spaceLeft)
                {
                    if( spaceLeft == 0)
                    {
                        ourFinalText += "\n";
                        spaceLeft = getColumns();
                    }

                    ourFinalText += eachElement.substr(letterSavedCounter, spaceLeft + ( moreThanOne * -1 ));

                    letterSavedCounter += (spaceLeft + ( moreThanOne * - 1) );
                    elementLength -= (spaceLeft + ( moreThanOne * - 1) );
                    spaceLeft = 0;
                    if( elementLength > 1)
                        ourFinalText += '-';
                }
                /*ourFinalText += eachElement.substr( letterSavedCounter, elementLength );
                spaceLeft -= elementLength;
                elementLength = 0;*/
            }
        }
        else if( eachElement.length() <= spaceLeft )
        {
            ourFinalText += eachElement;
            spaceLeft -= eachElement.length();
        }
    }

    ourText = ourFinalText;
}