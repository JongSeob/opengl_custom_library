#ifndef GLrect_h__
#define GLrect_h__

#include "GLpoint.hpp"

enum {RECT_LEFT, RECT_RIGHT, RECT_UP, RECT_DOWN};

// GLrect의 TopLeft, BottomRight 좌표는 GLUT & WINDOW 좌표를 기준으로 한다.
// 오른쪽으로 이동할 수록 x값이 증가, 밑으로 내려갈 수록 y값이 증가.
class GLrect 
{
private:
	GLpoint TopLeft;
	GLpoint BottomRight;

	int width;
	int height;

public:

	//** Function **//

	// 왼쪽위, 오른쪽아래 좌표 출력.
	void show();

	// point가 rect 내부에 있는지 확인
	bool contains(GLpoint point);

	// 해당 rect와 겹쳐있는지 확인.
	bool isOverlappedWith(GLrect rect);
	
	// 해당 방향으로 좌표 이동.
	GLrect& move(int distance, int direction);

	

	//** Constructor **//

	GLrect(int topLeft_X = 0, int topLeft_Y = 0, int bottomRight_X = 0, int bottomRight_Y = 0);
	GLrect(GLpoint topLeft, GLpoint bottomRight);

	//** Operator Overloading **//

	GLrect& operator=(GLrect _rect);

	//** 변수 Encapsulation  **//

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
