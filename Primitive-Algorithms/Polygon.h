#ifndef POLYGON_H
#define POLYGON_H
#include "Line.h"
#include <cmath>
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <algorithm>
class wcPt2D {
public:
    GLfloat x, y;
};
class Polygon:public Line
{
public:
    Polygon() {
    }
    void translatePolygon (wcPt2D * verts, GLint nVerts, GLfloat tx, GLfloat ty)
    {
        GLint k;
        for (k = 0; k < nVerts; k++) {
            verts [k].x = verts [k].x + tx;
            verts [k].y = verts [k].y + ty;
        }
        glBegin (GL_POLYGON);
        for (k = 0; k < nVerts; k++)
            glVertex2f (verts [k].x, verts [k].y);
        glEnd ( );
    }
    void rotatePolygon (wcPt2D * verts, GLint nVerts, wcPt2D pivPt,GLdouble theta)
    {
        wcPt2D * vertsRot=new wcPt2D[nVerts];
        GLint k;
        for (k = 0; k < nVerts; k++) {
            vertsRot [k].x = pivPt.x + (verts [k].x-pivPt.x)*cos(theta)
                                    - (verts [k].y-pivPt.y)*sin(theta);
            vertsRot [k].y = pivPt.y + (verts [k].x-pivPt.x)*sin(theta)
                                    + (verts [k].y-pivPt.y)*cos(theta);
        }

        glBegin(GL_POLYGON);
            for (k = 0; k < nVerts; k++)
            glVertex2f (vertsRot [k].x, vertsRot[k].y);
        glEnd();
    }
    void scalePolygon (wcPt2D * verts, GLint nVerts, wcPt2D fixedPt,
                       GLfloat sx, GLfloat sy)
    {
        wcPt2D *vertsNew=new wcPt2D[nVerts];
        GLint k;
        for (k = 0; k < nVerts; k++) {
            vertsNew[k].x = verts [k].x * sx + fixedPt.x * (1 - sx);
            vertsNew[k].y = verts [k].y * sy + fixedPt.y * (1 - sy);
        }
        glBegin(GL_POLYGON);
            for (k = 0; k < nVerts; k++)
                glVertex2f (vertsNew[k].x, vertsNew[k].y);
        glEnd();
    }
private:
    //wcPt2D *points;
};
#endif // POLYGON_H
