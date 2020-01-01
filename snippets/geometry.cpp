#include "geometry.h"
#include <math.h>

PointArray::PointArray(const Point points[], const int size) {
	this->size = size;
	start = new Point[size];
	for (int i = 0; i < size; ++i) {
		// default assign operator. copies values (from `points`) 
		// into already initialized object(`Point`s in `start`)
		// Point p1 = p2; [COPY CONSTRUCTOR]
		// p1 = p2; [ASSIGN OPERATOR]
		start[i] = points[i];
	}
}

PointArray::PointArray(const PointArray& pv) {
	size = pv.size;
	start = new Point[pv.size];  // allocate new memory to...
	for (int i = 0; i < size; ++i) {
		start[i] = pv.start[i];  // ensure 2 arrays do not use the same memory
	}
}

PointArray::~PointArray() {
	delete[] start;
}

void PointArray::resize(int n) {
	Point* temp = new Point[n];
	int lim = n < size ? n : size;
	for (int i = 0; i < lim; ++i) {
		temp[i] = this->start[i];
	}
	delete[] start;
	start = temp;
	size = n;
}

void PointArray::push_back(const Point &p){
	resize(size + 1);
	start[size - 1] = p; // Just the assign operator copying values
}

void PointArray::insert(const int position, const Point &p) {
	resize(size + 1);
	int lim = size < position && position >= 0 ? size : position;
	for (int i = size; i > lim; --i) {
		start[i] = start[i - 1];
	}
	start[lim] = p;
}

void PointArray::remove(const int position) {
	if (position >=0 && position < size) {
		for (int i = position; i < size - 1; ++i) {
			start[i] = start[i + 1];
		}
		resize(size - 1);
	}
}

void PointArray::clear() {
	size = 0;
	delete[] start;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

// Used only to create `PointArray` using `Point`s
Point creator[4];

PointArray createFromPoints(const Point &p1, const Point &p2,
	const Point &p3, const Point &p4 = Point()) {  // always 4. 4th is optional for `Triangle`s
	creator[0] = p1;
	creator[1] = p2;
	creator[2] = p3;
	creator[3] = p4;
	return PointArray(creator, 4); // in C++, cannot return address of temporary object
}

int Polygon::count = 0;  // How-to initialize static member

Rectangle::Rectangle(const Point &ll, const Point &ur):
Polygon(createFromPoints(ll, ur, Point(ll.getX(), ur.getY()),
	Point(ur.getX(), ll.getY()))) {}

Rectangle::Rectangle(const int &lx, const int &ly, const int &ux, const int &uy)
:Polygon(createFromPoints(Point(lx, ly), Point(ux, uy), Point(lx, uy),
	Point(ux, ly))) {}

double Rectangle::area() const {
	int width = pa.get(1)->getX() - pa.get(0)->getX();
	int height = pa.get(1)->getY() - pa.get(0)->getY();
	return double(height * width);
}

////////////////////////////////////////////////////////////////////////////////////////////////////

Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3)
:Polygon(createFromPoints(p1, p2, p3)) {}

Triangle::Triangle(const int &x1, const int &y1, const int &x2, const int &y2,
	const int &x3, const int &y3)
	: Polygon(createFromPoints(Point(x1, y1), Point(x2, y2), Point(x3, y3))) {}

double euclidean(const double &delx, const double &dely){
	return sqrt(delx * delx + dely * dely);
}

double Triangle::area() const {
	double a = euclidean(pa.get(1)->getX() - pa.get(0)->getX(), \
		pa.get(1)->getY() - pa.get(0)->getY());
	double b = euclidean(pa.get(1)->getX() - pa.get(2)->getX(), \
		pa.get(1)->getY() - pa.get(2)->getY());
	double c = euclidean(pa.get(2)->getX() - pa.get(0)->getX(), \
		pa.get(2)->getY() - pa.get(0)->getY());
	double s = (a+b+c) / 2;

	return sqrt(s*(s-a)*(s-b)*(s-c));
}
