#include "Plotter.h"
#include "strlib.h"
using namespace std;

void runPlotterScript(istream& input) {
    PenStyle mypenstyle ={1,"black"};
    int penstate=0;   //默认笔抬起
    double startx=0;
    double starty=0;  //笔初始坐标
    double finalx=0;
    double finaly=0;
    for (string line; getline(input, line); ) {
        /* ... 对 line 进行处理 ... */
        Vector<string> Penstate = stringSplit(line, " ");
            if(Penstate.isEmpty())  continue;
            string command = toLowerCase(Penstate[0]);
             if(command == "pencolor"){
                 mypenstyle.color=Penstate[1];
              }
             else if( command == "penwidth"){
               mypenstyle.width= stringToReal(Penstate[1]);
              }
              else if (command == "penup"){ penstate=0;}
              else if (command == "pendown"){ penstate=1;}
                if(command == "moveabs"){
                 finalx=stringToReal(Penstate[1]);
                 finaly=stringToReal(Penstate[2]);
                 if(penstate)    drawLine(startx,starty,finalx,finaly,mypenstyle);
                 startx=finalx; starty=finaly;
                }
                else if(command == "moverel"){
                    finalx=stringToReal(Penstate[1])+startx;
                    finaly=stringToReal(Penstate[2])+starty;
                    if(penstate)    drawLine(startx,starty,finalx,finaly,mypenstyle);
                    startx=finalx; starty=finaly;
                }


    }

}

