Реализованы классы:

- Point — базовый класс (координаты, перемещение)
- Krug — круг (наследуется от Point)
- Ring — кольцо (наследуется от Krug)


Для выполнения программы необходимо:
- Установленный компилятор C++ (g++)
- Установленная библиотека SFML(`pacman -S mingw-w64-ucrt-x86_64-sfml`)

Пример команды сборки:

`g++ main.cpp -o app -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system`