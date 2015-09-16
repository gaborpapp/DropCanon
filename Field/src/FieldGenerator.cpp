#include "FieldGenerator.h"
#include "Globals.h"

void FieldGenerator::setup() {
    int tmpNumParticles = Globals::fieldNumParticles;
    numParticlesChanged( tmpNumParticles );
    mode = "noise_random";
    camera.setNearClip(0.01f);
}

void FieldGenerator::numParticlesChanged(int& _num ) {
    particles.resize( _num );
    for( unsigned int i = 0; i < particles.size(); i++ ) {
        reInitParticle( &particles.at(i) );
        particles.at(i).age = ofRandom( Globals::fieldMaxAge );
        ofVec3f middle(0.5,0.5,particles.at(i).pos.z);
        particles.at(i).distanceFromMiddle = middle.distance(particles.at(i).pos);
    }
}

void FieldGenerator::reInitParticle( FieldParticle* _p ) {
    ofVec3f spawnSize(10,10,10);
    
    //  Cuboid distribution
    _p->pos = ofVec3f(  ofRandom( spawnSize.x * -0.5, spawnSize.x * 0.5),
                        ofRandom( spawnSize.y *  0.0, spawnSize.y * 1.0),
                        ofRandom( spawnSize.z * -0.5, spawnSize.z * 0.5) );
    
    //  Planar distribution
    /*
    _p->pos = ofVec3f(ofRandom( spawnSize.x * -0.5, spawnSize.x * 0.5),
                      ofRandom( spawnSize.y * -0.5, spawnSize.y * 0.5),
                      0.5);
     */
    _p->vel = ofVec3f(0);
    
    _p->fieldRandomOffset = ofVec3f( ofRandom( 0, Globals::fieldRandomOffset),
                                     ofRandom( 0, Globals::fieldRandomOffset),
                                     ofRandom( 0, Globals::fieldRandomOffset) );
    _p->age = 0;
    _p->posHistory.clear();
}


void FieldGenerator::update() {
    float time = ofGetElapsedTimef();
    float timeDelta = 1.0 / 60.0; //ofGetLastFrameTime();
    
    float fieldReadTime = time * Globals::fieldTimeFrequency;
    
    for( unsigned int i = 0; i < particles.size(); i++ ) {
        FieldParticle* p = &particles.at(i);
        particles.at(i).age += timeDelta;
        
        if( particles.at(i).age >= Globals::fieldMaxAge )
        {
            reInitParticle( p );
        }
        
        ofVec3f noiseReadPos = (p->pos + p->fieldRandomOffset ) * Globals::fieldSpaceFrequency;
        
        ofVec3f v1 = (getNoise( noiseReadPos, fieldReadTime ) * Globals::fieldMagnitude).getInterpolated( p->vel, Globals::fieldOldVelAmount ) * Globals::fieldNoiseAmount;
        ofVec3f v2 = (getSpiral( p->pos, p->distanceFromMiddle, Globals::fieldSpiralRatio, ofGetElapsedTimef()) * Globals::fieldMagnitude).getInterpolated( p->vel, Globals::fieldOldVelAmount ) * Globals::fieldSpiralAmount;
        ofVec3f v3 = (getUniform() * Globals::fieldMagnitude).getInterpolated( p->vel, Globals::fieldOldVelAmount ) * Globals::fieldUniformAmount;
        
        //  mix all the field types here
        p->vel = v1 + v2 + v3;
        
        p->vel.limit( Globals::fieldMaxVel );
        p->pos += p->vel;
        
        // Save positions to use as a tail
        p->posHistory.push_front( p->pos );
        while( p->posHistory.size() > Globals::fieldTailLength ) { p->posHistory.pop_back(); }
    }
}

ofVec3f FieldGenerator::getNoise( ofVec3f _noisePos, float _time ) {
    ofVec3f p(0,0,0);
    
    //	p.x += ofSignedNoise( _noisePos.x, _noisePos.y, _noisePos.z, _time );
    //	p.y += ofSignedNoise( _noisePos.y, _noisePos.z, _noisePos.x, _time );
    //	p.z += ofSignedNoise( _noisePos.z, _noisePos.x, _noisePos.y, _time );
    
    p.x += ofSignedNoise( _noisePos.x, _noisePos.y, _noisePos.z, _time );
    p.y += ofSignedNoise( _noisePos.y, _noisePos.z, _time,		 _noisePos.x );
    p.z += ofSignedNoise( _noisePos.z, _time,		_noisePos.x, _noisePos.y );
    return p;
}

ofVec3f FieldGenerator::getUniform(  ) {
    ofVec3f p(0,0,0);
    p.y -= 0.2;
    return p;
}

ofVec3f FieldGenerator::getSpiral( ofVec3f _particlePos, float _distance, float _ratio, float _time ) {
    ofVec3f p(0,0,0);
    p.x-=_ratio;
    p.y-=_ratio;
    p.rotateRad(atan2(_particlePos.y, _particlePos.x), ofVec3f(0,0,0), ofVec3f(0,1,1));
    return p;
}


void FieldGenerator::draw() {
    if(!inited) {
        camera.setPosition( 0, 0, Globals::camZoom );
    }
    camera.begin();
    
    ofSetColor(255,0,0);
    
    ofDrawLine(0,-0.1,0,0.1);
    ofDrawLine(-0.1,0,0.1,0);
    
    drawParticles();
    
    camera.end();
}

void FieldGenerator::drawParticles() {
    ofPushMatrix();
    
    //  use rotation sensors here
    /*  
        ofRotateX(ofGetFrameNum());
        ofRotateZ(ofGetFrameNum());
        ofRotateY(ofGetFrameNum());
    */
    
    ofMesh mesh;
    mesh.setMode( OF_PRIMITIVE_LINES );
    for( unsigned int i = 0; i < particles.size(); i++ ) {
        FieldParticle* p = &particles.at(i);
        
        ofSeedRandom( i << 24 );
        
        ofColor c = (Globals::invert) ? 255 : 0;
        ofSetColor(c);
        if( p->posHistory.size() > 1 ) {
            for( int j = 1; j < p->posHistory.size(); j++ ) {
                mesh.addVertex( p->posHistory.at(j-1) );
                mesh.addVertex( p->posHistory.at(j) );
            }
        }
    }
    mesh.draw();
    
    ofPopMatrix();
    ofSeedRandom();
}


