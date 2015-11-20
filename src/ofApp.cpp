#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

	bubble.setup();
	noise.setup();

}

//--------------------------------------------------------------
void ofApp::update(){

	ofBackground(0);
	ofSetWindowTitle(ofToString(ofGetFrameRate()));

	//noise.update4D(); // FUNCIONA, PERO ME ZARPO EN CANTIDAD DE CALCULOS Y NO ARRANCA: POW(PIXELS,4)
	noise.update();




}

//--------------------------------------------------------------
void ofApp::draw(){

	ofSetColor(255);

	//noise.render();

	ofPushMatrix();
	//ofTranslate(ofGetWidth() * 0.25,ofGetHeight() * 0.3, -200);
	ofTranslate(ofGetMouseX(), ofGetMouseY(), -200);


	drawAxisGizmo(200);


	int count = bubble.getMesh().getVertices().size();

	ofFill();
	for (int i = 0; i < count; i++)
	{

		float vertexNoise = noise.getNoiseAt(bubble.getMeshVertexPosition(i));
		bubble.setVertexRenderScale(vertexNoise * 5);
		bubble.renderVertex(i);

		
		//ofDrawBitmapString(ofToString(vertexNoise), bubble.getMeshVertexPosition(i) * bubble.scale);
		
		
		//bubble.setMeshVertexPosition(i,);

	}
	
	//bubble.render();

	// DRAW NOISE FIELD
	/*
	ofVec3f pos = ofVec3f(0.0,0.0,0.);
	float increment = 0.1;
	int count = 10;
	float size = 0;

	for (int x = 0; x < count; x++)
	{
	pos.x = (x * increment);

	for (int y = 0; y < count; y++)
	{
	pos.y = (y * increment);
	for (int z = 0; z < count; z++)
	{
	pos.z = (z * increment);

	size = noise.getNoiseAt(pos);
	ofCircle(pos * 200, size * 5);


	}

	}
	}
	*/



	//ofDrawAxis(100);

	ofPopMatrix();
}

void ofApp::drawAxisGizmo(float size){

	ofPoint worldCenter;
	worldCenter.set(0.,0.,0.);
	float multiplier = size;

	ofFill();
	ofSetColor(255);
	ofDrawBox(worldCenter,10);

	ofNoFill();
	ofSetColor(255,0,0);
	//X
	ofPoint extent = ofPoint( ofPoint(1 * multiplier,0,0));
	ofLine(worldCenter, extent);
	ofDrawBitmapString(ofToString(extent.x), extent);
	//Y
	extent.set(0, 1 * multiplier,0);
	ofSetColor(0,255,0);
	ofLine(worldCenter, extent);
	ofDrawBitmapString(ofToString(extent.y), extent);

	//Z
	extent.set(0,0, 1 * multiplier);
	ofSetColor(0,0,255);
	ofLine(worldCenter, extent);
	ofDrawBitmapString(ofToString(extent.z), extent);

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
