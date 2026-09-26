#include<iostream>
#include<cmath>
using namespace std;

struct wp {
    double x;
    double y;
    double z;
};
struct pp {
    double u;
    double v;
};
struct camera {
    double fx;
    double fy;
    double cx;
    double cy;
};
wp wtop (wp pw,double R[3][3],wp t ){
    wp pc;
    pc.x=R[0][0]*pw.x+R[0][1]*pw.y+R[0][2]*pw.z+t.x;
    pc.y=R[1][0]*pw.x+R[1][1]*pw.y+R[1][2]*pw.z+t.y;
    pc.z=R[2][0]*pw.x+R[2][1]*pw.y+R[2][2]*pw.z+t.z;
    return pc;
}
pp ctop (camera cam,wp pc){
    pp f;
    f.u=cam.fx*pc.x/pc.z+cam.cx;
    f.v=cam.fy*pc.y/pc.z+cam.cy;
    return f;
};
double distance(pp f,pp t){
    double end=sqrt((f.u-t.u)*(f.u-t.u)+(f.v-t.v)*(f.v-t.v));
    return end;
};
int main(){

    camera cam;
    cout<<"请依次输入相机内参 fx,fy,cx,cy:";
    cin>>cam.fx>>cam.fy>>cam.cx>>cam.cy;

    pp ture;
    cout<<"请依次输入已知坐标u，v:";
    cin>>ture.u>>ture.v;

    wp t;
    cout<<"请依次输入平移向量tx,ty,tz:";
    cin>>t.x>>t.y>>t.z;

    double R[3][3];
    cout<<"请依次输入旋转矩阵R的9个数（按行输入）:";
    for(int i =0; i<3;i++){
        for(int j=0 ;j<3;j++){
            cin>>R[i][j];
        };
    };

    wp world;
    cout<<"请输入世界中的坐标x,y,z：";
    cin>>world.x>>world.y>>world.z;
    
    wp pc =wtop( world,R,t);

    if(pc.z<0){
        cout<<"此点不能投影到相机上，z为"<<pc.z<<endl;
        return 0;
    }
    
    pp flash =ctop( cam, pc);

    double err =distance(flash,ture);

    cout<<"像素距离为："<<err<<endl;

    return 0;
};