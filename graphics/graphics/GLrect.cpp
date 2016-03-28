#include <iostream>
#include <cstdlib>
#include "GLrect.hpp"

using namespace std;

GLrect::GLrect( int topLeft_X, int topLeft_Y, int bottomRight_X, int bottomRight_Y )
	:TopLeft(topLeft_X, topLeft_Y), BottomRight(bottomRight_X, bottomRight_Y)
{
	width = bottomRight_X - topLeft_X;
	height = bottomRight_Y - topLeft_Y;
}

GLrect::GLrect( GLpoint topLeft, GLpoint bottomRight )
	:TopLeft(topLeft.x, topLeft.y), BottomRight(bottomRight.x, bottomRight.y)
{
	width = bottomRight.x - topLeft.x;
	height = bottomRight.y - topLeft.y;
}

void GLrect::show()
{
	cout << "TopLeft     = "; TopLeft.show();	  cout << "	width  = " << width << endl;
	cout << "BottomRight = "; BottomRight.show(); cout << "	height = " << height << endl;
}

bool GLrect::contains( GLpoint point )
{
	// point�� rect �ȿ� ���� ��� true, �ƴϸ� false
	if( (TopLeft.x <= point.x && TopLeft.y <= point.y) &&
		(BottomRight.x >= point.x && BottomRight.y >= point.y)
		)
	{
		return true;
	}

	return false;
}

GLrect& GLrect::move( int distance, int direction )
{
	switch(direction)
	{
	case RECT_UP :
		TopLeft.y	  -= distance;
		BottomRight.y -= distance;
		break;
	case RECT_DOWN :
		TopLeft.y     += distance;
		BottomRight.y += distance;
		break;
	case RECT_LEFT :
		TopLeft.x     -= distance;
		BottomRight.x -= distance;
		break;
	case RECT_RIGHT :
		TopLeft.x     += distance;
		BottomRight.x += distance;
		break;
	default:
		cout << "incorrect direction" << endl;
		exit(1);
	}

	return *this;
}

GLrect& GLrect::operator=( GLrect _rect )
{
	this->TopLeft = _rect.TopLeft;
	this->BottomRight = _rect.BottomRight;
	this->width = _rect.width;
	this->height = _rect.height;

	return *this;
}

GLpoint GLrect::getTopLeft()
{
	GLpoint temp = TopLeft;

	return temp;
}

void GLrect::setTopLeft( int x, int y )
{
	TopLeft.x = x;
	TopLeft.y = y;

	width  = BottomRight.x - TopLeft.x;
	height = BottomRight.y - TopLeft.y;
}

void GLrect::setTopLeft( GLpoint point )
{
	TopLeft.x = point.x;
	TopLeft.y = point.y;

	width  = BottomRight.x - TopLeft.x;
	height = BottomRight.y - TopLeft.y;
}

GLpoint GLrect::getBottomRight()
{
	GLpoint temp = BottomRight;

	return temp;
}

void GLrect::setBottomRight( int x, int y )
{
	BottomRight.x = x;
	BottomRight.y = y;

	width  = BottomRight.x - TopLeft.x;
	height = BottomRight.y - TopLeft.y;
}

void GLrect::setBottomRight( GLpoint point )
{
	BottomRight.x = point.x;
	BottomRight.y = point.y;

	width  = BottomRight.x - TopLeft.x;
	height = BottomRight.y - TopLeft.y;
}

const int GLrect::getWidth()
{
	return width;
}

const int GLrect::getHeight()
{
	return height;
}

// �ٸ� ������� �����ִ��� Ȯ��. �׵θ��� ����ִ� ���� ����.
bool GLrect::isOverlappedWith( GLrect rect )
{
	// �簢���� �� �������� ������� ��� ��츦 Ž���� �� �����Ƿ� ������ ��, ���� �Ʒ� �������� �ӽ÷� �߰�.
	GLpoint this_TopRight   = GLpoint(this->TopLeft.x + this->width, this->TopLeft.y);
	GLpoint this_BottomLeft = GLpoint(this->BottomRight.x - this->width, this->BottomRight.y);

	GLpoint rect_TopRight = GLpoint(rect.TopLeft.x + rect.width, rect.TopLeft.y);
	GLpoint rect_BottomLeft = GLpoint(rect.BottomRight.x - rect.width, rect.BottomRight.y);
	
	// �� �簢���� �������� �ٸ� �簢���� ���ԵǴ� ���
	if( (this->contains(rect.TopLeft) || this->contains(rect.BottomRight) || this->contains(rect_BottomLeft) || this->contains(rect_TopRight)) ||  
		(rect.contains(this->TopLeft) || rect.contains(this->BottomRight) || rect.contains(this_BottomLeft) || rect.contains(this_TopRight)) )
	{
		// �� �簢���� ǥ���� ������� ���� ���
		if( (this->TopLeft.x != rect_TopRight.x) && (this_TopRight.x != rect.TopLeft.x) && 
			(this->TopLeft.y != rect.BottomRight.y) && (this->BottomRight.y != rect.TopLeft.y)
			)
		{
			return true;
		}
	}

	return false;
}
