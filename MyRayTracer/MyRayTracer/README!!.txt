VISUAl STUDIO PROJECT;

mocht de code niet compilen voer dan de onderstaande uit:

1)
Project>Properties>Linker>Input>Additional Dependencies.
voer dit in.

opengl32.lib;SDL2.lib;SDL2main.lib;

2)
Project>Properties>Linker>General>Additional Library Directories.
voeg de locatie van de onderstaande folder toe.

C:\Users\Raber\Desktop\cpp-eindopdracht\MyRayTracer\libs\glm-0.9.6.3
C:\Users\Raber\Desktop\cpp-eindopdracht\MyRayTracer\libs\SDL2-2.0.4\lib\x86

3)
Project>Properties>C/C++>General>Additional Include Directories.
voeg de locatie van de onderstaande folder toe.

C:\Users\Raber\Desktop\cpp-eindopdracht\MyRayTracer\libs\SDL2-2.0.4\lib\x86
C:\Users\Raber\Desktop\cpp-eindopdracht\MyRayTracer\libs\glm-0.9.6.3
C:\Users\Raber\Desktop\cpp-eindopdracht\MyRayTracer\libs\SDL2-2.0.4\include