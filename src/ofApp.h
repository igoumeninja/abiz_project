//-  Copyright 2019 and initial definition
  #pragma once

  #include "ofMain.h"
  #include "ofxOscSubscriber.h"
  #include "ofSketch.h"
  #include "ParticleSystem.h"
  #include <vector>

  #define PORT 12345
  #define NUM_MSG_STRINGS 20
class ofApp : public ofBaseApp{
 public:
  //- the voids
    void setup();
    void update();
    void draw();
  //- OSC
    ofxOscReceiver receiver;
    int currentMsgString;
    string msgStrings[NUM_MSG_STRINGS];
    float timers[NUM_MSG_STRINGS];
  //- Booleans
    bool fillBackground, sketchView;
    bool cutMotion, mirrorMode, onsetOn;
    bool soundSketch, soundSketchOld;
  //- Soundsketch
    float xSoundSketch, ySoundSketch;
  //- Textures
    ofTexture  fftTexture;
    ofTexture textureScreen;
  //- sketch
    ofSketch sketch[2048];
    float xSketch, ySketch, zSketch;
    float elasticityMin;
    float elasticityMax;
    float dampingMin;
    float dampingMax;
    float xSketchMin, xSketchMax, ySketchMin, ySketchMax;
    ofNode baseNode;
    ofNode childNode;
    ofNode grandChildNode;
    ofPolyline line;
    ofEasyCam cam;
  //- Colors
    ofColor bg_color, dotColor, conColor, sketchColor;
    ofColor fbo_color;
    ofColor color;
  int rSketch, gSketch, bSketch, aSketch;
  //- Particles
    ParticleSystem particleSystem;

    int rConColor, gConColor, bConColor, aConColor,
      rDotColor, gDotColor, bDotColor, aDotColor;
    int bounceXstart, bounceYstart, bounceXend, bounceYend;
    bool particleView, isMousePressed, slowMotion,
      viewParticles, iPadPush, pushParticles;
    float timeStep, pushX, pushY;
    int lineOpacity, pointOpacity;
    float particleNeighborhood, particleRepulsion;
    float centerAttraction;
    int kParticles, forceScale, forceRadius;
};
