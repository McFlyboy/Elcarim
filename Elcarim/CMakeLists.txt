add_executable(Elcarim "src/Background.cpp" "src/Background.hpp" "src/Ball.cpp" "src/Ball.hpp" "src/BeingHitComponent.cpp" "src/BeingHitComponent.hpp" "src/Camera.cpp" "src/Camera.hpp" "src/ColliderComponent.cpp" "src/ColliderComponent.hpp" "src/Color.hpp" "src/Color3.cpp" "src/Color3.hpp" "src/Color4.cpp" "src/Color4.hpp" "src/Component.cpp" "src/Component.hpp" "src/Controls.cpp" "src/Controls.hpp" "src/DeltaTimer.cpp" "src/DeltaTimer.hpp" "src/ErrorHandler.cpp" "src/ErrorHandler.hpp" "src/Game.cpp" "src/Game.hpp" "src/GameControls.cpp" "src/GameControls.hpp" "src/GameObject.cpp" "src/GameObject.hpp" "src/Gamepad.cpp" "src/Gamepad.hpp" "src/GameScene.cpp" "src/GameScene.hpp" "src/HittingComponent.cpp" "src/HittingComponent.hpp" "src/JumpingComponent.cpp" "src/JumpingComponent.hpp" "src/Keyboard.cpp" "src/Keyboard.hpp" "src/Launcher.cpp" "src/Math.cpp" "src/Math.hpp" "src/Model.cpp" "src/Model.hpp" "src/Models.cpp" "src/Models.hpp" "src/Mouse.cpp" "src/Mouse.hpp" "src/MovementComponent.cpp" "src/MovementComponent.hpp" "src/Niam.cpp" "src/Niam.hpp" "src/Renderer.cpp" "src/Renderer.hpp" "src/ResourceLoader.cpp" "src/ResourceLoader.hpp" "src/Scene.cpp" "src/Scene.hpp" "src/SceneManager.cpp" "src/SceneManager.hpp" "src/Shader.cpp" "src/Shader.hpp" "src/ShaderProgram.cpp" "src/ShaderProgram.hpp" "src/Shot.cpp" "src/Shot.hpp" "src/Texture.cpp" "src/Texture.hpp" "src/TexturedModelComponent.cpp" "src/TexturedModelComponent.hpp" "src/Timer.cpp" "src/Timer.hpp" "src/TransformationComponent.cpp" "src/TransformationComponent.hpp" "src/Window.cpp" "src/Window.hpp")

set_property(TARGET Elcarim PROPERTY CXX_STANDARD 20)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(Elcarim PRIVATE glfw)

find_package(glm CONFIG REQUIRED)
target_link_libraries(Elcarim PRIVATE glm::glm)

find_package(glad CONFIG REQUIRED)
target_link_libraries(Elcarim PRIVATE glad::glad)

find_path(STB_INCLUDE_DIRS "stb.h")
target_include_directories(Elcarim PRIVATE ${STB_INCLUDE_DIRS})

add_custom_command(
	TARGET Elcarim POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_SOURCE_DIR}/assets ${CMAKE_CURRENT_BINARY_DIR}/assets
)
