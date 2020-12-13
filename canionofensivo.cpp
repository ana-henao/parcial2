#include "canionofensivo.h"

canionOfensivo::canionOfensivo()
{

}

canionOfensivo::canionOfensivo(float d, float Ho, float ao)
{
    this->d=d;
    this->Ho=Ho;
    this->ao=ao;

}

Impacto canionOfensivo::DisparoOfensivo(canionDefensivo disparoD, int Voo, bool mostrar)
{

    int flag=0;// contador de disparos
    float x,y;
    float Vxo,Vy0;
    int V0o = 0;//velocidad inicial de disparo con la que arranca el cañon
    int t = 0;
    int angle = 0;
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos(angle*pi/180);
            Vy0 = V0o*sin(angle*pi/180);
            x = 0.0;
            y = 0.0;
            for(t = 0; ; t++){
                x = Vxo*t;
                y = this->getYo() + Vy0*t -(0.5*G*t*t);
                if(sqrt(pow((disparoD.getXd() - x),2)+pow((disparoD.getYd() - y),2)) < this->getd0()){
                    if(y<0) y=0;
                    this->impactos[flag]=new Impacto(angle,V0o,x,y,t);
                    //cout << angle<<endl;
                    //cout << "Impacto angulo: "<<impactos[flag].angle<< endl;
                    if(mostrar){
                         //ImprimirResultados1(angle, V0o, x, y, t);
                         Impacto impacto2=Impacto(angle, V0o, x, y, t);
                         impacto2.ImprimirResultados1();
                    }
                    flag += 1;
                    V0o+=50;
                    break;
                }
                if(y < 0){// si pasa la posicion de y, no impacta
                    break;
                }
            }
            if(flag==3) break;

        }
        if(flag==3) break;
    }
    if(flag!=3){
        cout << "No impacto en los disparos esperados"<< endl;

    }
    return *impactos[0];
}

void canionOfensivo::DisparoOfensivo2(canionDefensivo disparoD, int Voo, int angleoo, int Vooo)
{   int flag=0;
    float x,y, x2, y2;
    float Vxo,Vy0, Vxoo, Vyoo;
    int V0o = 0;//velocidad inicial de disparo con la que arranca el cañon
    int t = 0;
    int angle = 0;//no se coloca angulo especifico por que no se sabe a que angulo dispara para que le diera

    Vxoo=Vooo*cos((90-(angleoo-90))*pi/180);
    Vyoo = Vooo*sin((90-(angleoo-90))*pi/180);
    for(V0o = Voo; ; V0o += 5){
        for(angle = 0; angle < 90; angle++){
            Vxo = V0o*cos((angle)*pi/180);
            Vy0 = V0o*sin((angle)*pi/180);
            x = 0.0;
            y = 0.0;
            x2 = 0.0;
            y2 = 0.0;
            for(t = 0; ; t++){
                x2 = Vxoo*(t+1);
                y2 = this->getYo() + Vyoo*(t+1) -(0.5*G*t*t);
                x = disparoD.getXd()+Vxo*t;
                y = disparoD.getYd() + Vy0*t -(0.5*G*t*t);
                //cout << y<< endl;
                if(sqrt(pow((x2 - x),2)+pow((y2 - y),2)) < this->getd0()){
                    if(y<0) y=0;
                    Impacto impacto=Impacto(angleoo, Vooo, x2, y2, t+1);
                    cout << "------------------ Normal: ---------------------------------"<< endl;
                     impacto.ImprimirResultados1();
                     cout<< "------------------ Retraso: 1 s ----------------------------"<< endl;
                     //ImprimirResultados1(angle, V0o, x, y, t);
                     Impacto impacto2=Impacto(angle, V0o, x, y, t);
                     impacto2.ImprimirResultados1();
                     cout <<"-------------------------------------------------------------"<< endl;

                    flag += 1;
                    V0o+=50;
                    break;
                }
                if(y < 0){
                    break;
                }
            }
            if(flag==3) break;

        }
        if(flag==3) break;
    }
    if(flag!=3){
        cout << "No impacto en los disparos esperados"<< endl;

    }

}




