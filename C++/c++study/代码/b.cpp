class Circle
{
    public:
        double r;
        double Carea();
        double Clen();
};
double Circle::Carea()
{ return(3.14*r*r); }
double Circle::Clen()
{ return (3.14*2*r); }

class Rectangle
{
    public:
        double a,b;
        double Rarea();
        double Rlen();
};
double Rectangle::Rarea()
{ return(a*b); }
double Rectangle::Rlen()
{ return ((a+b)*2); }