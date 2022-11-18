#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    img.load("flower.jpg");
    imgMat = toCv(img);
    
    vector<Mat> bgr;
    split(imgMat, bgr);
    
    threshold(bgr[0], mask, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    
    bitwise_and(bgr[0], mask, bgr[0]);
    bitwise_and(bgr[1], mask, bgr[1]);
    bitwise_and(bgr[2], mask, bgr[2]);
    
    merge(bgr, result);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    drawMat(imgMat, 0, 0);
    drawMat(mask, img.getWidth(), 0);
    drawMat(result, img.getWidth(), img.getHeight());
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
