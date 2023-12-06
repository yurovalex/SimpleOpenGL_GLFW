# SimpleOpenGL_GLFW
Простой пример по работе с OpenGL с подключением библиотек: GLFW, ImGui, Spdlog, GLM. Генератор сборки CMake.
#ENG Before use, go to the "external" folder and start the command line mode (terminal). In the terminal run ./install_external.sh and wait until all components are installed.

Building the application over the terminal (konsole KDE X11): mkdir build cd build cmake -G Ninja .. ninja

and after to run application ./RunExample

Простой пример по работе с OpenGL с подключением библиотек: GLFW, ImGui, Spdlog, GLM. Генератор сборки CMake.

#RUS Перед использованием зайти в папку "external" и запустить режим командной строки (терминал). В терминале запустить ./install_external.sh и подождать, пока все компоненты не будут установлены.

Сборка приложения через терминал: mkdir build cd build cmake -G Ninja .. ninja

После сборки перейти в папку Sources и запустить приложение ./RunExample

Результаты работы приложения в Linux Manjaro показаны на рис.1.
![изображение](https://github.com/yurovalex/SimpleOpenGL_GLFW/assets/104449428/c25d2540-cd79-49ef-80ee-0517b7ec31da)


          Рисунок 1 - Окно GLFW, диалоговое окно ImGui, построение двух фигур
