#include "multimedia.h"
#include <string>
#include <iostream>
using namespace std;
multimedia::multimedia()
{
    path = "none";
    nameFile = "none";
}

multimedia::multimedia(string _path, string _nameFile)
{
    path = _path;
    nameFile = _nameFile;
}


multimedia::~multimedia(){}

void multimedia::setPath(string _path){path = _path;}
void multimedia::setNameFile(string _nameFile){nameFile = _nameFile;}

string multimedia::getNameFile() const {return nameFile;}
string multimedia::getPath() const {return path;}
//void multimedia::show(ostream& s) const {s << "The path is : " <<
//                                              getPath() <<
//                                           ", And the name of the file is : "
//                                             << getNameFile() << endl;}


