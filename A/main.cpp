#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using std::endl;

double distance(const double x1, const double y1, const double x2, const double y2) {
    return pow(pow((x2 - x1), 2) + pow((y2 - y1), 2), 0.5);
}

void findPointsOfContact(const double& xc, const double& yc, const double& R, const double& xn, const double& yn,
    double& xa, double& ya, double& xb, double& yb)
{
    double dist = distance(xc, yc, xn, yn);

    double B = pow(pow(dist, 2)- pow(R, 2), 0.5);
    double h = (R / dist) * B;
    double d = pow(pow(R, 2) - pow(h, 2), 0.5);

    double x = xc + ((xn - xc) /dist) * d;
    double y = yc + ((yn - yc) / dist) * d;

    xa = x + ((yn - yc) / dist) * h;
    ya = y - ((xn - xc) / dist) * h;

    xb = x - ((yn - yc) / dist) * h;
    yb = y + ((xn - xc) / dist) * h;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    double xc, yc, R, xn, yn;
    double xa, ya, xb, yb;
    xa = ya = xb = yb = 0;
    input >> xc >> yc >> R >> xn >> yn;

    double CN = distance(xc, yc, xn, yn);

   
    if (CN == R) {
        output << "1" << endl;
        output.precision(5);
        output << std::fixed << xn << " " << yn << endl;
    }
    else if (CN < R) {
        output <<"0 ";
    }
    else {
        findPointsOfContact(xc, yc, R, xn, yn, xa, ya, xb, yb);
        output << "2" << endl;
        output.precision(5);
        output << std::fixed << xa << " " << ya << " " << xb << " " << yb << endl;
    }
    return 0;
}