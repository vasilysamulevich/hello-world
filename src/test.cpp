#include <iostream>
#include "Cell.h"
int main(){
Cell test;
Player player1;
Teleport* a=new Teleport(Teleport::entrance,Pair(200,450));
Player& player=player1;
player.print();
test.setElem(a);
Cell test1;
test1=test;
((Teleport*)test1.getElem())->print();
*test1.getElem()+player;
player.print();

}
