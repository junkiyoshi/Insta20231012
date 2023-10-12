#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofEnableDepthTest();
	ofSetLineWidth(1.5);
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);
	
	auto radius = 250;

	ofBeginShape();
	for (float theta_deg = 3; theta_deg < 180; theta_deg += 0.5) {

		auto phi_deg = ofMap(ofNoise(theta_deg * 0.01, ofGetFrameNum() * 0.0025), 0, 1, -720, 720);

		auto location = glm::vec3(
			radius * sin(theta_deg * DEG_TO_RAD) * cos(phi_deg * DEG_TO_RAD),
			radius * sin(theta_deg * DEG_TO_RAD) * sin(phi_deg * DEG_TO_RAD),
			radius * cos(theta_deg * DEG_TO_RAD));

		ofFill();
		ofDrawSphere(location, 3);
		ofVertex(location);
	}
	ofNoFill();
	ofEndShape();

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}