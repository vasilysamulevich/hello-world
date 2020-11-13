#include  "Field.h"

Field::Field(int height, int width,Pair etrance, Pair quit){
    this->etrance=etrance;
    this->quit=quit;
    if(height <=0 || width <=0){
        std::cout<<"Неккорректные параметры\n";
        exit(1);
    }
    this->height=height;
    this->width=width;
     cells=new Cell* [height];
    for(int i=0;i<height;i++)
        cells[i]=new Cell [width];

}

Field::~Field(){
    for(int i=0;i<height;i++){
        delete  [] cells[i];
    }
    delete  [] cells;
}

Field::Field(const Field &other) :Field(other.height, other.width){ //конструктор копирования
    etrance=other.etrance;
    quit=other.quit;
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++)
            cells[i][j]=other.cells[i][j];
    }


}


Field::Field (Field&& other){ //конструктор перемещения
    height=other.height;
    width=other.width;
    cells=other.cells;
    etrance=other.etrance;
    quit=other.quit;
    other.height=0;
    other.width=0;
    other.cells=nullptr;
}




Field::Field (std::string* strings,int length1, int length2):Field(length1,length2) {

    for(int i=0;i<height;i++){
        for(int j=0;j<strings[i].length();j++){
            if(j >= width){
                std::cout<<"Ошибка!Поле введено неверно!\n";
                exit(1);
            }
            switch(strings[i][j]){
                case ' ':
                    cells[i][j].setContent(Cell::empty);
                break;

                case 'W':
                    cells[i][j].setContent(Cell::wall);
                break;
                
                case 'S':
                    if(etrance.x!=-1){
                        std::cout<<"Ошибка, вход уже определен";
                        exit(1);
                    }
                    cells[i][j].setContent(Cell::entrance);
                    etrance.x =i;
                    etrance.y=j;
                    
                break;

                case 'F':
                    if(quit.x!=-1){
                        std::cout<<"Ошибка, выход уже определен";
                        exit(1);
                    }
                    cells[i][j].setContent(Cell::quit);
                    quit.x=i;
                    quit.y=j;
                break;
                
                default:
                    std::cout<<"Ошибка, неизвестные символы.\n";
                exit(1);
            }

        }    
    }

}

void Field::setTeleport(Pair start,Pair finish){

    if(!start.checkBounds(height,width)||!finish.checkBounds(height,width)){
        std::cout<<"Ошибка, неправильные координаты для телепорта.\n";
        return;
    }
    if(!cells[start.x][start.y].checkContent(Cell::empty) ||!cells[finish.x][finish.y].checkContent(Cell::empty)){
        std::cout<<"Неподходящее место для телепорта\n";
        return;
    }

    Teleport* first=new Teleport(Teleport::entrance,start);
    Teleport* second=new Teleport(Teleport::quit,finish);
    cells[start.x][start.y].setElem(first);
    cells[finish.x][finish.y].setElem(second);
}


void Field::setPoints(Pair position, int val){
    if(!position.checkBounds(height,width)){
        std::cout<<"Ошибка, неправильные координаты для Очков опыта.\n";
        return;

    }

    if(!cells[position.x][position.y].checkContent(Cell::empty)){
        std::cout<<"Неподходящее место для телепорта\n";
        return;
    }
    Points* temp=new Points(val);
    cells[position.x][position.y].setElem(temp);
}


void Field::setReverse(Pair position){
if(!position.checkBounds(height,width)){
        std::cout<<"Ошибка, неправильные координаты для Инверсии.\n";
        return;

    }

    if(!cells[position.x][position.y].checkContent(Cell::empty)){
        std::cout<<"Неподходящее место для инверсии\n";
        return;
    }
    Reverse* temp=new Reverse();
    cells[position.x][position.y].setElem(temp);
}




void Field::print(){
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++)
            cells[i][j].print();
        std::cout<<'\n';
    }
}


