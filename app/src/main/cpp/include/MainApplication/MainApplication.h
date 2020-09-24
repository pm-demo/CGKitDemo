/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2020. All rights reserved.
 * Description: A sample that illustrates the rendering of a triangle.
 */

#ifndef MAIN_APPLICATION_H
#define MAIN_APPLICATION_H

#define CGKIT_LOG
#include "Application/CGKitHeaders.h"

using namespace CGKit;

enum TouchCountNum {
    TOUCH_COUNT_MOVE = 1,
    TOUCH_COUNT_ZOOM,
    TOUCH_COUNT_MULTI_FINGER,
    TOUCH_COUNT_MAX = TOUCH_COUNT_MULTI_FINGER
};

class MainApplication : public BaseApplication
{
public:
    MainApplication();
    virtual ~MainApplication();
    virtual void Start(void* param);
    virtual void Initialize(void* winHandle, u32 width, u32 height);
    virtual void UnInitialize();
    virtual void InitScene();
    virtual void Update(float deltaTime);
    virtual void Resize(u32 width, u32 height);
    virtual void ProcessInputEvent(const InputEvent* inputEvent);

private:
    SceneObject* CreateSkybox();

private:
    bool m_touchBegin;
    float m_touchPosX;
    float m_touchPosY;
    float m_deltaTime;
    float m_deltaAccumulate = 0.0f;
    float m_objectRotation = 0.0f;
    float m_objectScale = 1.0f;
//   const Vector3 SCENE_OBJECT_POSITION = Vector3(0.0f, -18.0f, 40.0f);
//p   const Vector3 SCENE_OBJECT_SCALE = Vector3(30.f, 30.f, 30.f);
    // adjust scale and position as per model
    const Vector3 SCENE_OBJECT_POSITION = Vector3(2.5f, 0.0f, 40.0f); // wind mill
    const Vector3 SCENE_OBJECT_SCALE = Vector3(0.25f, 0.25f, 0.25f);  // wind mill
// black_smith    const Vector3 SCENE_OBJECT_POSITION = Vector3(0.0f, 0.0f, 40.0f);
// black_smith    const Vector3 SCENE_OBJECT_SCALE = Vector3(10.f, 10.f, 10.f);
    SceneObject* m_sceneObject = nullptr;
    SceneObject* m_pointLightObject = nullptr;
    String m_envMap = "cubemaps/env/cubemap.cub";
};

BaseApplication* CreateMainApplication();

#endif