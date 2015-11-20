#include "noiseGenerator.h"


noiseGenerator::noiseGenerator()
{
}


noiseGenerator::~noiseGenerator(void)
{
}

void noiseGenerator::setup(){

	zDim = aDim = ofRandom(1.);
	phase = 0.015;

	textureSize.set(20,10);
	noiseImage.allocate( floor(textureSize.x), floor(textureSize.y), OF_IMAGE_GRAYSCALE);

}

void noiseGenerator::update(){

	aDim += phase;
	//zDim += phase;
}



void noiseGenerator::render(){



}

float noiseGenerator::getNoiseAt(ofVec3f spacePosition){
	
	// spacePosition SHOULD ENTER NORMALIZED
	
	return ofNoise(spacePosition.x, spacePosition.y, spacePosition.z, aDim);
}

void noiseGenerator::renderNoise3D(){

	ofPixelsRef noisePixels = noiseImage.getPixelsRef();
	//noisePixels.setFromPixels(noiseImage.getPixels(), noiseImage.getWidth(), noiseImage.getHeight(), OF_IMAGE_GRAYSCALE);

	
	float xDim = 0.0;
	for (int x = xDim; x < noisePixels.getWidth(); x++) {
		xDim += phase;
		float yDim = 0.0;
		for (int y = yDim; y < noisePixels.getHeight(); y++) {
			yDim += phase;

			float intensity = ofNoise(xDim,yDim,zDim);
			
			noisePixels.setColor(noisePixels.getPixelIndex(x,y), ofColor(intensity * 255));

		}
	}
	
	zDim += phase;

	noiseImage.setFromPixels(noisePixels);
	noiseImage.draw(0,0);

}

void noiseGenerator::renderNoise4D(){

	ofPixelsRef noisePixels = noiseImage.getPixelsRef();
	//noisePixels.setFromPixels(noiseImage.getPixels(), noiseImage.getWidth(), noiseImage.getHeight(), OF_IMAGE_GRAYSCALE);


	float xDim = 0.0;
	for (int x = xDim; x < noisePixels.getWidth(); x++) {
		
		xDim += phase;
		float yDim = 0.0;
		
		for (int y = yDim; y < noisePixels.getHeight(); y++) {
			
			yDim += phase;
			float zDim = 0.0;
			
			for (int z = zDim; z < noisePixels.getHeight(); z++) {
				zDim += phase;

				aDim = 0.0;
				for (int a = aDim; a < noisePixels.getHeight(); a++) {
					aDim += phase;
					float intensity = ofNoise(xDim,yDim,zDim, aDim);
					noisePixels.setColor(noisePixels.getPixelIndex(x,y), ofColor(intensity * 255));

					//cout << ofToString(xDim) + " : " + ofToString(yDim) + " : " + ofToString(zDim) + " : " + ofToString(aDim) << endl;
				}
			}
		}

	}

	aDim += phase;

	noiseImage.setFromPixels(noisePixels);
	noiseImage.draw(0,0);

}
