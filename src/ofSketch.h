// Copyright 2019 Aris Bezas
#pragma once

#define stoixeia 200

class ofSketch {
 public:
  int sketchID;
  float xi[stoixeia], yi[stoixeia], zi[stoixeia];
  float epitaxinsiX[stoixeia], epitaxinsiY[stoixeia], epitaxinsiZ[stoixeia];
  float elastikotita[stoixeia], aposbesi[stoixeia];
  float deltaX[stoixeia], deltaY[stoixeia], deltaZ[stoixeia];

  float elast, aposv;

  ofVec3f my3d;
  void init(float elast, float aposv);
  void draw(int x, int y, int z, int r, int g, int b, int a);
};








































