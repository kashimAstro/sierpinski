#include "testApp.h"

float theta=0,r,g,b,separacion=2;
int h=0;
int width,height;
bool xmousePressed=false;
ofLight light;
ofMaterial material;
ofEasyCam cam;
ofImage matCap;
ofShader shader;

void drawSphere(float x,float y,float z,float radio,float r,float g,float b,float divisor)
{
  ofPushMatrix();
  ofTranslate(x,y,z);
  if(xmousePressed){
    ofNoFill();
    ofSetColor(0,60);
  }else{
    ofFill();
    ofSetColor(255,60);
  }

  ofBeginShape();
  ofVertex(0,0,0);
  ofVertex(radio/divisor,0,0);
  ofEndShape();
  ofBeginShape();
  ofVertex(0,0,0);
  ofVertex(-radio/divisor,0,0);
  ofEndShape();
  ofBeginShape();
  ofVertex(0,0,0);
  ofVertex(0,radio/divisor,0);
  ofEndShape();
  ofBeginShape();
  ofVertex(0,0,0);
  ofVertex(0,-radio/divisor,0);
  ofEndShape();
  ofBeginShape();
  ofVertex(0,0,0);
  ofVertex(0,0,radio/divisor);
  ofEndShape();
  ofBeginShape();
  ofVertex(0,0,0);
  ofVertex(0,0,-radio/divisor);
  ofEndShape();
  ofSetColor(r,g,b);
  
  ofDrawBox(radio);
  if(radio>20)
  {
    drawSphere(radio/divisor,0,0,radio/2,r,0,b,divisor);
    drawSphere(-radio/divisor,0,0,radio/2,r,g,0,divisor);
    drawSphere(0,radio/divisor,0,radio/2,0,g,b,divisor);
    drawSphere(0,-radio/divisor,0,radio/2,r,g,0,divisor);
    drawSphere(0,0,radio/divisor,radio/2,r,0,b,divisor);
    drawSphere(0,0,-radio/divisor,radio/2,0,g,b,divisor);
  }
  ofPopMatrix();
}



//--------------------------------------------------------------
void testApp::setup(){
r=ofRandom(255);
g=ofRandom(255);
b=ofRandom(255);
width=ofGetScreenWidth();
height=ofGetScreenHeight();
 ofEnableDepthTest();
         ofDisableArbTex();
         matCap.loadImage("matcap7.jpg");
         shader.load("sem");
ofToggleFullscreen();
}

//--------------------------------------------------------------
void testApp::update(){
}

//--------------------------------------------------------------
void testApp::draw(){
  ofBackground(0,20);
  if(xmousePressed)
     ofBackground(255,20);
cam.begin();
//  ofTranslate(0,height/2,-500);

shader.begin();
   shader.setUniformTexture("tMatCap", matCap, 1);
  for(int e=1;e<=2;e++){
    separacion=ofMap(mouseX,0,width,0,1.5);
     ofPushMatrix();
     ofTranslate(e*width/3,0,0);
  if(e==2)  
  {
   ofRotateY(theta);
   ofRotateX(theta);
   ofRotateZ(theta);
  }
  if(e==1)
  {
   ofRotateY(theta);
   ofRotateX(-theta);
   ofRotateZ(-theta);
  }
  drawSphere(0,0,0,mouseY/4,100,100,100,separacion);
  drawSphere(0,height/4,0,mouseY/4,r,g,b,separacion);
  drawSphere(0,-height/4,0,mouseY/4,r,g,b,separacion);
  drawSphere(0,0,height/4,mouseY/4,r,g,b,separacion);
  drawSphere(0,0,-height/4,mouseY/4,r,g,b,separacion);
  ofPopMatrix();
}

shader.end();
cam.end();
theta+=0.02;
h+=100;
if(h==10000)
h=0;

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
xmousePressed=!xmousePressed;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
