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
For the file validation, we read it's contents line by line and loaded it's contents to
