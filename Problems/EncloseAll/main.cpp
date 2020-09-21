#include <iostream>
#include <cmath>
#include <set>
#define x first
#define y second
using namespace std;
typedef pair <double,double> pii;
int N;
pii points[55];
double error = 0.0000001;

double distanceSquare(double ax, double ay, double bx, double by){
    double distx = ax-bx;
    double disty = ay-by;
    return distx*distx+disty*disty;
}

bool works(double rad){
    set <pii> intersect;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            pii mid;
            mid.x = (points[i].x + points[j].x) / 2;
            mid.y = (points[i].y + points[j].y) / 2;
            double distx = mid.x - points[i].x;
            double disty = mid.y - points[i].y;
            double leg = rad * rad - distx * distx - disty * disty;
            if (0 - leg > error * error) {
                intersect.clear();
                return false;
            }
            leg = sqrt(abs(leg));
            double mag = sqrt(distx*distx+disty*disty);
            pii normal = {-disty / mag, distx / mag};
            pii vect = {normal.x*leg, normal.y*leg};
            intersect.insert({mid.x+vect.x, mid.y+vect.y});
            intersect.insert({mid.x-vect.x, mid.y-vect.y});
        }
    }

    bool ok = false;
    for (auto it: intersect){
        bool indeed = true;
        for (int i=0; i<N; i++){
            if (distanceSquare(it.x, it.y, points[i].x, points[i].y) - rad*rad > error) {
                indeed = false;
            }
        }
        if (indeed) ok = true;
    }
    intersect.clear();
    return ok;
}

int main() {
    cin >> N;
    for (int i=0; i<N; i++){
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    double l = 0, r = 1500, m = 0;
    while (l+error < r) {
        m = (l+r)/2;
        if (works(m)) r = m;
        else l = m;
    }
    printf("%.7lf\n", m);
    return 0;
}
