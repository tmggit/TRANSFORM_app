
//
//  MoldedShape.h
//  basicExample
//
//  Created by Daniel Windham on 6/23/15.
//
//

#ifndef __basicExample__MoldedShape__
#define __basicExample__MoldedShape__

#include <iostream>
#include "ofMain.h"
#include "Constants.h"
#include "Depression.h"


#define MOLDED_SHAPE_DIM 16
#define MOTION_ACCUMULATION_THRESHOLD 50 // lower this to increase speed
#define DECELERATION_ACCUMULATION_THRESHOLD 10 // lower this to increase friction


class MoldedShape {
public:
    MoldedShape(int id, int _heightMap[MOLDED_SHAPE_DIM][MOLDED_SHAPE_DIM]);
    MoldedShape(int id, MoldedShape *moldedShape);
    void update();
    int getId();
    void setDirection(float angleInDegrees);
    void setVelocity(ofVec2f velocity);
    ofVec2f getVelocity();
    Boolean containsLocation(ofVec2f location);
    ofVec2f nearestEdgeToLocation(ofVec2f location);
    ofVec2f vectorFromNearestEdgeToLocation(ofVec2f location);
    float distanceFromLocation(ofVec2f location);
    Boolean overlapsShape(MoldedShape *otherShape);
    Depression netDepressionVector(int depressionMap[RELIEF_SIZE_X][RELIEF_SIZE_Y], int allowedDistance=2);
    void updateVelocityFromDepressions(int depressionMap[RELIEF_SIZE_X][RELIEF_SIZE_Y]);

    ofVec2f position;
    int heightMap[MOLDED_SHAPE_DIM][MOLDED_SHAPE_DIM];
    int totalVolume = 0;
    ofVec2f centerOfVolume;
    int speed = 0;
    ofVec2f direction; // direction of movement as a unit vector

private:
    void calculateCenterOfVolume();
    int id;
    ofVec2f motionAccumulator;
    int decelerationAccumulator = 0;
};


#endif /* defined(__basicExample__MoldedShape__) */