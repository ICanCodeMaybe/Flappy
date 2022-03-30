#include <iostream>
#include <vector>

#include <glm/glm.hpp>

#include <Little.h>

#include <GLFW/glfw3.h>
#include "entity.h"

void OnEvent(lil::Event& e);
bool OnMouseButtonDown(lil::MouseButtonDownEvent& e);
bool OnKeyPressed(lil::KeyPressedEvent& e);
bool OnKeyRelease(lil::KeyReleasedEvent& e);

bool shouldClose = false;

lil::OrthoCamera cam(-1.0f, 1.0f, -1.0f, 1.0f);
glm::vec2 camPos = glm::vec2(0.0f);

bool Key_W = false,  Key_S = false,  Key_A = false, Key_D;

int main(){

    lil::Application::Get()->Init();

//window creation
    lil::WindowSpecs spec;
    spec.CallbackEventFn = OnEvent;
    
    lil::Window window;
    window.Create(spec);

    lil::Application::Get()->CreateOpenglContext(window);

    lil::Renderer::Get()->SetWindow(&window);

//shader

    Entity e({1.0f, 0.0f, 1.0f});
    e.SetPosition({2.0f, 2.0f});

    lil::Quad quad({0.1f, 0.5f, 0.7f}, {-1.0f, -1.0f});

    lil::Circle circle({1.0f, 1.0f, 0.0f});
    lil::Shader* mS = circle.GetShader();

    while(!shouldClose){
        lil::RendererCommand::Get()->SetClearColor({0.1f, 0.2f, 0.3f, 1.0f});
        lil::RendererCommand::Get()->Clear();

     //This input system is done realy wierdly, i'll have to work on it   
        if(Key_W == true)
            camPos.y += 0.1f;
        if(Key_S == true)
            camPos.y -= 0.1f;
        if(Key_D == true)
            camPos.x += 0.1f;
        if(Key_A == true)
            camPos.x -= 0.1f;

        //settting cameras's postition
        cam.SetPosition({camPos.x, camPos.y, 1.0f});

        //rendering
        lil::Renderer::Get()->BeginScene(&cam);


        lil::Renderer::Get()->DrawQuad(e);
        lil::Renderer::Get()->DrawCircle(circle);

        lil::Renderer::Get()->EndScene();

        window.HandleEvents();
        window.SwapBuffers();
    }
    return 0;
}

void OnEvent(lil::Event& e){
    e.LogIt();
    
    if(e.GetEventType() == lil::EventType::WindowClosed)
        shouldClose = true;

    lil::Dispatcher dispatcher(e);
    dispatcher.Dispatch<lil::KeyPressedEvent>(OnKeyPressed);
       dispatcher.Dispatch<lil::KeyReleasedEvent>(OnKeyRelease);
}

bool OnKeyPressed(lil::KeyPressedEvent& e){
    if(e.GetKeyCode() == GLFW_KEY_W)
        Key_W = true;
    if(e.GetKeyCode() == GLFW_KEY_S)
        Key_S = true; 
    if(e.GetKeyCode() == GLFW_KEY_A)
        Key_A = true;
    if(e.GetKeyCode() == GLFW_KEY_D)
        Key_D = true;

    return true;
}

bool OnKeyRelease(lil::KeyReleasedEvent& e){
    if(e.GetKeyCode() == GLFW_KEY_W)
        Key_W = false;
    if(e.GetKeyCode() == GLFW_KEY_S)
        Key_S = false; 
    if(e.GetKeyCode() == GLFW_KEY_A)
        Key_A = false;
    if(e.GetKeyCode() == GLFW_KEY_D)
        Key_D = false; 


    return true;
}