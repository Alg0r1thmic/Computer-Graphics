# Este trabajado fue desarrollado usando OpenGl y Qtcreator

## Modelo Uml
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/3DCamera-Control/images/model.png)

### la clase Input 
  Esta clase se encargara de administrar la entrada es decir capturar los eventos del movimiento del mouse,presion de teclas click del mouse 
### la clase Camera3D
uno de los  metodos mas importantes es 
```
  Camera3D :: toMatrix ().
```
Se encargara de crear una matriz invertida,Tambien estan 
```
forward (), right () y up ().
```
 Toman los vectores del sistema de coordenadas del objeto actual y los giran usando  QQuaternion
### la clase Window 
Esta clase usara clases como Camara3D,Tranform3d,input,vertex para crear una ventana de visualizacion

# Para la renderizacion 

Dado que la información de vértice (información que constituye una pieza de geometría) está definida por el usuario, Qt no proporciona una clase QVertex lista para usar. Para simplificar las cosas, vamos a hacer una clase que actuará como nuestra información de vértice

Los codigo de sombreador o shader que nesecitara esta clase estan definidas de la siguiente manera


shaders / simple.vert:

```
#version 330
in highp vec4 vColor;
out highp vec4 fColor;

void main()
{
   fColor = vColor;
}
```
shaders / simple.frag:

```
#version 330
layout(location = 1) in vec3 position;
layout(location = 1) in vec3 color;
out vec4 vColor;

uniform mat4 modelToWorld;
uniform mat4 worldToCamera;
uniform mat4 cameraToView;

void main()
{
  gl_Position = cameraToView * worldToCamera * modelToWorld * vec4(position, 1.0);
  vColor = vec4(color, 1.0);
}

```
## MoVimiento Rotario 
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/3DCamera-Control/images/rotate.gif)

## Movimiento con el mouse
![alt text](![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/3DCamera-Control/images/rotate.gif)



## Movimiento con la teclas 
```
A->derecha
D->izquierda
S->zoon (+)
W->zoon (-)
Q->abjo 
E->arriba
```
![alt text](![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/3DCamera-Control/images/moveWithKey.gif)

