# miniRT
### Project overview:
This project consists of coding a simple ray tracer in C. The program will read a .rt file, interpret it's contents and render the scene on the screen.

The project was developed by [me](https://www.linkedin.com/in/gabrielclcardoso/) and [Leonardo Farias](https://www.linkedin.com/in/leofariasrj25/).

#### Features that will be implemented:
* Rendering of basic shapes: Cylinders, spheres, planes and cones;
* Presence of a single light spot;
* Optional presence of an ambient light;
* Diffuse lighting;
* Specular lighting;
* Ambient lighting;
* Colored lighting.

#
### Project approach:
In this project, we started by studying the ray tracing render technique and understanding how it works. After a couple of days of research we had a good overview of what the project was going to need and how it would develop. That's when we took the decision to adopt a pretty linear approach to our development of the project:
* Validate program parameters;
* Construct the types that would hold information about the scene, window and objects;
* Build the .rt file content validation;
* Rotate and translate scene objects to align camera with the z axis;
* Cast ray for each pixel on the screen;
* Get closest intersection for each of the pixel rays;
* Color these intersections accordingly.

#### Validate program parameters:
This is the simplest of the development bullet points. It consists simply of validating the argc and argv parameters to check if the program called with the expected parameters.

#### Type construction:
Here we took some important design decisions for the project.
- We created an `e_element` enum in order to add readability to the code and access arrays of pointers to functions through it;
- We declared a `u_object` union that could hold any of the structs that represented renderable elements in the scene;
- We defined the `t_scene` and the `t_window` structs that would hold information regarding the scene and the window respectively.

#### .rt file validation

For the file validation, we had to check if the file followed the following set of rules:
1. There must be a single camera in the .rt file that will be represented by the following line format: `C -50.0,0,20 0,0,1 70`
* `C` => Identifier
* `-50.0,0,20` => xyz coordinates
* `0,0,1` => Normalized direction vector
* `70` => FOV
2. There must be a single light spot in the .rt file that will be represented by the following line format: `L -40.0,50.0,0.0 0.6 10,0,255`
* `L` => Identifier
* `-40.0,50.0,0.0` => xyz coordinates
* `0.6` => Brightness in range \[0.0, 1.0\]
* `10,0,255` => RGB colors in range \[0, 255\] **(optional)**
3. There can be a single Ambient light in the .rt file that will be represented by following line format: `A 0.2 255,255,255`
* `A` => Identfier
* `0.2` => Brightness in range \[0.0, 1.0\]
* `255,255,255` => RGB colors in range \[0, 255\]
4. There can be an arbitraty number of the following shapes on the scene
  
    4.1 Spheres, which will be represented by the following line format: `sp 0.0,0.0,20.6 12.6 10,0,255`
    * `sp` => Identifier
    * `0.0,0.0,20.6` => xyz coordinates
    * `12.6` => Diameter
    * `10,0,255` => RGB colors in range \[0, 255\]
    
    4.2 Planes, which will be represented by the following line format: `pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225`
    * `pl` => Identifier
    * `0.0,0.0,-10.0` => xyz coordinates
    * `0.0,1.0,0.0` => Normalized normal vector
    * `0,0,255` => RGB colors in range \[0, 255\]

    4.3 Cylinders, which will be represented by the following line format: `cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255`
    * `cy` => Identifier
    * `50.0,0.0,20.6` => xyz coordinates
    * `0.0,0.0,1.0` => Normalized direction vector
    * `14.2` => Diameter
    * `21.42` => Height
    * `10,0,255` => RGB colors in range \[0, 255\]
    
    4.4 Cones, which will be represented the same way as cylinders but with the `cn` identifier.

The attributes in each line can be separeted by an arbitrary number of space characters and each line can be separeted by an abitrary number of empty lines.

To validate the file we read it line by line initializing their respective elements and if an error is encoutered we free all the alocated resources and print an error message detailing the error encoutered.

