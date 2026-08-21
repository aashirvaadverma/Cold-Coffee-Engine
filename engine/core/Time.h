#pragma once

class Time
{
public:
    static void Initialize();
    static void Update();

    static float GetDeltaTime();

private:
    static float s_DeltaTime;
    static unsigned long long s_LastTime;
};