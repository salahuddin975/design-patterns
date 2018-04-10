#include <iostream>
#include <list>

class Graphic
{
public:
    virtual void print() = 0;
};


class Ellipse : public Graphic
{
public:
    void print(){
        std::cout << "Ellipse" << std::endl;
    }
};

class Circle : public Graphic
{
public:
    void print(){
        std::cout << "Circle" << std::endl;
    }
};

class CompositeGraphic : public Graphic
{
private:
    std::list<Graphic> child_graphic;

public:
    void print()
    {
        for(auto graphic : child_graphic){
            graphic.print();
        }
    }

    void add(Graphic graphic)
    {
        child_graphic.push_back(graphic);
    }

    void remove(Graphic graphic)
    {

    }
};



int main()
{


    return 0;
}