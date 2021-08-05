# Little-Game-Engine-funciality-

C++ Scratch mini game engine With smfl 

having multiple states 
like
1. gamestate
2. mainmenu state
3. editor state


in Game state we have player


// resources 
buttons class

there is entity componenent system
1. entity class

// few components

1. under entity class
animation components
hitbox components
movement components



![image](https://user-images.githubusercontent.com/86443601/128161809-8ba96d83-8e22-4c0b-8ac9-a8e9cade7a0e.png)
![image](https://user-images.githubusercontent.com/86443601/128161863-6a10cfae-e741-43b2-9fb2-0a59f3550735.png)
![image](https://user-images.githubusercontent.com/86443601/128161911-896ad386-f3d0-4f86-b1ee-5509f8d4494e.png)
![image](https://user-images.githubusercontent.com/86443601/128161979-ee8f3b52-e2fe-4754-9ffb-5878d80628ed.png)
![image](https://user-images.githubusercontent.com/86443601/128162073-058e0b26-2d1f-4a86-9585-3fd4165decfe.png)





Installing SFML
First, you must download the SFML development files. You can download the minimal package (libraries + headers), but it is recommended that you download the full SDK, which contains the samples and documentation as well.
These packages can be found on the download page.

Once you have downloaded and extracted the files to your hard drive, you have to make the SFML headers and library files available to Visual C++. There are two ways of doing it:

Copy the SFML development files to your Visual Studio installation directory
Copy SFML-x.y\include\SFML to the VC\include directory of your Visual Studio installation (so that you obtain VC\include\SFML)
Copy the *.lib files in SFML-x.y\lib to the VC\lib directory of your Visual Studio installation
Leave the SFML files where you want, and setup Visual Studio so that it can find them
Go to the Tools / Options menu, then to Projects and Solutions / VC++ Directories
In Include files, add SFML-x.y\include
In Library files, add SFML-x.y\lib
Screenshot of the dialog box for setting up the include pathScreenshot of the dialog box for setting up the library path
Compiling your first SFML program
Create a new "Win32 console application" project, and write a SFML program. For example, you can try the sf::Clock class of the System package :

#include <SFML/System.hpp>
#include <iostream>

int main()
{
    sf::Clock Clock;
    while (Clock.GetElapsedTime() < 5.f)
    {
        std::cout << Clock.GetElapsedTime() << std::endl;
        sf::Sleep(0.5f);
    }

    return 0;
}
Don't forget that all SFML classes and functions are in the sf namespace.

Open your project's options, then go to the Linker / Input item. In the Additional dependencies row, add the SFML libraries you are using. Here we only use sfml-system.lib.
This is for the dynamic version of the libraries, the one using the DLLs. If you want to link with the static version of the libraries, add the "-s" suffix : sfml-system-s.lib, or sfml-system-s-d.lib for the debug version.

Important: for the Debug configuration, you have to link with the debug versions of the libraries, which have the "-d" suffix (sfml-system-d.lib in this case). If you don't, you may get undefined behaviours and crashes.

Screenshot of the dialog box for setting up the project's libraries
Your program should now compile, link and run fine. If you linked against the dynamic versions of the SFML libraries, donc forget to copy the corresponding DLLs (sfml-system.dll in this case) to your executable's directory, or to a directory contained in the PATH environment variable.

Important: if you link against the dynamic libraries, you have to define the SFML_DYNAMIC macro in your project's settings. If you don't, you'll get linker errors when compiling your application.

Screenshot of the dialog box for linking with dynamic libraries
If you are using the Audio package, you must also copy the DLLs of the external libraries needed by it, which are libsndfile-1.dll, and OpenAL32.dll.
These files can be found in the extlibs\bin directory of the package that you downloaded (SDK or development files).

Compiling SFML
If the precompiled SFML libraries don't exist for your system, or if you want to use the latest sources from SVN, you can compile SFML quite easily. In such case, no test have been made so you are encouraged to report any failure or success encountered during your compile process. If you succeed compiling SFML for a new platform, please contact the development team so that we can share the files with the community.

To compile SFML libraries and samples, you must first download and install the full SDK (or get the files from the SVN repository).

Go to SFML-x.y\build\vc2005 (or SFML-x.y\build\vc2008 if you're using VC++ 2008), and open the file SFML.sln. Choose the configuration you want to build (Debug or Release, Static or DLL), and clic "build". This should create the corresponding SFML libraries in the lib directory, as well as the samples executables.

If Qt and wxWidgets are not installed on your system, you may get compile errors with the corresponding samples ; just ignore them.
                                                        
                                                        
                                                        
                                                        https://www.sfml-dev.org/tutorials/1.6/images/start-vc-include-path.png
                                                        https://www.sfml-dev.org/tutorials/1.6/images/start-vc-lib-path.png
                                                        https://www.sfml-dev.org/tutorials/1.6/images/start-vc-project-link.png
                                                        https://www.sfml-dev.org/tutorials/1.6/images/start-vc-project-dynamic.png
