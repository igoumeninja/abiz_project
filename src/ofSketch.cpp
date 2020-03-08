/*
 *  Sketch.cpp
 *  sketch091221
 *
 *  Created by Aris Bezas on 091223
 *  Copyright 2009 igoumeninja. All rights reserved.
 *
 */
 
#include "ofApp.h"
#include "ofSketch.h"
//----------------------------------------------------------------------------------------------------//

// Initialize the Sketch Lines Characteristics
void ofSketch::init(int sketchID, float elast, float aposv) {
	
	if	(sketchID == 0)	{
		for (int i=0; i<stoixeia; i++){
			elastikotita[i] = (elast)*(.07*(i+1));// 0.05  kai 0.005
			aposbesi[i] = aposv-(0.02 *i);
		}
	}
	if	(sketchID == 1)	{
		for (int i=0; i<stoixeiaMouse; i++){
			elastikotitaMouse[i] = (elast)*(.05*(i+1));// 0.05  kai 0.005
			aposbesiMouse[i] = aposv-(0.02 *i);
		}
	}
}

void ofSketch::drawMouse3D(int xL, int yL, int zL, int redL, int greenL, int blueL, int alphaL, float lines) {
  ofNoFill();
  ofSetColor(redL, greenL, blueL, alphaL);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_LINE_SMOOTH);    
  if	(lines)	{
    glBegin(GL_POINTS); //GL_LINE_LOOP,GL_POINTS, GL_LINE_STRIP  ( http://pyopengl.sourceforge.net/documentation/manual/glBegin.3G.xml )
  }	else	{
    glBegin(GL_POINTS); //GL_LINE_LOOP
  }
  
  for (int i=0; i<stoixeiaMouse; i++){
    if	(alphaL != 0)	{
      if (i==0){
        deltaXMouse[i] = (xL - xiMouse[i]);
        deltaYMouse[i] = (yL - yiMouse[i]);
        deltaZMouse[i] = (zL - ziMouse[i]);
      }
      else {
        deltaXMouse[i] = (xiMouse[i-1]-xiMouse[i]);
        deltaYMouse[i] = (yiMouse[i-1]-yiMouse[i]);
        deltaZMouse[i] = (ziMouse[i-1]-ziMouse[i]);
      }		
      deltaXMouse[i] *= elastikotitaMouse[i];    // create elastikotita effect
      deltaYMouse[i] *= elastikotitaMouse[i];
      deltaZMouse[i] *= elastikotitaMouse[i];
      epitaxinsiXMouse[i] += deltaXMouse[i];
      epitaxinsiYMouse[i] += deltaYMouse[i];
      epitaxinsiZMouse[i] += deltaZMouse[i];
      xiMouse[i] += epitaxinsiXMouse[i]; // move it
      yiMouse[i] += epitaxinsiYMouse[i];
      ziMouse[i] += epitaxinsiZMouse[i];
    } else {
      xiMouse[i] = xL;
      yiMouse[i] = yL;
      ziMouse[i] = yL;
    }		
    my3d.x = xiMouse[i];
    my3d.y = yiMouse[i];
    my3d.z = zL;		//my3d.z = ofRandom(100,500); maybe it 'll be interasting to put a midi controller for this to prevent chaotic-sand results
    glVertex3f(my3d.x, my3d.y, my3d.z);	
    epitaxinsiXMouse[i] *= aposbesiMouse[i];    // slow down elastikotita
    epitaxinsiYMouse[i] *= aposbesiMouse[i];
    epitaxinsiZMouse[i] *= aposbesiMouse[i];
  }
  glEnd();	
}












































