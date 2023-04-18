# miniRT

![image](https://user-images.githubusercontent.com/69059969/232882789-5e322231-94a0-480f-8e48-296a695243fe.png)

* [Overview](https://github.com/gabrielclcardoso/minibash/edit/master/README.md#project-overview)
* [Approach](https://github.com/gabrielclcardoso/minibash/edit/master/README.md#project-approach)
* [Extra features](https://github.com/raytracers/miniRT/edit/103-create-readme/README.md#extra-featurees)
* [Running the ray tracer](https://github.com/raytracers/miniRT/edit/103-create-readme/README.md#running-the-ray-tracer)

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
In this project, we started by studying the ray tracing render technique and understanding how it works. After a couple of days of research we had a good overview of what the project was going to need and how it would develop. That's when we took the decision to adopt a pretty linear approach to our development of the project which followed these steps:
* Validate program parameters;
* Construct the types that would hold information about the scene, window and objects;
* Build the .rt file content validation;
* Rotate and translate scene objects to align camera with the z axis;
* Cast ray for each pixel on the screen;
* Get closest intersection for each of the pixel rays;
* Color these intersections accordingly.

#### Validate program parameters:
This is the simplest of the development bullet points. It consists simply of validating the argc and argv parameters to check if the program was ran with the expected parameters.

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

#### Objects rotation and translation
In order to simplify the camera ray generation we can position the camera at the origin and align it with the z axis, that way we only need to consider the x and y axis when computing the ray origin. In our program we decided to align the camera along the negative z axis and this was achieved by multiplying every positional vector in the scene by a view transformation matrix that translated and rotated the vector accordingly and multiplying every normal/direction vector by the rotation component of the view transformation matrix.

#### Camera rays generation
To generate the camera rays we would:

1. Consider the screen as a 1 by 1 square with it's center on the camera origin;
2. Distort this square accordingly to consider the camera's FOV and the window's aspect ratio;
3. Generate rays that have their origins 1 unit behind the camera's origin along the z axis and pass in the center of their respective pixel;
4. Move the origin of these rays to their respective pixel coordinates.

#### Get closest intersections for each camera ray
To get the closest intersection for each of the camera rays we check it's collision with every object in the scene and calculate their distance.  Afterwards, if any intersection exists, we pick the one with the lowest positive distance.

#### Intersection coloring
To color the intersections we first factor in if that intersection exists, if it doesn't exist we color the corresponding pixel black, otherwise we calculate it's color.

To calculate the color of the intersections that exist we cast a ray from the intersection to the light spot origin. If the ray reaches the light spot without intersecting we compute the diffuse and specular light components for that pixel and add them together with the ambient light component. If the ray doesn't reach the light spot, only the ambient light component of the pixel color is taken into account which results in a darker spot.

#

### Extra Featurees
During the development of the project we decided to add 2 extra features to the project.
1. Interactive mode
2. Terminal log
#### 1. Interactive mode
We decided to add an interactive mode as a way to interact with the scene in a more natural way. This was accomplished by creating a cheap render function,
which does not take into account lighting, only intersections. When you enter interactive mode you will be able to move the camera position arrounde the scene with the instructions printed on the screen.

The camera movement is obtained via the view transformation matrix and rotation matrix used in the beggining of the program to put the camera at the origin and align it with the z axis, only this time the camera will not be translated or rotated but everything arround it. This gives the impression that the camera is moving arround when in fact it's the whole scene thats moving arround it.
#### 2. Terminal log
This feature is meant to give some feedback to the user while he is running the program. It displays what the program is doing and when the scene is rendered it also displays the time that it took to render it.

#

### Running the ray tracer
##### Platforms supported: Linux and Macos.
To try it out follow these simple steps:

1 Clone this repository wherever you like:

```
git clone https://github.com/raytracers/miniRT
```
2 Enter the cloned repository and run make inside it:
```
cd miniRT && make
```
3 Run the miniRT executable with any of the scenes inside the scenes directory or with your own built scene
```
./miniRT scenes/cool_spheres.rt
```
