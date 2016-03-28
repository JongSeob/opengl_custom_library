#ifndef GLrect_h__
#define GLrect_h__

#include "GLpoint.hpp"

enum {RECT_LEFT, RECT_RIGHT, RECT_UP, RECT_DOWN};

// GLrect�� TopLeft, BottomRight ��ǥ�� GLUT & WINDOW ��ǥ�� �������� �Ѵ�.
// ���������� �̵��� ���� x���� ����, ������ ������ ���� y���� ����.
class GLrect 
{
private:
	GLpoint TopLeft;
	GLpoint BottomRight;

	int width;
	int height;

public:

	//** Function **//

	// ������, �����ʾƷ� ��ǥ ���.
	void show();

	// point�� rect ���ο� �ִ��� Ȯ��
	bool contains(GLpoint point);

	// �ش� rect�� �����ִ��� Ȯ��.
	bool isOverlappedWith(GLrect rect);
	
	// �ش� �������� ��ǥ �̵�.
	GLrect& move(int distance, int direction);

	

	//** Constructor **//

	GLrect(int topLeft_X = 0, int topLeft_Y = 0, int bottomRight_X = 0, int bottomRight_Y = 0);
	GLrect(GLpoint topLeft, GLpoint bottomRight);

	//** Operator Overloading **//

	GLrect& operator=(GLrect _rect);

	//** ���� Encapsulation  **//

	GLpoint getTopLeft();

	void setTopLeft(int x, int y);

	void setTopLeft(GLpoint point);

	GLpoint getBottomRight();

	void setBottomRight(int x, int y);

	void setBottomRight(GLpoint point);

	const int getWidth();

	const int getHeight();

};

#endif // GLrect_h__
