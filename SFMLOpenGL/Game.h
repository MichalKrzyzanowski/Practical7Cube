#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>


using namespace std;

class Game
{
public:
	Game();
	~Game();
	void run();
	void setup();
	void controlCube();
private:
	sf::Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	GLuint index;
	sf::Clock clock;
	sf::Time elapsed;

	float rotationAngle = 0.0f;

	Vector3 m_points[8];
};