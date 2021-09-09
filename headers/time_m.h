#pragma once
#ifndef TIMEM_H
#define TIMEM_H

class Time {
    static float lastFrame;

public:
    static float deltaTime;	// time between current frame and last frame

    static float DeltaTime() {
        // per-frame time logic
        float currentFrame = glfwGetTime();
        Time::deltaTime = currentFrame - Time::lastFrame;
        Time::lastFrame = currentFrame;
        return Time::deltaTime;
    }

    Time() = delete;
};

#endif