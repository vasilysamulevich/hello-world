#include <typeinfo>
#include "Element.h"
#include "Teleport.h"
#include "Points.h"
#include "Reverse.h"

class Cell{
public:
    enum  type {wall,empty,entrance,quit};
    Cell();
    ~Cell();
    bool checkContent(type content);
    Element* getElem();
    void setElem(Element* elem);
    void setContent(type content);
    Cell& operator=(const Cell& other); //оператор присваивания копированием
    void print();
private:
    int getType () const;
    type content;
    Element* elem;
    
};

