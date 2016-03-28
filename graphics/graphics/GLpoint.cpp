#include <iostream>
#include "GLpoint.hpp"

using namespace std;

void GLpoint::show()
{
	cout << "[" << x << ", " << y << "]";
}

GLpoint& GLpoint::operator=( GLpoint& point )
{
	this->x = point.x;
	this->y = point.y;

	return *this;
}

GLpoint GLpoint::operator+( GLpoint& point )
{
	GLpoint temp(this->x, this->y);

	temp.x += point.x;
	temp.y += point.y;		

	return temp;
}

GLpoint GLpoint::operator-( GLpoint& point )
{
	GLpoint temp(this->x, this->y);

	temp.x -= point.x;
	temp.y -= point.y;		

	return temp;
}

GLpoint GLpoint::operator*( int num )
{
	GLpoint temp(this->x, this->y);

	temp.x *= num;
	temp.y *= num;

	return temp;
}

GLpoint& GLpoint::moveUp( int distance )
{
	y -= distance;
	return *this;
}

GLpoint& GLpoint::moveDown( int distance )
{
	y += distance;
	return *this;
}

GLpoint& GLpoint::moveLeft( int distance )
{
	x -= distance;
	return *this;
}

GLpoint& GLpoint::moveRight( int distance )
{
	x += distance;
	return *this;
}

GLpoint& GLpoint::move( int distance, int direction )
{
	switch(direction)
	{
	case POINT_UP :
		y -= distance;
		break;
	case POINT_DOWN :
		y += distance;
		break;
	case POINT_LEFT :
		x -= distance;
		break;
	case POINT_RIGHT :
		x += distance;
		break;
	default:
		cout << "incorrect direction" << endl;
		exit(1);
	}

	return *this;
}
