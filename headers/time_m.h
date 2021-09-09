#pragma once
#ifndef TIMEM_H
#define TIMEM_H

//class Time {
//    static float lastFrame;
//
//public:
//    static float deltaTime;	// time between current frame and last frame
//
//     
//
//    Time() = delete;
//};

namespace Time {
    float deltaTime;

    float DeltaTime();
}

#endif