#pragma once

#include "ofMain.h"

class Bubble
{
public:
	Bubble(void);
	~Bubble(void);

	void setup();
	void update();
	void render();
	void renderVertex(int index);


	ofMesh bubble;
	float scale;
	float vertexRenderScale;

	ofMesh getMesh();
	ofVec3f getMeshVertexPosition(int index);
	void setMeshVertexPosition(int index, ofVec3f position);


	void setScale(float _scale);
	void setVertexRenderScale(float _vertexRenderScale);

private:

};

