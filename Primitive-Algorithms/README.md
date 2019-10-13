# Este trabajado fue desarrollado usando OpenGl y Qtcreator
## Modelo Uml
![alt text]()

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
void lineBresenham3D(int x1,int y1,int z1,int x2,int y2,int z2){
        setPixel3D(x1,y1,z1);
        int xs,ys,zs,p1,p2;
        int dx = abs(x2 - x1);
        int dy = abs(y2 - y1);
        int dz = abs(z2 - z1);
        if (x2 > x1)
            xs = 1;
        else
            xs = -1;
        if (y2 > y1)
            ys = 1;
        else
            ys = -1;
        if (z2 > z1)
            zs = 1;
        else
            zs = -1;

        if (dx >= dy and dx >= dz){
            p1 = 2 * dy - dx ;
            p2 = 2 * dz - dx ;
            while (x1 != x2){
                x1 += xs;
                if (p1 >= 0){
                    y1 += ys ;
                    p1 -= 2 * dx ;
                }
                if (p2 >= 0){
                    z1 += zs;
                    p2 -= 2 * dx;
                }
                p1 += 2 * dy ;
                p2 += 2 * dz ;
                setPixel3D(x1,y1,z1);
            }
        }
        else if (dy >= dx and dy >= dz){
            p1 = 2 * dx - dy;
            p2 = 2 * dz - dy;
            while (y1 != y2){
                y1 += ys;
                if (p1 >= 0){
                    x1 += xs;
                    p1 -= 2 * dy;
                }
                if (p2 >= 0){
                    z1 += zs;
                    p2 -= 2 * dy;
                }
                p1 += 2 * dx;
                p2 += 2 * dz;
                setPixel3D(x1,y1,z1);
            }

        }
        else {
            p1 = 2 * dy - dz;
            p2 = 2 * dx - dz;
            while (z1 != z2){
                z1 += zs;
                if (p1 >= 0){
                    y1 += ys;
                    p1 -= 2 * dz;
                }
                if (p2 >= 0){
                    x1 += xs;
                    p2 -= 2 * dz;
                }
                p1 += 2 * dy;
                p2 += 2 * dx;
                setPixel3D(x1,y1,z1);
            }
        }
    }

```
pero como una linea solo esta en dos dimensiones z=0
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/line3d/line.gif)

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
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/scale/scalePolygon.gif)

### Rotar poligono
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/rotate/rotatePolygon.png)

### Trasladar poligono
![alt text](https://github.com/Alg0r1thmic/Computer-Graphics/blob/master/Primitive-Algorithms/Images/translate/translatePolygon.gif)
