// Copyright 2019 Aris Bezas
#include "ofApp.h"
void ofApp::setup() {
  //- Global Definition
    ofBackground(0, 0, 0);
    ofSetWindowPosition(0, 0);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);
    ofEnableAlphaBlending();
    ofSetFrameRate(60);  // if vertical sync is off, we can go faster
    ofSetVerticalSync(false);
    glPointSize(1);
    ofEnableAntiAliasing();
    ofSetFrameRate(60);
    ofSetBackgroundAuto(false);
    // ofEnableDepthTest();
  //- OSC communication
    receiver.setup(PORT);
    ofxSubscribeOsc(9005, "/particleView", particleView);
    ofxSubscribeOsc(9005, "/bounce/x/start", bounceXstart);
    ofxSubscribeOsc(9005, "/bounce/y/start", bounceYstart);
    ofxSubscribeOsc(9005, "/bounce/x/end", bounceXend);
    ofxSubscribeOsc(9005, "/bounce/y/end", bounceYend);
    ofxSubscribeOsc(9005, "/particleNeighborhood", particleNeighborhood);
    ofxSubscribeOsc(9005, "/forceRadius", forceRadius);
    ofxSubscribeOsc(9005, "/forceScale", forceScale);
    ofxSubscribeOsc(9005, "/pushParticles", pushParticles);
    ofxSubscribeOsc(9005, "/push/x", pushX);
    ofxSubscribeOsc(9005, "/push/y", pushY);
    ofxSubscribeOsc(9005, "/dotColor", dotColor);
    ofxSubscribeOsc(9005, "/conColor", conColor);

    ofxSubscribeOsc(9005, "/sketchView", sketchView);
    ofxSubscribeOsc(9005, "/sketch/x", xSketch);
    ofxSubscribeOsc(9005, "/sketch/y", ySketch);
    ofxSubscribeOsc(9005, "/sketch/z", zSketch);
    ofxSubscribeOsc(9005, "/elasticityMin", elasticityMin);
    ofxSubscribeOsc(9005, "/elasticityMax", elasticityMax);
    ofxSubscribeOsc(9005, "/dampingMin", dampingMin);
    ofxSubscribeOsc(9005, "/dampingMax", dampingMax);
    ofxSubscribeOsc(9005, "/sketchColor", sketchColor);
    
    ofxSubscribeOsc(9005, "/bg_color", bg_color);
  //- Start Values
    rDotColor = gDotColor = bDotColor = aDotColor = 255;
    rSketch = gSketch = bSketch = aSketch = 255;
    xSketch = ySketch = zSketch = 100;
    xSketchMin = 0; xSketchMax = 1;
    ySketchMin = 40; ySketchMax = 800;
    fillBackground = true;
    sketchView = true;
    particleView = false;
    sketchColor = ofColor(255, 255, 255, 255);
    bg_color = ofColor(0, 0, 0, 40);
    ofBackground(255);
  //- Sketch
  //- Particles
    int binPower = 4;

    particleSystem.setup(ofGetWidth(), ofGetHeight(), binPower);
    kParticles = 2;  // change that to 5 for MacBook Pro
    float padding = 0;
    float maxVelocity = .95;
    for (int i = 0; i < kParticles * 1024; i++) {
      float x = ofRandom(padding, ofGetWidth() - padding);
      float y = ofRandom(padding, ofGetHeight() - padding);
      float xv = ofRandom(-maxVelocity, maxVelocity);
      float yv = ofRandom(-maxVelocity, maxVelocity);
      Particle particle(x, y, xv, yv);
      particleSystem.add(particle);
    }
    rConColor = gConColor = bConColor = 255;
    rDotColor = gDotColor = bDotColor = 255;
    timeStep = 1;
    lineOpacity = 1;
    pointOpacity = 255;
    isMousePressed = false;
    slowMotion = false;
    particleNeighborhood = 25;
    particleRepulsion = 3;
    centerAttraction = .01;
    forceRadius = 100;
    forceScale = 10;
    bounceXstart = 0;
    bounceYstart = 0;
    bounceXend = ofGetScreenWidth();
    bounceYend = ofGetScreenHeight();}
  void ofApp::update() {
  //- Sketch
    if (sketchView) {
      for (int i = 100; i < 200; i++) {
        sketch[i].init(ofRandom(elasticityMin, elasticityMax),
                       ofRandom(dampingMin, dampingMax));
      }
    }
  }
void ofApp::draw() {
  //- fillBackgroumd
    if (fillBackground) {
      ofSetColor(bg_color);
      ofFill();
      ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());}
  //- Sketch
    if (sketchView) {
      ofSetColor(sketchColor);
      for (int i=100; i < 200; i++) {
        //sketch[i].drawMouse3D(xSketch, ySketch, zSketch,
        //                      rSketch, gSketch, bSketch, aSketch, 1);
        sketch[i].draw( xSketch, ySketch, zSketch, 255,255,255,255,1);
      }
    }
  //- Particles
    if (particleView) {
      particleSystem.setTimeStep(timeStep);
      ofSetColor(conColor);
      particleSystem.setupForces();
      glBegin(GL_LINES);
      for (int i = 0; i < particleSystem.size(); i++) {
        Particle& cur = particleSystem[i];
        particleSystem.addRepulsionForce(
            cur, particleNeighborhood, particleRepulsion);
        cur.bounceOffWalls(bounceXstart, bounceYstart, bounceXend, bounceYend);
        cur.addDampingForce();
      }
      if (pushParticles) {
        particleSystem.addRepulsionForce(
            pushX, pushY, forceRadius, forceScale);
      }
      glEnd();
      particleSystem.update();
      ofSetColor(dotColor);
      particleSystem.draw();
    }
}

