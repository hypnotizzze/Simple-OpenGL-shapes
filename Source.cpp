#define GLEW_STATIC
#include <Windows.h>
#include <iostream>
#include "Shader.h"
#include "V.h"

int current_state = 1;

void key_callback(GLFWwindow* window, int state, int scancode, int action, int mode);


int main()
{
	//Инициализация GLFW
	if (!glfwInit())
		return -1;
	//Настройка GLFW
	//Задается минимальная требуемая версия OpenGL. 
	//Мажорная 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//Минорная
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//Установка профайла для которого создается контекст
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Выключение возможности изменения размера окна
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	GLFWwindow* window = glfwCreateWindow(1200, 800, "LearnOpenGL", nullptr, nullptr);

	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	glfwSetKeyCallback(window, key_callback);

	GLint nrAttributes;
	glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
	std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes << std::endl;

	Shader sh1("vertex_1.txt", "fragment_1.txt"); // Создание шейдера
	sh1.Use();
	sh1.SetColor(1.0f, 0.0f, 0.0f, 1.0f);
	GLfloat timeValue, Red_Value, Green_Value, Blue_Value;
	VO VO_1; // Создание VBO и VAO
	VO_1.Init();

	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents(); // Проверка вызова события
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		sh1.Use();
		switch (current_state)
		{
			case 1:
				VO_1.Draw_Primitive();
				break;
			case 2:
				VO_1.Set_Of_Triangles();
				break;
			case 3:
				VO_1.Set_Of_Lines();
				break;
			case 4:
				VO_1.Isosceles_Triangle();
				break;
			case 5:
				VO_1.Rectangular_Trapezoid();
				break;
			case 6:
				VO_1.M_gon();
				break;
			case 7:
				VO_1.Parallelogram();
				break;
			case 8:
				VO_1.Rectangle();
				break;
			case 9:
				VO_1.Deltoid();
				break;
			case 0:
				VO_1.Rhombus();
				break;
			case 10:
				timeValue = glfwGetTime();
				Red_Value = (sin(timeValue) / 2) + 0.5;
				Green_Value = (cos(timeValue));
				Blue_Value = (cos(timeValue) / 2) + 0.5;
				sh1.SetColor(Red_Value, Green_Value, Blue_Value, 1.0f);
				VO_1.Random_Vert();
				break;
			default:
				break;
		}	  		
		glfwSwapBuffers(window); // Смена местами буффера
	}
	glfwTerminate();
	return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	// Когда пользователь нажимает ESC, мы устанавливаем свойство WindowShouldClose в true, 
	// и приложение после этого закроется
	if (((GetKeyState(VK_CONTROL) & 0xA2) && (GetKeyState(0x51) & 0x51)) || GetKeyState(VK_ESCAPE) & 0x1B)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_0 && action == GLFW_PRESS)
		current_state = 0;
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		current_state = 1;
	if (key == GLFW_KEY_2 && action == GLFW_PRESS)
		current_state = 2;
	if (key == GLFW_KEY_3 && action == GLFW_PRESS)
		current_state = 3;
	if (key == GLFW_KEY_4 && action == GLFW_PRESS)
		current_state = 4;
	if (key == GLFW_KEY_5 && action == GLFW_PRESS)
		current_state = 5;
	if (key == GLFW_KEY_6 && action == GLFW_PRESS)
		current_state = 6;
	if (key == GLFW_KEY_7 && action == GLFW_PRESS)
		current_state = 7;
	if (key == GLFW_KEY_8 && action == GLFW_PRESS)
		current_state = 8;
	if (key == GLFW_KEY_9 && action == GLFW_PRESS)
		current_state = 9;
	if (key == GLFW_KEY_R && action == GLFW_PRESS)
		current_state = 10;
	if (key == GLFW_KEY_Q && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

}