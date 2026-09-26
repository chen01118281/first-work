#ifndef REPROJECT_HPP
#define REPROJECT_HPP

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

wp wtop(wp pw, double R[3][3], wp t);

pp ctop(camera cam, wp pc);

double distance(pp f, pp t);

#endif
