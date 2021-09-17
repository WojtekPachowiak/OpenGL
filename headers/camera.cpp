#include "camera.h"
#include "globals.h"
#include "time_m.h"
#include "Input.h"
#include "window.h"

// Defines several possible options for camera movement. Used as abstraction to stay away from window-system specific input methods
enum CameraInput
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT,
    SPEED_UP
};


enum Navigation
{
    FLY,
    MOUSE_DRAG,
    DISABLED
};


// Default camera values
const float YAW = -90.0f;
const float PITCH = 0.0f;
const float SPEED = 2.5f;
const float SPEED_BOOST_MULT = 3.0f;
const float SENSITIVITY = 0.1f;
const float ZOOM = 45.0f;


//set mouse position to centre of the screen
float lastX = (float)g::SCR_WIDTH / 2.0;
float lastY = (float)g::SCR_HEIGHT / 2.0;
//mouse movement was just enabled
bool firstMouse = true;



// constructor with vectors
Camera::Camera(glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f), float yaw = YAW, float pitch = PITCH)
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), navigationMode(FLY)
{
    Position = position;
    WorldUp = up;
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}


// constructor with scalar values
Camera::Camera(float posX, float posY, float posZ, float upX, float upY, float upZ, float yaw, float pitch) 
    : Front(glm::vec3(0.0f, 0.0f, -1.0f)), MovementSpeed(SPEED), MouseSensitivity(SENSITIVITY), Zoom(ZOOM), navigationMode(FLY)
{
    Position = glm::vec3(posX, posY, posZ);
    WorldUp = glm::vec3(upX, upY, upZ);
    Yaw = yaw;
    Pitch = pitch;
    updateCameraVectors();
}


// returns the view matrix calculated using Euler Angles and the LookAt Matrix
glm::mat4 Camera::GetViewMatrix()
{
    return glm::lookAt(Position, Position + Front, Up);
}



// processes input received from any keyboard-like input system. Accepts input parameter in the form of camera defined ENUM (to abstract it from windowing systems)
void Camera::ProcessKeyboardAndMove()
{
    using namespace Input::Keys;

    float velocity = MovementSpeed * Time::deltaTime;
    
    if (Input::IsPressed(LSHIFT)) velocity *= SPEED_BOOST_MULT;
    if (Input::IsPressed(W)) Position += Front * velocity;
    if (Input::IsPressed(S)) Position -= Front * velocity;
    if (Input::IsPressed(A)) Position -= Right * velocity;
    if (Input::IsPressed(D)) Position += Right * velocity;
}


// processes input received from a mouse input system. Expects the offset value in both the x and y direction.
void Camera::ProcessMouseMovement(float xpos, float ypos, GLboolean constrainPitch = true)
{
    //if the mouse movement was just enabled, don't calculate mouse movement
    if (firstMouse) {
        lastX = xpos;
        lastY = ypos;
        firstMouse = false;
        return;
    }

    float xoffset;
    float yoffset;

    xoffset = xpos - lastX;
    yoffset = lastY - ypos;
    lastX = xpos;
    lastY = ypos;
    
    using namespace Input::Keys;

    //if the mouse movement was just enabled, don't calculate mouse movement

    if (navigationMode == FLY) {
        xoffset *= MouseSensitivity;
        yoffset *= MouseSensitivity;

        Yaw += xoffset;
        Pitch += yoffset;

        // make sure that when pitch is out of bounds, screen doesn't get flipped
        if (constrainPitch)
        {
            if (Pitch > 89.0f)
                Pitch = 89.0f;
            if (Pitch < -89.0f)
                Pitch = -89.0f;
        }
    }
    else if (navigationMode == MOUSE_DRAG) {
        if (Input::IsPressed(MOUSE1)) {
            glm::vec3 origin = glm::vec3(0.0, 0.0, 0.0);
            glm::vec3 x = Position - origin;
            glm::mat4 trans = glm::mat4(1.0f);
            trans = glm::rotate(trans, xoffset, Up);
            Position = glm::vec3(trans * glm::vec4(x,1.0)) + origin;

        }
    }

    // update Front, Right and Up Vectors using the updated Euler angles
    updateCameraVectors();
}


// processes input received from a mouse scroll-wheel event. Only requires input on the vertical wheel-axis
void Camera::ProcessMouseScroll(float yoffset)
{
    Zoom -= (float)yoffset;
    if (Zoom < 1.0f)
        Zoom = 1.0f;
    if (Zoom > 45.0f)
        Zoom = 45.0f;
}


    // calculates the front vector from the Camera's (updated) Euler Angles
void Camera::updateCameraVectors()
{
    // calculate the new Front vector
    glm::vec3 front;
    front.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    front.y = sin(glm::radians(Pitch));
    front.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
    Front = glm::normalize(front);
    // also re-calculate the Right and Up vector
    Right = glm::normalize(glm::cross(Front, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
    Up = glm::normalize(glm::cross(Right, Front));
}

