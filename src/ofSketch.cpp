// Copyright 2019 Aris Bezas
#include "ofApp.h"
#include "ofSketch.h"

void ofSketch::init(float elast, float aposv) {
  for (int i = 0; i < stoixeia; i++) {
    elastikotita[i] = (elast)*(.07*(i+1));  // 0.05  kai 0.005
    aposbesi[i] = aposv-(0.02 *i);
  }
}

void ofSketch::draw(int x, int y, int z, int r, int g, int b, int a) {
  ofNoFill();
  ofSetColor(r, g, b, a);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  glBegin(GL_POINTS);
  for (int i = 0; i < stoixeia; i++) {
    if (i == 0) {
      deltaX[i] = (x - xi[i]);
      deltaY[i] = (y - yi[i]);
      deltaZ[i] = (z - zi[i]);
    } else {
      deltaX[i] = (xi[i-1]-xi[i]);
      deltaY[i] = (yi[i-1]-yi[i]);
      deltaZ[i] = (zi[i-1]-zi[i]);
    }
    deltaX[i] *= elastikotita[i];
    deltaY[i] *= elastikotita[i];
    deltaZ[i] *= elastikotita[i];
    epitaxinsiX[i] += deltaX[i];
    epitaxinsiY[i] += deltaY[i];
    epitaxinsiZ[i] += deltaZ[i];
    xi[i] += epitaxinsiX[i];
    yi[i] += epitaxinsiY[i];
    zi[i] += epitaxinsiZ[i];
    my3d.x = xi[i];
    my3d.y = yi[i];
    my3d.z = z;
    glVertex3f(my3d.x, my3d.y, my3d.z);
    epitaxinsiX[i] *= aposbesi[i];    // slow down elastikotita
    epitaxinsiY[i] *= aposbesi[i];
    epitaxinsiZ[i] *= aposbesi[i];
  }
  glEnd();
}












































