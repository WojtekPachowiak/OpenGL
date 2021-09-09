#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"



class Camera {
public:


    Camera(glm::vec3 position, glm::vec3 up, float yaw, float pitch);
    Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch);

    glm::mat4 GetViewMatrix();

    void ProcessKeyboardAndMove();
    void ProcessMouseMovement(float xoffset, float yoffset, GLboolean constrainPitch);
    void ProcessMouseScroll(float yoffset);

    void updateCameraVectors();

private:
    // camera Attributes
    glm::vec3 Position;
    glm::vec3 Front;
    glm::vec3 Up;
    glm::vec3 Right;
    glm::vec3 WorldUp;
    // euler Angles
    float Yaw;
    float Pitch;
    // camera options
    float MovementSpeed;
    float MovementSpeedBoost;
    float MouseSensitivity;
    float Zoom;
    //how is camera navigated
    Navigation navigationMode;
};
#endif