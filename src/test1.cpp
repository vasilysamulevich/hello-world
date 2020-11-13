#include <iostream>
#include "Field.h"


int main(){
std::string area []=
{"  W   W   ",
 "          ",
 "  S   W   ",
 "          ",
 "  W   W   ",
 "          ",
 "  W   F   ",
 "      W   ",
 "  W       ",
 "          "
};

Field test(area,10,10);
test.setTeleport(Pair(0,3),Pair(5,5));
Field test1=test;
test.print();
std::cout<<"\n\n\n\n";
test1.print();
}
