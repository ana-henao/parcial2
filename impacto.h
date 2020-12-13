#ifndef IMPACTO_H
#define IMPACTO_H


class Impacto
{
private:
    int angle=0;
    int V0o=0;
    int x=0;
    int y=0;
    int t=0;

public:
    Impacto(int angle,int V0o,int x,int y,int t);
    int getangle(){return angle;};
    int getV0o(){return V0o;};
    int getx(){return x;};
    int gety(){return y;};
    int gett(){return t;};

};

#endif // IMPACTO_H
