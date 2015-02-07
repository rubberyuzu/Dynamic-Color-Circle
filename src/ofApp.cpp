#include "ofApp.h"



//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(100);
    grid_size = 32;
    r = 200;
    linex = mouseX;
    liney = mouseY;
}

//--------------------------------------------------------------
void ofApp::update(){
    linex = mouseX;
    liney = mouseY;
    
    double x_dist = mouseX - ofGetWindowWidth()/2;
    double y_dist = mouseY - ofGetWindowHeight()/2;
    
    r = sqrt(pow(x_dist,2) + pow(y_dist, 2));
    
    ofVec3f v1(x_dist, y_dist);
    ofVec3f v2(10, 0);
    
    if(y_dist <= 0){
        angle = v1.angle(v2);
    }else{
        angle = 360 - v1.angle(v2);
    }
    
    hsb_col = ofColor::fromHsb(angle*255/360, 255, 255);
    
    cout << angle <<endl;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(hsb_col);
    int i;
    for(i=0; i<ofGetWindowHeight()/grid_size; i++){
        ofLine(0, i*grid_size, ofGetWindowWidth(), i*grid_size);
    }
    for(i=0; i<ofGetWindowWidth()/grid_size; i++){
        ofLine(i*grid_size, 0, i*grid_size, ofGetWindowHeight());
    }
    
    
    
    ofCircle(ofGetWindowWidth()/2, ofGetWindowHeight()/2, r);
    
    ofLine(linex, liney-ofGetWindowHeight(),linex, liney+ofGetWindowHeight());
    ofLine(linex-ofGetWindowWidth(), liney,linex+ofGetWindowWidth(), liney);
    
    ofSetColor(255);
    ofDrawBitmapString(ofToString(angle), mouseX, mouseY);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
