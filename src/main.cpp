#include <iostream>
#include "reproject.hpp"
using namespace std;

int main() {

    camera cam;
    cout << "请依次输入相机内参 fx,fy,cx,cy:";
    cin >> cam.fx >> cam.fy >> cam.cx >> cam.cy;

    pp ture;
    cout << "请依次输入已知坐标u,v:";
    cin >> ture.u >> ture.v;

    wp t;
    cout << "请依次输入平移向量tx,ty,tz:";
    cin >> t.x >> t.y >> t.z;

    double R[3][3];
    cout << "请依次输入旋转矩阵R的9个数（按行输入）:";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> R[i][j];
        }
    }

    wp world;
    cout << "请输入世界中的坐标x,y,z：";
    cin >> world.x >> world.y >> world.z;

    wp pc = wtop(world, R, t);

    if (pc.z <= 0) {
        cout << "此点不能投影到相机上，z为" << pc.z << endl;
        return 0;
    }

    pp flash = ctop(cam, pc);
    cout << "重投影像素坐标 u=" << flash.u << " v=" << flash.v << endl;

    double err = distance(flash, ture);

    cout << "像素距离为：" << err << endl;

    return 0;
}
