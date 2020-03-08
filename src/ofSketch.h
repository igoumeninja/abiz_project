/*
 *  Sketch.h
 *  sketch091221
 *
 *  Created by fou fou on 12/23/09.
 *  Copyright 2009 Aris Bezas. All rights reserved.
 *
 */

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
  float epitaxinsiXMouse[stoixeiaMouse], epitaxinsiYMouse[stoixeiaMouse];
  float			epitaxinsiZMouse[stoixeiaMouse];
  float			elastikotitaMouse[stoixeiaMouse];
  float			aposbesiMouse[stoixeiaMouse];	
  float			deltaXMouse[stoixeiaMouse];
  float			deltaYMouse[stoixeiaMouse];
  float			deltaZMouse[stoixeiaMouse];
  
  float			elast, aposv;
  int				xL, yL, zL;
  float			value, xC, yC;		
  int				redL, greenL, blueL, alphaL;
  float			delta;
  float			xp,yp;
  
  float				on_off, lines, slines;
  
  ofVec3f		my3d;
  
  void			init(int sketchID, float elast, float aposv);
  void			drawMouse3D(int xL, int yL, int zL, int redL, int greenL, int blueL, int alphaL, float lines);
private:
	ofxOscSender	sender;
};








































