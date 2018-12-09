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
    virtual ~multimedia() = 0;
    virtual void jouer() const = 0;
    string getPath() const ;
    string getNameFile() const;
    void setPath(string _path) ;
    void setNameFile(string _nameFile);
    virtual void show(ostream& s) const = 0;


};

#endif // MULTIMEDIA_H
