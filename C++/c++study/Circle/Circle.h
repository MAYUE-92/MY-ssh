class Circle
{
    private:
    	double r;
    public:
    	void Input();//输入半径
    	double CRadius();//读取半径
    	double CArea();//求面积
    	double CLen();//求周长
    	
    	Circle();//无参构造函数
    	Circle(double x);//有参构造函数
    	Circle(Circle&x);//拷贝构造函数
};