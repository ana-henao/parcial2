#include "impacto.h"


Impacto::Impacto(int angle,int V0o,int x,int y,int t)
{
    this->angle=angle;
    this->V0o=V0o;
    this->x=x;
    this->y=y;
    this->t=t;

}

void Impacto::ImprimirResultados1()
{

    cout << "Impacto con un angulo de " << this->angle << " grados" << endl;
    cout << "Impacto con velocidad incial " << this->V0o << endl;
    cout << "Impacto con posicion x: " << this->x << endl;
    cout << "Impacto con posicion y: " << this->y << endl;
    cout << "Con tiempo: " << this->t << endl;
    cout << endl;

}

void Impacto::update(int angle, int V0o, int x, int y, int t)
{

    this->angle=angle;
    this->V0o=V0o;
    this->x=x;
    this->y=y;
    this->t=t;
}
