#include "XMLFile.h"

string XMLFile::getXMLFileName()
{
    return XML_FILE_NAME;
}
bool XMLFile::XMLFileExists(string XMLFileName)
{
    CMarkup xml;
    return(xml.Load(XMLFileName+".xml"));

}
