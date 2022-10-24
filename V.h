#ifndef VO_H
#define VO_H

#include <GL/glew.h> // GLEW
#include <GLFW/glfw3.h> // GLFW
#include <cstdlib> // rand and srand
#include <ctime> // time

GLfloat vertices[] = {
	0.45f, 0.9f, 0.0f,
	0.9f, 0.0f, 0.0f,
	0.45f, -0.9f, 0.0f,
	-0.45f, -0.9f, 0.0f,
	-0.9f, 0.0f, 0.0f,
	-0.45f, 0.9f, 0.0f,
	0.45f, 0.0f, 0.0f,
	0.0f, 0.45f, 0.0f,
	0.0f, -0.9f, 0.0f,
	0.0f, 0.9f, 0.0f
};

GLfloat vert[3 * 150];

class VO
{
public:
	GLuint VAO = 0, VBO = 0, VAO_POINT=0, VBO_POINT=0;
	void Init()
	{
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);

		srand(time(0));
		for (int i = 0; i < 300;)
		{
			vert[i++] = GLfloat(-1 + 0.01 * (rand() % 180));
			vert[i++] = GLfloat(-1 + 0.01 * (rand() % 180));
			vert[i++] = 0.0f;
		}

		glGenVertexArrays(1, &VAO_POINT);
		glGenBuffers(1, &VBO_POINT);
		glBindVertexArray(VAO_POINT);
		glBindBuffer(GL_ARRAY_BUFFER, VBO_POINT);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vert), vert, GL_DYNAMIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	~VO()
	{
		glDeleteVertexArrays(1, &VAO);
		glDeleteBuffers(1, &VBO);
	} 

	void Draw_Primitive()
	{
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
	}
	void Set_Of_Triangles()
	{
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
		glBindVertexArray(0);
	}
	void Set_Of_Lines()
	{
		glBindVertexArray(VAO);
		glDrawArrays(GL_LINE_LOOP, 0, 6);
		glBindVertexArray(0);
	}
	void Isosceles_Triangle()
	{
		GLuint idx[] = { 3u, 4u, 5u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0);
	}
	void Rectangular_Trapezoid()
	{
		GLuint idx[] = { 6u, 0u, 4u, 5u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0);
	}
	void M_gon()
	{
		GLuint idx[] = { 2u, 3u, 0u, 4u, 5u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLE_STRIP, 5, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0);
	}
	void Parallelogram()
	{
		GLuint idx[] = { 4u, 3u, 0u, 1u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0);
	}
	void Rectangle()
	{
		GLuint idx[] = { 2u, 3u, 0u, 5u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0);
	}
	void Deltoid()
	{
		GLuint idx[] = { 4u, 7u, 8u, 1u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLE_STRIP, 4, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0);
	}
	void Rhombus()
	{
		GLuint idx[] = { 9u, 4u, 8u, 1u };
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, idx);
		glBindVertexArray(0); 
	}
	void Random_Vert()
	{
		glBindVertexArray(VAO_POINT);
		glDrawArrays(GL_POINTS, 0, 150);
		glBindVertexArray(0);
	}
};

#endif