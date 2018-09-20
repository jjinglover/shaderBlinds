
#ifndef __wrapperWindow__
#define __wrapperWindow__

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class wrapperWindow
{
public:
	wrapperWindow(){};
	wrapperWindow(int w, int h){
		m_window = nullptr;
		this->init(w, h);
	}
	~wrapperWindow(){};

	GLFWwindow *getWindow(){
		return m_window;
	}
private:
	bool init(int w, int h){
		glfwInit();

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
		glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

		m_window = glfwCreateWindow(w, h, "opengl", nullptr, nullptr);
		if (!m_window){
			std::cout << "create window failed" << std::endl;
		}
		glfwMakeContextCurrent(m_window);

		glewExperimental = GL_TRUE;
		GLint err = glewInit();
		if (err != GLEW_OK)
		{
			auto str = glewGetErrorString(err);
			std::cout << "failed to init glew" << str << std::endl;
			glfwTerminate();
			return false;
		}

		int width, height;
		glfwGetFramebufferSize(m_window, &width, &height);
		glViewport(0, 0, width, height);
		return true;
	}

	GLFWwindow *m_window;
};

#endif