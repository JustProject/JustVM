# Then JustVM Open Source Project (JuVMOSP)

Our goal is to **MAKE JVM SLOW AGAIN**!

## Development
Welcome, my dearest developer!
We've been looking forward for new contributors for a while, I mean, really a while.  
You contribution can be extremely important for all of us.

Here's our environment configuration recommendations:  
1. Ubuntu >=15.10 LTS  
2. GCC(Gnu Compiler Collection, include gcc/g++/make) >=6.0  
3. Boost Library >=1.61  
4. CMake >=3.5.2  
5. [Optional] CLion IDE >=2016.1  

The first four of the above list is necessary for the build progress.
Although IDE is not necessary for your development, but we extremely recommend you try it.

### Environmental Configuration
If you haven't got required libraries, here's how you do that: 
(We assume that you're using Ubuntu and was connected to the Internet)  
1. Ubuntu:  
[Ubuntu Organization](http://www.ubuntu.com/)
Follow the instructions on the site and you can get the OS.  
2. GCC:  
``sudo apt-get install gcc``  
3. Boost:  
``sudo apt-get install libboost-all-dev``  
4. CMake:  
``sudo apt-get install cmake``  
And also, the apt source may not contain the latest version of CMake, 
if you do encountered this situation, we recommend you go to 
[CMake](https://www.cmake.org/), where you may download the latest release and build/install it
on your own machine, for further information and instruction about CMake, 
please contact one of our developers at email.
5. CLion IDE:  
[JetBrains CLion IDE](http://www.jetbrains.com/clion/)  
You may already noticed that CLion IDE is a commercial-plan-only software, 
so you may want to make a purchase to JetBrains and get its license.

### Build - Plan I - CLI
```
mkdir build
cd build
cmake ..
make
```

### Build - Plan II - Clion
Choose ``File -> Open...`` from the menu, and choose ``CMakeLists.txt``
in the project root directory, then click OK.  
After open the project, you may choose ``Run -> Build`` or press keyboard 
shortcut ``Ctrl+F9``/``control+F9``, then the building process will be 
initiated automatically.

## Contact Developers
Yoto Chang - yotochang@gmail.com - @zhangyutng926 (Twitter&Telegram)
