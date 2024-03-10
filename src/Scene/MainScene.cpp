#include <iostream>
#include <cmath>

#include "MainScene.h"

#include <imgui.h>
#include <imgui_internal.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_glfw.h>

#define PI 3.14159265358


template <typename T>
T DegreeToRadian(T degree) {
    return degree / double(180.0) * double(PI);
}
template <typename T>
T RadianToDegree(T radian) {
    return radian / double(PI) * double(180.0);
}

namespace CG
{
    MainScene::MainScene()
    {
        p0c = { 1.0, 0.0, 0.0 };
        p1c = { 1.0, 0.0, 0.0 };
        p2c = { 1.0, 0.0, 0.0 };
        
        float ro = 1.0;
        float ri = ro * sin(DegreeToRadian(18.0)) / sin(DegreeToRadian(54.0));

        for (int i = 0; i < 10; i += 2) {
            px[i] = cos(DegreeToRadian(36.0 * i + 18.0));
            py[i] = sin(DegreeToRadian(36.0 * i + 18.0));
            px[i + 1] = ri * cos(DegreeToRadian(36.0 * i + 54.0));
            py[i + 1] = ri * sin(DegreeToRadian(36.0 * i + 54.0));
        }

        cameraFront = glm::vec3(0, 0, -1);
        cameraPosition = glm::vec3(0, 0, 3);
    }

    MainScene::~MainScene()
    {
    }

    auto MainScene::Initialize() -> bool
    {
        glEnable(GL_DEPTH_TEST);
        glCullFace(GL_BACK);
        glEnable(GL_CULL_FACE);
        OnResize(1280, 720);
        
        return true;
    }

    void MainScene::Update(double dt)
    {

    }

