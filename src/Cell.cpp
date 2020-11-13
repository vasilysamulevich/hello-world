#include "Cell.h"


Cell::Cell():content(empty),elem(nullptr) {}

Cell::~Cell(){
    if(elem!=nullptr){
        delete elem;
    }
}

bool Cell::checkContent(type content){
    return this->content==content;
}

void Cell::setContent(type content){
    this->content=content;
}

Element* Cell::getElem(){
    return elem;
}

void Cell::setElem(Element* elem){
    this->elem=elem;
}

int Cell::getType() const{
    if(elem == nullptr)
        return 0;

    if(typeid(*elem)==typeid(Teleport))
        return 1;

    if(typeid(*elem)==typeid(Points))
        return 2;

    if(typeid(*elem)==typeid(Reverse))
        return 3;
}

Cell& Cell::operator=(const Cell& other){
    content=other.content;
    if(elem!=nullptr)
        delete elem;

    int val=other.getType();
    if(val == 0){
        elem=nullptr;
        return *this;
    }
    if(val == 1){
        elem=(Element*) new Teleport;
        *((Teleport*)elem)=*((Teleport*)other.elem);
    }
    
    if(val == 2){
        elem=(Element*) new Points;
        *((Points*)elem)=*((Points*)other.elem);
    }

    if(val == 3){
        elem=(Element*) new Reverse;
        *((Reverse*)elem)=*((Reverse*)other.elem);

    }
    
    return *this;
}

void Cell::print(){
    if(content==wall)
        std::cout<<"W";
    if(content==entrance)
        std::cout<<"S";
    if(content==quit)
        std::cout<<"F";
    if(content == empty)
        std::cout<<' ';
    if(elem!=nullptr)
        (*elem).print();
}    





