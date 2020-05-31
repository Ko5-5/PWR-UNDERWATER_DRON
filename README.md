# Simulation of an Underwater Drone

This is a project I completed, while studying at Wroclaw University of Technology, as a final assignment of Second Semester of Automation and Robotics.

# Brief overview

This program is an simple simulation of a Drone swimming/driving underwater. The drone is prezented simply as a cuboid moving between surface of the water and a surface of bottom of the reservoir. 

It's written in C++ and the simulation is rendered using Gnuplot.

Connection between the program and Gnuplot is being controlled by "Lacze do Gnuplota" written by dr. inz. Bogdan Kreczmer. 

# Key features

 - Rotation around OZ axis by an angle given by the user
 - Forward movement at an angle given by the user
 - Collision with the water and bottom surface
 - Animation of Drone's rotors while moving

# Compilation

To compile the program I'm using GNU Make, that uses a Makefile to manage the compilation.
To start, start this command in the "project" directory.

```sh
make
```

This command will start the compilation process, and then start the program.

# Menu and usage

After the start