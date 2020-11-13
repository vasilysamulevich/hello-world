#include "Pair.h"
#include "Cell.h"
#include "Player.h"
class Field{
    int height;
    int width;
    Cell** cells;
    Pair etrance;
    Pair quit;
public:
    Field(int height=0, int width=0,Pair etrance=Pair(), Pair quit=Pair());
    Field(std::string* strings,int length1,int length2);
    ~Field();
    Field(const Field &other);//конструктор копирования
  //  Field& operator=(const Field &other); //оператор присваинвания копированием
    Field (Field && other);//конструктор перемещения
  //  Field& operator = (Field && other); //оператор присваивания перемещением
    void setTeleport(Pair start, Pair finish);
    void setPoints(Pair position , int val=50);
    void setReverse (Pair position);
    void print();
};

