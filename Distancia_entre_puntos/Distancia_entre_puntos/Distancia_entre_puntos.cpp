#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

struct Point {
    double x, y;
};

bool compareX(const Point& a, const Point& b) {
    return a.x < b.x;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double distance(const Point& a, const Point& b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double bruteForce(const vector<Point>& points, int start, int end) {
    double minDist = numeric_limits<double>::max();
    for (int i = start; i <= end; i++) {
        for (int j = i + 1; j <= end; j++) {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

double closestUtil(const vector<Point>& points, int start, int end) {
    if (end - start <= 2) {
        return bruteForce(points, start, end);
    }

    int mid = (start + end) / 2;
    double midX = points[mid].x;

    double leftDist = closestUtil(points, start, mid);
    double rightDist = closestUtil(points, mid + 1, end);
    double minDist = min(leftDist, rightDist);

    vector<Point> strip;
    for (int i = start; i <= end; i++) {
        if (abs(points[i].x - midX) < minDist) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    int stripSize = strip.size();
    for (int i = 0; i < stripSize; i++) {
        for (int j = i + 1; j < stripSize && (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

double closestPoints(const vector<Point>& points) {
    vector<Point> sortedPoints = points;
    sort(sortedPoints.begin(), sortedPoints.end(), compareX);
    return closestUtil(sortedPoints, 0, sortedPoints.size() - 1);
}

int main() {
    vector<Point> points = { {2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4} };
    double minDist = closestPoints(points);
    cout << "La distancia mínima entre dos puntos es: " << minDist << endl;
    return 0;
}