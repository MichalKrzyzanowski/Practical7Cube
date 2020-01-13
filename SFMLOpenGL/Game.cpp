#include <Game.h>

bool updatable = false;


Game::Game() : window(sf::VideoMode(800, 600), "OpenGL Cube"),
m_points
{
	{ -1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ -1.0f, -1.0f, 1.0f },
	{ 1.0f, -1.0f, 1.0f },

	{ -1.0f, 1.0f, -1.0f },
	{ 1.0f, 1.0f, -1.0f },
	{ -1.0f, -1.0f, -1.0f },
	{ 1.0f, -1.0f, -1.0f },
}

{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{
	initialize();
	
	

	sf::Event event;

	while (isRunning)
	{
		
		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::setup()
{
	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{
		

		// top face
		glColor3f(0.0f, 1.0f, 1.0f); // cyan
		glVertex3f(m_points[4].X, m_points[4].Y, m_points[4].Z); // 5
		glVertex3f(m_points[5].X, m_points[5].Y, m_points[5].Z); // 6
		glVertex3f(m_points[1].X, m_points[1].Y, m_points[1].Z); // 2


		glVertex3f(m_points[1].X, m_points[1].Y, m_points[1].Z); // 2
		glVertex3f(m_points[0].X, m_points[0].Y, m_points[0].Z); // 1
		glVertex3f(m_points[4].X, m_points[4].Y, m_points[4].Z); // 5

		// right face
		glColor3f(1.0f, 1.0f, 1.0f); // white
		glVertex3f(m_points[1].X, m_points[1].Y, m_points[1].Z); // 2
		glVertex3f(m_points[5].X, m_points[5].Y, m_points[5].Z); // 6
		glVertex3f(m_points[7].X, m_points[7].Y, m_points[7].Z); // 8

		glVertex3f(m_points[7].X, m_points[7].Y, m_points[7].Z); // 8
		glVertex3f(m_points[3].X, m_points[3].Y, m_points[3].Z); // 4
		glVertex3f(m_points[1].X, m_points[1].Y, m_points[1].Z); // 2


		//Back Face
		glColor3f(1.0f, 1.0f, 0.0f); // yellow
		glVertex3f(m_points[5].X, m_points[5].Y, m_points[5].Z); // 6
		glVertex3f(m_points[4].X, m_points[4].Y, m_points[4].Z); // 5
		glVertex3f(m_points[6].X, m_points[6].Y, m_points[6].Z); // 7

		glVertex3f(m_points[6].X, m_points[6].Y, m_points[6].Z); // 7
		glVertex3f(m_points[7].X, m_points[7].Y, m_points[7].Z); // 8
		glVertex3f(m_points[5].X, m_points[5].Y, m_points[5].Z); // 6


		// left face
		glColor3f(1.0f, 0.0f, 1.0f); // magenta
		glVertex3f(m_points[0].X, m_points[0].Y, m_points[0].Z); // 1
		glVertex3f(m_points[4].X, m_points[4].Y, m_points[4].Z); // 5
		glVertex3f(m_points[6].X, m_points[6].Y, m_points[6].Z); // 7

		glVertex3f(m_points[6].X, m_points[6].Y, m_points[6].Z); // 7
		glVertex3f(m_points[2].X, m_points[2].Y, m_points[2].Z); // 3
		glVertex3f(m_points[0].X, m_points[0].Y, m_points[0].Z); // 1


		//Front Face
		glColor3f(0.0f, 0.0f, 1.0f); // blue
		glVertex3f(m_points[1].X, m_points[1].Y, m_points[1].Z); // 2
		glVertex3f(m_points[0].X, m_points[0].Y, m_points[0].Z); // 1
		glVertex3f(m_points[2].X, m_points[2].Y, m_points[2].Z); // 3 

		glVertex3f(m_points[1].X, m_points[1].Y, m_points[1].Z); // 2
		glVertex3f(m_points[2].X, m_points[2].Y, m_points[2].Z); // 3
		glVertex3f(m_points[3].X, m_points[3].Y, m_points[3].Z); // 4


		// bottom face
		glColor3f(1.0f, 0.0f, 0.0f); // red
		glVertex3f(m_points[6].X, m_points[6].Y, m_points[6].Z);// 7
		glVertex3f(m_points[7].X, m_points[7].Y, m_points[7].Z); // 8
		glVertex3f(m_points[3].X, m_points[3].Y, m_points[3].Z); // 4

		glVertex3f(m_points[3].X, m_points[3].Y, m_points[3].Z); // 4
		glVertex3f(m_points[2].X, m_points[2].Y, m_points[2].Z); // 3
		glVertex3f(m_points[6].X, m_points[6].Y, m_points[6].Z); // 7

		//Complete the faces of the Cube
	}
	glEnd();
	glEndList();
}

void Game::controlCube()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::RotationX(rotationAngle) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::RotationX(-rotationAngle) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::RotationY(rotationAngle) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::RotationY(-rotationAngle) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::RotationZ(rotationAngle) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::RotationZ(-rotationAngle) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::Translate(0, -1) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::Translate(0, 1) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::Translate(-1, 0) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::Translate(1, 0) * m_points[i];
		}
	}


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::Scale3D(101.0) * m_points[i];
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
	{
		for (int i = 0; i < 8; i++)
		{
			m_points[i] = Matrix3::Scale3D(99.0) * m_points[i];
		}
	}
}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml
	setup();
}

void Game::update()
{
	setup();
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	//glNewList(index, GL_COMPILE);
	
	rotationAngle = 0.5f;
	
	controlCube();

	cout << "Update up" << endl;
}

void Game::draw()
{
	cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	cout << "Drawing Cube " << endl;
	glLoadIdentity();
	//glRotatef(rotationAngle, 0, 0, 1); // Rotates the camera on Y Axis
	glTranslatef(0.0f, 0.0f, -8.0f);

	glCallList(1);

	window.display();

}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

