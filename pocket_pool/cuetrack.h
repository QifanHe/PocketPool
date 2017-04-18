#ifndef CUETRACK_H
#define CUETRACK_H
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <QPair>
#include <vector>
#include <QTimer>
#include <QObject>

using namespace cv;
using namespace std;
class Cuetrack:public QObject
{
    Q_OBJECT
public:
    Cuetrack();
    void startTracking();
    int detecting;
    vector<Point> spiral_marker_detect(Mat img, Scalar target, size_t n, int number, vector<Point> pre_vec);
    vector<Point> detect_marker(Mat img, Scalar target, size_t n, int &number);
    QPair<double, double> hitValue;
private:
    double vX;
    double vY;

    Scalar_<uint8_t> tar;
    Mat target;
    VideoCapture cap;
    Vec3b intensity;
    vector<Point> cur;
    vector<Point> pre;
    Mat cam_img;
    Mat cam;
    QTimer * timer;
    bool filter(Point *start, Point *end, int m, int n, int Type);
    vector<Point> predict_marker(vector<Point> pre, vector<Point> cur);
private slots:
    void timerHandler();
};

#endif // CUETRACK_H
