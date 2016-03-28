#ifndef GLpoint_h__
#define GLpoint_h__

// 좌표는 GLUT, Window 기준. 
// 오른쪽으로 이동하면 x 증가, 아래로 내려가면 y 증가

enum {POINT_LEFT, POINT_RIGHT, POINT_UP, POINT_DOWN};

struct GLpoint
{
	// Variable

	int x;
	int y;

	// Function

	void show();

	GLpoint& move(int distance, int direction);
	GLpoint& moveUp(int distance);
	GLpoint& moveDown(int distance);
	GLpoint& moveLeft(int distance);
	GLpoint& moveRight(int distance);
	
	// Constructor
	GLpoint(int x = 0, int y = 0) : x(x), y(y) {}
		
	// Operator Overloading
	GLpoint& operator=(GLpoint& point);
	GLpoint operator+(GLpoint& point);
	GLpoint operator-(GLpoint& point);
	GLpoint operator*(int num);
};

#endif // GLpoint_h__
