#pragma once

#include <string>
#include <format>
#include <iostream>

#include "GLFW/glfw3.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "system_clock.hpp"
#include "Editor.hpp"

namespace ui
{
    struct IdleState
    {
        bool is_idle = false;
        double idle_timer = 0.0f;
    };

    class App
    {
    public:
        App() = default;
        ~App();
        bool init(const char* title, int width, int height);
        void run();
    
    private:
        GLFWwindow* m_window = nullptr;
        IdleState m_idle_state;
        internal::SystemClock m_system_clock;
        Editor m_editor;
        bool m_init_dock = true;

        void set_imgui_config();
        void set_imgui_style();
        void poll_events();
    };
} // namespace ui
