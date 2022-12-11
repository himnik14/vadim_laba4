#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
#define pi 3.14
class Circle
{
protected:
    double _r;
public:
    Circle();
    Circle(double _r);
    void set_r(double _r);
    void show();
    double get_r();
    virtual double get_square();
    double get_lengthCircle();
};

class CircleCylinder : public Circle
{
    double _h;
public:
    CircleCylinder();
    CircleCylinder(double _r, double _h);
    void set_h(double _h);
    double get_volume();
    double get_square();
    void show();

};

Circle::Circle()
{

}

CircleCylinder::CircleCylinder()
{

}

CircleCylinder::CircleCylinder(double _r, double _h)
{
    if (_r <= 0 || _h <= 0)
        throw exception("Высота или радуис не могут быть меньше или равными нулю!\n");
    this->_h = _h;
    this->_r = _r;
}

void CircleCylinder::show() 
{
    cout << "Площадь цилиндра: " << get_square() << endl;
    cout << "Объем целиндра: " << get_volume() << endl;
}

Circle::Circle(double _r)
{
    if (_r <= 0)
        throw exception("Радиус окружности не может быть меньше или равным нулю!\n");
    this->_r = _r;
}

void Circle::show()
{
    cout << "Площадь окружности: " << get_square() << endl;
    cout << "Длина окружности: " << get_lengthCircle() << endl;
}

void CircleCylinder::set_h(double _h)
{
    if (_h <= 0)
        throw exception("Высота целиндра не может быть меньше или равной нулю!\n");
    this->_h = _h;
}

double CircleCylinder::get_square()
{
    return 2 * pi * _r * _h + 2*pi * pow(_r, 2);
}

double CircleCylinder::get_volume()
{
    return pi * pow(_r, 2) * _h;
}

void Circle::set_r(double _r)
{
    if (_r <= 0)
        throw exception("Радиус окружности не может быть меньше нуля!\n");
    this->_r = _r;
}

double Circle::get_r()
{
    return _r;
}

double Circle::get_square()
{
    return pi * pow(_r, 2);
}

double Circle::get_lengthCircle()
{
    return pi * 2 * _r;
}


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    CircleCylinder cr;
    Circle c;
    try
    {
        cr.set_h(5);
        cr.set_r(3);
        c.set_r(5);
    }
    catch (const std::exception& exc)
    {
        cout << exc.what();
        return 0;
    }
    c.show();
    cr.show();
    int N, M, max = INT_MIN, iop = 0;
    double _r, _h, middle = 0;
    cout << "Сколько окружностей вы хотите создать?\n";
    cin >> N;
    cout << "Сколько цилиндров вы хотите создать?\n";
    cin >> M;
    vector<Circle> circ;
    vector<CircleCylinder> cyl;
    for (int i = 0; i < N; i++)
    {
        try
        {
            cout << "Создание " << i + 1 << " окуржности.....\n";
            cout << "Введите радиус окружности: \n";
            cin >> _r;
            circ.push_back(Circle(_r));
        }
        catch (const std::exception& ex)
        {
            cout << ex.what();
        }
    }
    for (int i = 0; i < circ.size(); i++)
    {
        cout << i + 1 << ") окружность: \n";
        circ[i].show();
    }
    for (int i = 0; i < circ.size(); i++)
    {
        if (circ[i].get_square() > max)
        {
            max = circ[i].get_square();
            iop = i;
        }
    }
    cout << "\nОкружность имеющая максимальную площадь: \n";
    circ[iop].show();
    cout << endl;
    for (int i = 0; i < M; i++)
    {
        try
        {
            cout << "Создание " << i + 1 << " цилиндра.....\n";
            cout << "Введите радиус цилиндра: \n";
            cin >> _r;
            cout << "Введите высоту цилидра: \n";
            cin >> _h;
            cyl.push_back(CircleCylinder(_r, _h));
        }
        catch (const std::exception& ex)
        {
            cout << ex.what();
        }
    }
    for (int i = 0; i < cyl.size(); i++)
    {
        cout << i + 1 << ") цилиндр: \n";
        cyl[i].show();
    }
    for (int i = 0; i < cyl.size(); i++)
    {
        middle += cyl[i].get_volume();
    }
    cout << "\nСредний объём цилиндров равен: " << middle / cyl.size() << endl;
}

