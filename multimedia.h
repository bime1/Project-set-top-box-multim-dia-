#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H
#include <string>
#include <iostream>

using namespace std;

class multimedia
{
private:
    string path;
    string nameFile;
public:
    multimedia();
    multimedia(string _path,string _nameFile);
    virtual ~multimedia();
    virtual void jouer(void) const = 0;
    string getPath() const ;
    string getNameFile() const;
    void setPath(string _path) ;
    void setNameFile(string _nameFile);
    void show(ostream& s) const ;


};

#endif // MULTIMEDIA_H
