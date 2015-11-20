#pragma once

#include "ofMain.h"
#include "noiseGenerator.h"

class noiseGenerator
{
public:
	noiseGenerator(void);
	~noiseGenerator(void);

	void setup();
	void update();
	void render();
	void renderNoise3D();
	void renderNoise4D();

	float getNoiseAt(ofVec3f spacePosition);


	ofVec2f textureSize;
	float zDim;
	float aDim;
	float phase;

	ofImage noiseImage;



private:


};

