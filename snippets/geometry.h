#pragma once
class Point {
	int x, y;
public:
	Point(int x = 0, int y = 0): x(x), y(y) {}
	int getX() const { return x; } // constant function
	int getY() const { return y; } // constant function
	void setX(const int new_x) { x = new_x; }
	void setY(const int new_y) { y = new_y; }
};

class PointArray {
	Point* start;
	int size;

protected:
	void resize(int n);

public:
	PointArray() : start(nullptr), size(0) {};
	PointArray(const Point points[], const int size);
	// copy constructor. create a new object using existing.
	// By default, it performs shallow copy. Ie only copies the immediate members.
	// For objects with pointers to dynamically-allocated stuff,
	// write specific copy constructor to enable deep copying
	PointArray(const PointArray& pv);
	~PointArray();
	void push_back(const Point &p);
	void insert(const int position, const Point &p);
	void remove(const int position);
	const int getSize() const { return size; }
	void clear();
	Point *get(const int position) { return (position >= 0 && position < size ? &start[position] : nullptr); }
	// to ensure returned `Point` is immutable
	const Point *get(const int position) const { return (position >= 0 && position < size ? &start[position] : nullptr); }
};

class Polygon {
protected:
	PointArray pa;
	static int count;

public:
	Polygon(const Point points[], const int size): pa(points, size) { ++count; }
	Polygon(const PointArray other): pa(other) { ++count; }
	// Do not need specific copy constructor for `Polygon` here
	// `PointArray` already has a specific CopyCotr & will be called
	~Polygon() { --count; }
	virtual double area() const = 0; // abstract class
	// independent of any `Polygon` instances
	// can be called even if no `Polygon`s exist yet
	static int getNumPolygons() { return count; }
	virtual int getNumSides() = 0;
	const PointArray* getPoints() { return &pa; }
};

class Rectangle : public Polygon {
public:
	Rectangle(const Point &ll, const Point &ur);
	Rectangle(const int &lx, const int &ly, const int &ux, const int &uy);
	virtual int getNumSides() { return 4; }
	virtual double area() const;
};

class Triangle : public Polygon {
public:
	friend double euclidean (const double &a, const double &b);
	Triangle(const Point &p1, const Point &p2, const Point &p3);
	Triangle(const int &x1, const int &y1, const int &x2, const int &y2,
		const int &x3, const int &y3);
	virtual int getNumSides() { return 3; }
	virtual double area() const;
};