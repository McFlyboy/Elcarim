# Elcarim
This is an arcade bullet-hell game based on the gameplay of *Touhou 01: The Highly Responsive to Prayers* (Zun Soft, 1996),
and is being developed from scratch in C++ for Windows, Mac and Linux.

## The tech
The graphics runs on OpenGL with custom shaders in GLSL, through a cross-platform windowing system called
[GLFW](https://github.com/glfw/glfw). Keyboard input and gamepad (XBOX/PS4 controller) input is also taken care of by GLFW.
The code utilizes [GLM](https://glm.g-truc.net/0.9.9/index.html) as it's primary
math library, and uses [STB Image](https://github.com/nothings/stb/blob/master/stb_image.h) for loading PNG-files.
When audio is implemented later it will either be through OpenAL or OpenAL Soft.

## Old version
This project is a re-creation of a project I did in
Java a back in 2016-2018 called [Project 1996](https://github.com/McFlyboy/Project-1996). That version is still playable and can
be found here: https://mcflyboy.itch.io/project1996 (Windows only)
