#pragma once

class Globals{
public:
    
    static bool  invert;
    static float distanceAlpha;
    
    //  camera
    static float camZoom;
    static float camPanX;
    static float camPanY;
    
    // noise grid
    static bool  fieldShowTail;
    static int   fieldNumParticles;
    static float fieldNoiseAmount;
    static float fieldSpiralAmount;
    static float fieldUniformAmount;
    static float fieldCircularAmount;
    static float fieldOscillAmount;
    static float fieldRandomOffset;
    static float fieldMagnitude;
    static float fieldSpaceFrequency;
    static float fieldTimeFrequency;
    static float fieldOldVelAmount;
    static float fieldMaxVel;
    static float fieldMaxAge;
    static float fieldSpiralRatio;
    static float fieldCircularRatio;
    static float fieldOscillRatio;
    static int   fieldTailLength;
    static float fieldConnections;
    static int   fieldResetPos;
    static bool  fieldAging;
    
};
