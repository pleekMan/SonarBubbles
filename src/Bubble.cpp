#include "Bubble.h"


Bubble::Bubble()
{
}


Bubble::~Bubble(void)
{
}

void Bubble::setup(){

	scale = 300;
	vertexRenderScale = 30;

	//ofSetSphereResolution(100);
	ofSpherePrimitive sphere;
	sphere.setResolution(50);
	sphere.setRadius(1.0);
	sphere.setPosition(ofVec3f(0,0,0));
	bubble = sphere.getMesh();

}

ofMesh Bubble::getMesh(){
	return bubble;
}

ofVec3f Bubble::getMeshVertexPosition(int index){
	return bubble.getVertex(index);
}

void Bubble::setMeshVertexPosition(int index, ofVec3f position){
	bubble.getVertex(index).set(position);
}

void Bubble::update(){


	

}

void Bubble::render(){

	ofSetColor(255);
	ofNoFill();

	for (int i = 0; i < bubble.getVertices().size(); i++)
	{
		if(vertexRenderScale < 5){
			ofSetColor(255);
		} else {
			ofSetColor(255,0,0);
		}
		ofCircle( bubble.getVertex(i) * scale, vertexRenderScale);
		
	}

}

void Bubble::renderVertex(int index){
		
		if(vertexRenderScale < 2.5){
			ofSetColor(255);
		} else {
			ofSetColor(0,0,127);
		}

		ofCircle( bubble.getVertex(index) * scale, vertexRenderScale);
		

}



void Bubble::setScale(float _scale){
	scale = _scale;
}

void Bubble::setVertexRenderScale(float _vertexRenderScale){
	vertexRenderScale = _vertexRenderScale;
}




