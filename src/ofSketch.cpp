// Copyright 2019 Aris Bezas
#include "ofApp.h"
#include "ofSketch.h"

void ofSketch::init(int sketchID, float elast, float aposv) {
  for (int i = 0; i < stoixeia; i++) {
    elastikotita[i] = (elast)*(.07*(i+1));  // 0.05  kai 0.005
    aposbesi[i] = aposv-(0.02 *i);
  }
  for (int i = 0; i < stoixeiaMouse; i++) {
    elastikotitaMouse[i] = (elast)*(.05*(i+1));  // 0.05  kai 0.005
    aposbesiMouse[i] = aposv-(0.02 *i);
  }
}

void ofSketch::draw(int x, int y, int z,
                    int r, int g, int b, int a, float lines) {
  ofNoFill();
  ofSetColor(r, g, b, a);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);
  if (lines) {
    glBegin(GL_POINTS);
  } else {
    glBegin(GL_POINTS);  // GL_LINE_LOOP
  }
  for (int i = 0; i < stoixeiaMouse; i++) {
    if (a != 0) {
      if (i == 0) {
        deltaXMouse[i] = (x - xiMouse[i]);
        deltaYMouse[i] = (y - yiMouse[i]);
        deltaZMouse[i] = (z - ziMouse[i]);
      } else {
        deltaXMouse[i] = (xiMouse[i-1]-xiMouse[i]);
        deltaYMouse[i] = (yiMouse[i-1]-yiMouse[i]);
        deltaZMouse[i] = (ziMouse[i-1]-ziMouse[i]);
      }
      deltaXMouse[i] *= elastikotitaMouse[i];
      deltaYMouse[i] *= elastikotitaMouse[i];
      deltaZMouse[i] *= elastikotitaMouse[i];
      epitaxinsiXMouse[i] += deltaXMouse[i];
      epitaxinsiYMouse[i] += deltaYMouse[i];
      epitaxinsiZMouse[i] += deltaZMouse[i];
      xiMouse[i] += epitaxinsiXMouse[i];
      yiMouse[i] += epitaxinsiYMouse[i];
      ziMouse[i] += epitaxinsiZMouse[i];
    } else {
      xiMouse[i] = x;
      yiMouse[i] = y;
      ziMouse[i] = y;
    }
    my3d.x = xiMouse[i];
    my3d.y = yiMouse[i];
    my3d.z = z;
    glVertex3f(my3d.x, my3d.y, my3d.z);
    epitaxinsiXMouse[i] *= aposbesiMouse[i];    // slow down elastikotita
    epitaxinsiYMouse[i] *= aposbesiMouse[i];
    epitaxinsiZMouse[i] *= aposbesiMouse[i];
  }
  glEnd();
}












































