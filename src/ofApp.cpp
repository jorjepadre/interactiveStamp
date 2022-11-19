#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // Load an image and convert to matrix
    img.load("flower.jpg");
    img.setImageType(OF_IMAGE_COLOR_ALPHA);
    imgMat = toCv(img);
    
    // Make a an array of 3 channels
    vector<Mat> bgr;
    split(imgMat, bgr);
    
    // Obtain a Mask
    threshold(bgr[0], mask, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    threshold(bgr[1], mask, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    threshold(bgr[2], mask, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);
    bitwise_and(bgr[0], mask, bgr[0]);
    bitwise_and(bgr[1], mask, bgr[1]);
    bitwise_and(bgr[2], mask, bgr[2]);
    bitwise_and(bgr[3], mask, bgr[3]);
    
    // Obtain a result matrix of a flower
    merge(bgr, result);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    drawMat(imgMat, 100, 100);
//    drawMat(mask, img.getWidth(), 0);
    drawMat(result, 100, img.getHeight() + 100);
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
    if (button == 0) {
        
    }
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    ;
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
