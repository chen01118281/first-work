#include "reproject.hpp"
#include <cmath>

wp wtop(wp pw, double R[3][3], wp t) {
    wp pc;
    pc.x = R[0][0] * pw.x + R[0][1] * pw.y + R[0][2] * pw.z + t.x;
    pc.y = R[1][0] * pw.x + R[1][1] * pw.y + R[1][2] * pw.z + t.y;
    pc.z = R[2][0] * pw.x + R[2][1] * pw.y + R[2][2] * pw.z + t.z;
    return pc;
}

pp ctop(camera cam, wp pc) {
    pp f;
    f.u = cam.fx * pc.x / pc.z + cam.cx;
    f.v = cam.fy * pc.y / pc.z + cam.cy;
    return f;
}

double distance(pp f, pp t) {
    double end = sqrt((f.u - t.u) * (f.u - t.u) + (f.v - t.v) * (f.v - t.v));
    return end;
}