    void MainScene::Render()
    {
        
        
        
        glMatrixMode(GL_MODELVIEW);
        glClearColor(0.0, 0.0, 0.0, 1); // Black background
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glPolygonMode(GL_FRONT_AND_BACK, mode);
        
        glLoadIdentity();
        glPushMatrix();

        gluLookAt(
            cameraPosition.x, cameraPosition.y, cameraPosition.z,
            cameraPosition.x + cameraFront.x, cameraPosition.y + cameraFront.y, cameraPosition.z + cameraFront.z,
            cameraUp.x, cameraUp.y, cameraUp.z
        );

        glTranslatef(xOffset, yOffset, 0.0f);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
        // Start drawing triangles in counter-clockwise (ccw) order
        glBegin(GL_TRIANGLES);

        // Right Up
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[0], py[0]);
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[1], py[1]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[9], py[9]);

        // Up
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[1], py[1]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[2], py[2]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[3], py[3]);

        // Left Up
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[3], py[3]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[4], py[4]);
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[5], py[5]);
        
        // Left Down
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[5], py[5]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[6], py[6]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[7], py[7]);

        // Right Down
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[8], py[8]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[9], py[9]);

        // Mid Left
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[3], py[3]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[5], py[5]);

        // Mid Up
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[1], py[1]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[3], py[3]);

        //Mid Right
        glColor3f(p1c[0], p1c[1], p1c[2]);
        glVertex2f(px[7], py[7]);
        glColor3f(p0c[0], p0c[1], p0c[2]);
        glVertex2f(px[9], py[9]);
        glColor3f(p2c[0], p2c[1], p2c[2]);
        glVertex2f(px[1], py[1]);
         

        //// P0
        //glColor3f(p0c[0], p0c[1], p0c[2]);
        //glVertex2f(-0.5, -0.5);

        //// P1
        //glColor3f(p1c[0], p1c[1], p1c[2]);
        //glVertex2f(0.5, -0.5);

        //// P2
        //glColor3f(p2c[0], p2c[1], p2c[2]);
        //glVertex2f(0, 0.5);

        // End drawing triangles
        glEnd();
        rotation += rotationSpeed;
    }

    void MainScene::OnResize(int width, int height)
    {
        
        std::cout << "MainScene Resize: " << width << " " << height << std::endl;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glViewport(0, 0, width, height);
        gluPerspective(100.0f, (double)width / (double)height, 0.1, 256.0f);

    }

    void MainScene::OnKeyboard(int key, int action)
    {
        std::cout << "MainScene OnKeyboard: " << key << " " << action << std::endl;

        float deltaTime = 0.1f;
        if (action == GLFW_REPEAT) {
            switch (key) {
            case GLFW_KEY_D:
                cameraPosition += glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
                break;
            case GLFW_KEY_A:
                cameraPosition -= glm::normalize(glm::cross(cameraFront, cameraUp)) * cameraSpeed * deltaTime;
                break;
            case GLFW_KEY_S:
                cameraPosition -= cameraSpeed * deltaTime * cameraFront;
                break;
            case GLFW_KEY_W:
                cameraPosition += cameraSpeed * deltaTime * cameraFront;
                break;
            }
        }
        if (action == GLFW_RELEASE)
        {
            switch (key)
            {
            case GLFW_KEY_1: // Red
                p0c = { 1.0, 0.0, 0.0 };
                p1c = { 1.0, 0.0, 0.0 };
                p2c = { 1.0, 0.0, 0.0 };
                break;
            case GLFW_KEY_2: // Green
                p0c = { 0.0, 1.0, 0.0 };
                p1c = { 0.0, 1.0, 0.0 };
                p2c = { 0.0, 1.0, 0.0 };
                break;
            case GLFW_KEY_3: // Blue
                p0c = { 0.0, 0.0, 1.0 };
                p1c = { 0.0, 0.0, 1.0 };
                p2c = { 0.0, 0.0, 1.0 };
                break;
            case GLFW_KEY_4: // Rainbow
                p0c = { 1.0, 0.0, 0.0 };
                p1c = { 0.0, 1.0, 0.0 };
                p2c = { 0.0, 0.0, 1.0 };
                break;
            case GLFW_KEY_DOWN:
                yOffset -= 0.1;
                break;
            case GLFW_KEY_UP:
                yOffset += 0.1;
                break;
            case GLFW_KEY_LEFT:
                xOffset -= 0.1;
                break;
            case GLFW_KEY_RIGHT:
                xOffset += 0.1;
                break;
            case GLFW_KEY_RIGHT_SHIFT:
                rotationSpeed -= 0.1;
                break;
            case GLFW_KEY_LEFT_SHIFT:
                rotationSpeed += 0.1;
                break;
            }
            
            
        }
    }
    bool firstMouse = true;

    void MainScene::OnCursorMove(double xpos, double ypos) {
        
        if (firstMouse) {
            lastX = xpos;
            lastY = ypos;
            firstMouse = false;
        }
        
        float xoffset = xpos - lastX;
        float yoffset = lastY - ypos;

        lastX = xpos;
        lastY = ypos;
        if (!rotatingCamera) {
            return;
        }
        float sensitivity = 0.05f;
        xoffset *= sensitivity;
        yoffset *= sensitivity;

        cameraYaw += xoffset;
        cameraPitch += yoffset;

        // Clamp pitch to avoid flipping
        if (cameraPitch > 89.0f) {
            cameraPitch = 89.0f;
        }
        if (cameraPitch < -89.0f) {
            cameraPitch = -89.0f;
        }

        // Update camera front direction
        glm::vec3 front;
        glm::vec3 up;
        front.x = cos(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
        front.y = sin(glm::radians(cameraPitch));
        front.z = sin(glm::radians(cameraYaw)) * cos(glm::radians(cameraPitch));
        std::cout << "Pos:" << std::endl;
        std::cout << "\tX: " << cameraPosition.x << " Y: " << cameraPosition.y << " Z: " << cameraPosition.z << std::endl;
        std::cout << "Front:" << std::endl;
        std::cout << "\tX: " << front.x << " Y: " << front.y << " Z: " << front.z << std::endl;

        up.x = sin(glm::radians(cameraPitch)) * cos(glm::radians(cameraYaw));
        up.y = cos(glm::radians(cameraPitch));
        up.z = sin(glm::radians(cameraPitch)) * -sin(glm::radians(cameraYaw));

        cameraFront = glm::normalize(front);
        cameraUp = glm::normalize(up);
    }
    void MainScene::OnMouseButton(int button, int action, int mod) {
        ImGuiIO& io = ImGui::GetIO();
        switch (button) {
        case GLFW_MOUSE_BUTTON_RIGHT:
            if (action == GLFW_PRESS) {
                rotatingCamera = true;
            }
            else if (action == GLFW_RELEASE) {
                rotatingCamera = false;
            }
        }
    }

    void MainScene::SetMode(int mode)
    {
        switch (mode)
        {
        case 0:
            this->mode = GL_FILL;
            break;
        case 1:
            this->mode = GL_LINE;
            break;
        default:
            this->mode = GL_FILL;
            break;
        }
    }
}