
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
vector<int> lost_x;
vector <int> lost_y;
vector<string> lost_orientacion;
class robot {
    int x;
    int y;
    string status;
    bool isLost;
    int tabx;
    int taby;
public:
    robot(int a, int b, int x, int y, string ori) : tabx{a}, taby{b}, isLost{false}, x{x}, y{y}, status{ori} {
    }
    void move() {
        if (verificar() == 0) {
            if (!isLost) {
                if (status == "N") {
                    y++;
                } else if (status == "S") {
                    y--;
                } else if (status == "E") {
                    x++;
                } else if (status == "W") {
                    x--;
                }
            }
            if (x < 0 || x > tabx || y > taby || y < 0) {
                if (status == "N") {
                    y--;
                } else if (status == "S") {
                    y++;
                } else if (status == "E") {
                    x--;
                } else if (status == "W") {
                    x++;
                }
                isLost = true;
                lost_x.push_back(x);
                lost_y.push_back(y);
                lost_orientacion.push_back(status);
            }
        }
        else if(verificar()==2){
            if (status == "N") {
                y++;
            } else if (status == "S") {
                y--;
            } else if (status == "E") {
                x++;
            } else if (status == "W") {
                x--;
            }
            if (x < 0 || x > tabx || y > taby || y < 0) {
                if (status == "N") {
                    y--;
                } else if (status == "S") {
                    y++;
                } else if (status == "E") {
                    x--;
                } else if (status == "W") {
                    x++;
                }
            }
        }
    }

    void changeStatus(char a) {
        if (!isLost) {
            if (a == 'L') {
                if (status == "N")
                    status = "W";
                else if (status == "S")
                    status = "E";
                else if (status == "E")
                    status = "N";
                else if (status == "W")
                    status = "S";
            } else if (a == 'R') {
                if (status == "N")
                    status = "E";
                else if (status == "S")
                    status = "W";
                else if (status == "E")
                    status = "S";
                else if (status == "W")
                    status = "N";
            }
        }
    }

    void print() {
        if (isLost) {
            cout << x << " " << y << " " << status << " " << "LOST" << endl;
        } else {
            cout << x << " " << y << " " << status << endl;
        }
    }

    int verificar() {
        for (int i = 0; i < lost_x.size(); i++) {
            if (x == lost_x[i] && y == lost_y[i] && status == lost_orientacion[i]) {
                return 1;
            }

            else if (x == lost_x[i] && y == lost_y[i]) {
                return 2;
            }
        }
        return 0;
    }

};
int main(){
    int tamx, tamy, posx, posy;
    string orientacion;
    string direcciones;
    cin>> tamx >> tamy;
    while(cin >> posx >> posy >> orientacion) {
        robot a(tamx, tamy ,posx ,posy, orientacion);
        cin >> direcciones;
        for (int i = 0; i < direcciones.size(); i++) {
            if (direcciones[i] == 'L' || direcciones[i] == 'R')
                a.changeStatus(direcciones[i]);
            else if (direcciones[i] == 'F') {
                a.move();
            }
        }
        a.print();
    }
}



