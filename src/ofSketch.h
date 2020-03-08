// Copyright 2019 Aris Bezas
#pragma once

#define stoixeia 100
#define stoixeiaMouse 100

class ofSketch {
 public:
  int sketchID;
  float xi[stoixeia], yi[stoixeia];
  float epitaxinsiX[stoixeia], epitaxinsiY[stoixeia];
  float elastikotita[stoixeia], aposbesi[stoixeia];
  float deltaX[stoixeia], deltaY[stoixeia];
  float xiMouse[stoixeiaMouse], yiMouse[stoixeiaMouse], ziMouse[stoixeiaMouse];
  float epitaxinsiXMouse[stoixeiaMouse], epitaxinsiYMouse[stoixeiaMouse],
    epitaxinsiZMouse[stoixeiaMouse];
  float elastikotitaMouse[stoixeiaMouse], aposbesiMouse[stoixeiaMouse];
  float deltaXMouse[stoixeiaMouse], deltaYMouse[stoixeiaMouse],
    deltaZMouse[stoixeiaMouse];

  float elast, aposv;
  int xL, yL, zL;
  float value, xC, yC;
  int redL, greenL, blueL, alphaL;
  float delta;
  float xp, yp;
  float on_off, lines, slines;

  ofVec3f my3d;
  void init(int sketchID, float elast, float aposv);
  void drawMouse3D(int xL, int yL, int zL, int redL, int greenL, int blueL, int alphaL, float lines);
private:
	ofxOscSender	sender;
};








































