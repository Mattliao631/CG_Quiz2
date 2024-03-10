#pragma once

#include <array>
#include <string>
#include <map>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace CG
{
	class MainScene
	{
	public:
		MainScene();
		~MainScene();

		auto Initialize() -> bool;
		void Update(double dt);
		void Render();

		void OnResize(int width, int height);
		void OnKeyboard(int key, int action);
		void OnCursorMove(double xpos, double ypos);
		void OnMouseButton(int button, int action, int mod);

		void SetMode(int mode);

	private:
		GLenum mode = GL_FILL; // GL_FILL or GL_LINE

		std::array<float, 3> p0c; // Color of P0
		std::array<float, 3> p1c; // Color of P1
		std::array<float, 3> p2c; // Color of P2

		std::array<float, 10> px;
		std::array<float, 10> py;

		float xOffset = 0.0;
		float yOffset = 0.0;

		float rotationSpeed = 0.2;
		float rotation = 0.0;

		glm::vec3 cameraPosition;
		glm::vec3 cameraFront;
		glm::vec3 cameraUp;

		float cameraYaw = -90.0f;
		float cameraPitch = 0.0f;

		float lastX = 1280.0f / 2;
		float lastY = 720.0f / 2;

		float cameraSpeed = 0.05f;
		bool rotatingCamera = false;
	};
}

