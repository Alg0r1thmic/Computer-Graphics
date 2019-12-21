#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H
#include<QOpenGLWidget>
#include<QOpenGLFunctions>
#include <algorithm>
#include "Shape.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;
class wcPt3D {
public:
    GLfloat x, y, z;
};
class BezierCurve:public Shape
{
public:
    BezierCurve(){
        //glClearColor (1.0, 1.0, 1.0, 0.0);
    }
    void plotPoint (wcPt3D bezCurvePt)
    {
        setPixelf(bezCurvePt.x, bezCurvePt.y);

    }
    void binomialCoeffs (GLint n, GLint * C)
    {
        GLint k, j;

        for (k =0; k <= n; k++) {
            /* Compute n!/(k!(n - k)!). */
            C [k] = 1;
            for (j = n; j >= k + 1; j--)
                C [k] *= j;
            for (j = n - k; j >= 2; j--)
                C [k] /= j;
        }
    }
    void computeBezPt (GLfloat u, wcPt3D * bezPt, GLint nCtrlPts,vector<wcPt3D>  ctrlPts, GLint * C)
    {
        GLint k, n = nCtrlPts - 1;
        GLfloat bezBlendFcn;
        bezPt->x = bezPt->y = bezPt->z = 0.0;
        for (k = 0; k < nCtrlPts; k++) {
            bezBlendFcn = C [k] * pow (u, k) * pow (1 - u, n - k);
            bezPt->x += ctrlPts[k].x * bezBlendFcn;
            bezPt->y += ctrlPts[k].y * bezBlendFcn;
            bezPt->z += ctrlPts[k].z * bezBlendFcn;
        }
    }
    void bezier (vector<wcPt3D> ctrlPts, GLint nCtrlPts, GLint nBezCurvePts)
    {
        wcPt3D bezCurvePt;
        GLfloat u;
        GLint *C, k;
        C=new GLint[nCtrlPts];
        binomialCoeffs (nCtrlPts - 1, C);
        for (k = 0; k <= nBezCurvePts; k++) {
            u = GLfloat (k) / GLfloat (nBezCurvePts);
            computeBezPt (u, &bezCurvePt, nCtrlPts, ctrlPts, C);
            plotPoint (bezCurvePt);
        }
        delete [ ] C;
    }
};

#endif // BEZIERCURVE_H
