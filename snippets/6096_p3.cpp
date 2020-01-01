// 6096_p3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "geometry.h"

void printAttirbutes(Polygon* p) {
	std::cout << "Area: " << p->area() << std::endl;
	for (int i = 0; i < 4; ++i) {
		std::cout << "Point " << i << " : "
			<< p->getPoints()->get(i)->getX() << " "
			<< p->getPoints()->get(i)->getY() << std::endl;
	}
}


int main()
{
	// P4 extras
	// Rectangle *rect = new Rectangle(0,0,5,5);
	// static_cast <Triangle *>(rect); // cannot even compile
	// dynamic_cast <Triangle *>(rect);  // can compile but runtime may fail
	// delete rect;

	// P3
	double ux, uy, lx, ly;
	std::cout << "Rectangle Points" << std::endl;
	std::cout << "Upper X" << std::endl;
	std::cin >> ux;
	std::cout << "Upper Y" << std::endl;
	std::cin >> uy;
	std::cout << "Lower X" << std::endl;
	std::cin >> lx;
	std::cout << "Lower Y" << std::endl;
	std::cin >> ly;
	Rectangle r(lx, ly, ux , uy);
    // upcasting (base ptr to child obj)
    Polygon* p = &r;
    std::cout << "Rectangle Attributes: " << std::endl;
	printAttirbutes(p);
	
	
	double x1, x2, x3, y1, y2, y3;
	std::cout << "Triangle Points" << std::endl;
	std::cout << "X1" << std::endl;
	std::cin >> x1;
	std::cout << "Y1" << std::endl;
	std::cin >> y1;
	std::cout << "X2" << std::endl;
	std::cin >> x2;
	std::cout << "Y2" << std::endl;
	std::cin >> y2;
	std::cout << "X3" << std::endl;
	std::cin >> x3;
	std::cout << "Y3" << std::endl;
	std::cin >> y3;
	Triangle t(x1, y1, x2, y2, x3, y3);
    p = &t;
	std::cout << "Triangle Attributes: " << std::endl;
	printAttirbutes(p);

	return 0;
}

/*
1. In the Point class, what would happen if the constructors were private?
--Cannot create `Point` objects. Unless there is a friend function/method from another class
declared in `Point` that also calls the constructor.

2. Describe what happens to the fields of a Polygon object when the object is destroyed.
--Calls the destructor of its `PointArray`, which deallocates the array of `Point`s.
Also decrements the `static count` shared by all `Polygon`s.

3. Why did we need to make the fields of Polygon protected?
--We want them to be private to outside but still accessible to inheriting classes.

For the next question, assume you are writing a function that takes as an argument a Polygon
* called polyPtr.
4. Imagine that we had overridden getNumSides in each of Rectangle and Triangle.
Which version of the function would be called if we wrote polyPtr->getNumSides()? Why?
--It depends whether virtual keyword was used to declare getNumSides() in Polygon.
If it is, then the version called depends on the class of the object pointed by polyPtr.
If not, then the version is always Polygon's.

*/

