#include "cuetrack.h"
#include "game.h"
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <QBrush>
#include <QDebug>
#include <QThread>
#define TOP 1
#define LEFT 2
#define BOTTOM 3
#define RIGHT 4
using namespace cv;
using namespace std;
extern Game * game;

Cuetrack::Cuetrack()
{
    timer = new QTimer(this);
    detecting = 0;
    vX = 0;
    vY = 0;
    connect(timer, SIGNAL(timeout()), this, SLOT(timerHandler()));

}



void Cuetrack::timerHandler()
{
    timer->stop();
    //qDebug()<<"timer handler in";
        cap >> cam;
        if (cam.empty()){
            //timer->start(33);
            qDebug()<<"cam is cmpty";
            return;
        }
        cam_img = cam;
        GaussianBlur(cam, cam_img, Size(5, 5), 0, 0);
        cur = spiral_marker_detect(cam_img, tar, size_t(20), 1, pre);
        if (cur.size() != 0){
            game->cursor->setPos(cur[0].x, cur[0].y);
            if (sqrt( pow(cur[0].x - game->balls[0]->x(), 2) + pow(cur[0].y - game->balls[0]->y(), 2) ) < 20){
                hitValue = qMakePair(5, 1);
                cap.release();
                detecting = 2;
                timer->stop();
                destroyAllWindows();
                return;
            }
        }
        pre = cur;
        //rectangle(cam_img, cur[0], Point(cur[0].x + 5, cur[0].y + 5), Scalar(0, 0, 0), 2);
        //imshow("current", cam_img);
        timer->start(33);
    }



void Cuetrack::startTracking()
{
    target = imread("target.jpg");
    if(!cap.open(0)){
        qDebug()<<"Camera cannot be opened";
        return;
    }
    intensity = target.at<Vec3b>(10, 10);
    tar.val[0] = intensity.val[0];
    tar.val[1] = intensity.val[1];
    tar.val[2] = intensity.val[2];
    timer->start(33);
}

vector<Point> Cuetrack::spiral_marker_detect(Mat img, Scalar target, size_t n, int number, vector<Point> pre_vec) {
    vector<Point> res;
	if (pre_vec.size() == 0) {
		return detect_marker(img, target, n, number);
	}
	Point pre = pre_vec[0];
	if ((pre.x > img.cols - 10) || (pre.x < 10) || (pre.y > img.rows - 10) || (pre.y < 10) )
		return detect_marker(img, target, n, number);
	Point top_start(pre.x, pre.y - 1);
	Point top_end(top_start.x + 1, top_start.y);
	Point right_start(top_end.x, top_end.y + 1);
	Point right_end(right_start.x, right_start.y + 1);
	Point bottom_start(right_end.x - 1, right_end.y);
	Point bottom_end(bottom_start.x - 1, bottom_start.y);
	Point left_start(bottom_end.x, bottom_end.y - 1);
	Point left_end(left_start.x, left_start.y - 1);
	bool flag = true;
	while (flag) {
		flag = false;
		if (filter(&top_start, &top_end, img.rows, img.cols, TOP)) {
			Mat dist(img, Range(top_start.y, top_end.y + 1), Range(top_start.x, top_end.x + 1));
			res = detect_marker(dist, target, n, number);
			if (number == 0) {
				res[0].x += top_start.x;
				res[0].y = top_start.y;
				return res;
			}
			flag = true;
			top_start.x--;
			top_start.y--;
			top_end.x++;
			top_end.y--;
		}
		if (filter(&right_start, &right_end, img.rows, img.cols, RIGHT)) {
			Mat dist(img, Range(right_start.y, right_end.y + 1), Range(right_start.x, right_end.x + 1));
			res = detect_marker(dist, target, n, number);
			if (number == 0) {
				res[0].y += right_start.y;
				res[0].x = right_start.x;
				return res;
			}
			flag = true;
			right_start.x++;
			right_start.y--;
			right_end.x++;
			right_end.y++;
		}
		if (filter(&bottom_start, &bottom_end, img.rows, img.cols, BOTTOM)) {
			Mat dist(img, Range(bottom_end.y, bottom_start.y + 1), Range(bottom_end.x, bottom_start.x + 1));
			res = detect_marker(dist, target, n, number);
			if (number == 0) {
				res[0].x += bottom_end.x;
				res[0].y = bottom_end.y;
				return res;
			}
			flag = true;
			bottom_start.x++;
			bottom_start.y++;
			bottom_end.x--;
			bottom_end.y++;
		}
		if (filter(&left_start, &left_end, img.rows, img.cols, LEFT)) {
			Mat dist(img, Range(left_end.y, left_start.y + 1), Range(left_end.x, left_start.x + 1));
			res = detect_marker(dist, target, n, number);
			if (number == 0) {
				res[0].y += left_end.y;
				res[0].x = left_end.x;
				return res;
			}
			flag = true;
			left_start.x--;
			left_start.y++;
			left_end.x--;
			left_end.y--;
		}
	}
	return res;
}

vector<Point> Cuetrack::detect_marker(Mat img, Scalar target, size_t n, int &number){
	uchar tmp_R;
	uchar tmp_G;
	uchar tmp_B;
	vector<Point> res;
	int accum = 0;
	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			Vec3b intensity = img.at<Vec3b>(i, j);
			tmp_B = (uchar)intensity.val[0];
			tmp_G = (uchar)intensity.val[1];
			tmp_R = (uchar)intensity.val[2];
			tmp_R = target.val[2] > tmp_R ? target.val[2] - tmp_R : tmp_R - target.val[2];
			tmp_G = target.val[1] > tmp_G ? target.val[1] - tmp_G : tmp_G - target.val[1];
			tmp_B = target.val[0] > tmp_B ? target.val[0] - tmp_B : tmp_B - target.val[0];
            if ((tmp_R > target.val[2] * 0.7) || (tmp_G > target.val[1] * 0.2) || (tmp_B > target.val[0] * 0.2)) {
				if (accum > 0)
					accum--;
				continue;
			}
			accum++;
			if (accum > 2) {
				number--;
				res.push_back(Point(j + n / 2, i + n / 2));
			}
			if (number < 1)
				return res;
		}
	}
	return res;
}

vector<Point> Cuetrack::predict_marker(vector<Point> pre, vector<Point> cur) {
	if (cur.size() == 0) {
		return pre;
	}
	vector<Point> res;
	if (pre.size() == 0)
		return cur;
	res.push_back(Point((cur[0].x + pre[0].x)/2, (cur[0].y + pre[0].y) / 2));
    return res;
}



bool Cuetrack::filter(Point *start, Point *end, int m, int n, int Type){
	switch (Type)
	{
	case TOP:
		if (start->y < 0)
			return false;
		start->x = (start->x < 0) ? 0 : start->x;
		end->x = (end->x < n) ? end->x : n - 1;
		break;
	case BOTTOM:
		if (start->y > m - 1)
			return false;
		start->x = (start->x > n - 1) ? n - 1 : start->x;
		end->x = (end->x > -1) ? end->x : 0;
		break;
	case LEFT:
		if (start->x < 0)
			return false;
		start->y = (start->y > m - 1) ? m - 1 : start->y;
		end->y = (end->y < 0) ? 0 : end->y;
		break;
	case RIGHT:
		if (start->x > n - 1)
			return false;
		start->y = (start->y > -1) ? start->y : 0;
		end->y = (end->y < m - 1) ? end->y : m - 1;
		break;
	default:
		return false;
	}
	return true;
}
