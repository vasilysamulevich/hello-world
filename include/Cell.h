#ifndef CELL_H
#define CELL_H
class Cell
{
public:
    static int size;
    enum cell_type{pass, unpass};
    Cell();
    Cell(cell_type);
    ~Cell();
    cell_type get_content();
    void set_content(cell_type);
private:
    cell_type content;
};




#endif
