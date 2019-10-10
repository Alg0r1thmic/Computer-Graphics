#ifndef CIRCLE_H
#define CIRCLE_H}
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <algorithm>

class screenPt
{
private:
    GLint x, y;
public:
    /* Constructor predeterminado: inicializa las coordenadas a (0, 0). */
    screenPt ( ) {
        x = y = 0;
    }
    void setCoords (GLint xCoordValue, GLint yCoordValue) {
        x = xCoordValue;
        y = yCoordValue;
    }
    GLint getx ( ) const {
        return x;
    }
    GLint gety ( ) const {
        return y;
    }
    void incrementx ( ) {
        x++;
    }
    void decrementy ( ) {
        y--;
    }
};
inline void setPixel (GLint xCoord, GLint yCoord)
{
    glBegin (GL_POINTS);
        glVertex2i (xCoord, yCoord);
    glEnd ( );
}
inline void circlePlotPoints (GLint xc, GLint yc,screenPt circPt)
{
    setPixel (xc + circPt.getx ( ), yc+circPt.gety());
    setPixel (xc - circPt.getx ( ), yc+circPt.gety());
    setPixel (xc + circPt.getx ( ), yc-circPt.gety());
    setPixel (xc - circPt.getx ( ), yc-circPt.gety());
    setPixel (xc + circPt.gety ( ), yc+circPt.getx());
    setPixel (xc - circPt.gety ( ), yc+circPt.getx());
    setPixel (xc + circPt.gety ( ), yc-circPt.getx());
    setPixel (xc - circPt.gety ( ), yc-circPt.getx());
}
inline void circleMidpoint (GLint xc, GLint yc, GLint radius)
{
    screenPt circPt;

    GLint p = 1 - radius;
    // Valor inicial para el parámetro de punto medio.
    circPt.setCoords (0, radius); // Establecer coordenadas para
    // punto superior del círculo.
    void circlePlotPoints (GLint, GLint, screenPt);
    /* Dibujar el punto inicial en cada cuadrante del círculo. */
    circlePlotPoints (xc, yc, circPt);
    /* Calcular el siguiente punto y dibujarlo en cada octante. */
    while (circPt.getx ( ) < circPt.gety ( )) {
        circPt.incrementx ( );
        if (p < 0)
            p += 2 * circPt.getx ( ) + 1;
        else {
            circPt.decrementy ( );
            p += 2 * (circPt.getx ( ) - circPt.gety ( )) + 1;
        }
        circlePlotPoints (xc, yc, circPt);
    }
}

#endif // CIRCLE_H
