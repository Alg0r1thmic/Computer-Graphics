# Este trabajado fue desarrollado usando OpenGl y Qtcreator
## Modelo Uml
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/model1.png)

## Generacion de linea
Para generar se usa el algoritmo de bresenham en el libro Gráficos por computadora
con OpenGL solo es para los casos en que la pendiente sea <1,por eso para generar una linea con cualquier pendiente se usa el siguiente codigo
```
        int dx = abs(x1 - x0);
        int dy = abs(y1 - y0);

        if (dx >= dy)
            this->lineBresenhamX(x0, y0, x1, y1, dx, dy);
        else
            this->lineBresenhamY(x0, y0, x1, y1, dx, dy);
   
```
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/line/line.gif)
## Generacion de linea3D
En este caso tambien se esta usando tambien el algoritmo de bresenham

```
Ingrese los dos puntos finales y almacene el punto inicial como $(x_ {0}, y_ {0}, z_ {0})$
Calcule las constantes dx, dy, dzy determine el eje impulsor comparando
los valores absolutos de dx, dy, dz
Si abs ( dx) es máximo, entonces el eje X es el eje impulsor
Si abs ( dy) es máximo, entonces el eje Y es el eje impulsor
Si abs ( dz) es máximo, entonces el eje Z es el eje motor
Supongamos que el eje X es el eje conductor, entonces
 py_ {0} = 2dy - dx \\ pz_ {0} = 2dz - dx 
En cada uno a lo x_ {k}largo de la línea, comenzando en k = 0, verifique las siguientes condiciones
y determine el siguiente punto:
Si py_ {k} <0Y pz_ {k} <0, entonces
trazar (x_ {k} +1, y_ {k}, z_ {k})y
establecerpy_ {k + 1} = py_ {k} + 2dy, pz_ {k + 1} = pz_ {k} + 2dz
De lo contrario, si py_ {k}> 0Y pz_ {k} <0, entonces
trazar (x_ {k} +1, y_ {k} +1, z_ {k})y
establecerpy_ {k + 1} = py_ {k} + 2dy-2dx, pz_ {k + 1} = pz_ {k} + 2dz
Si no py_ {k} 0,
trazar (x_ {k} +1, y_ {k}, z_ {k} +1)y
establecerpy_ {k + 1} = py_ {k} + 2dy, pz_ {k + 1} = pz_ {k} + 2dz-2dx
De lo contrario,
trazar (x_ {k} +1, y_ {k} +1, z_ {k} +1)y
establecer py_ {k + 1} = py_ {k} + 2dy-2dx, pz_ {k + 1} = pz_ {k} + 2dz-2dx>
Repita el paso 5 dx-1veces

```
pero como una linea solo esta en dos dimensiones z=0
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/line3d/line3d.gif)

## Generacion de Circulo
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/circle/circle.gif)

## Generacion de Elipse
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/ellipse/ellipse.gif)

## Generacion de Poligono
### Vertices del poligono
```
  v1=(50,190)
  v2=(50,290)
  v3=(270,290)
  v4=(270,190)
```
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/polygon.png)
### Escalar poligono
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/scale/polygonScale.gif)

### Rotar poligono
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/rotate/polygonRotate.gif)

### Trasladar poligono
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/translate/polygonTranslate.gif)
