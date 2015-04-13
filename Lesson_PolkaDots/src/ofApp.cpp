#include "ofApp.h"

void ofApp::drawanH(float xPos, float yPos, float scale){

ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    ofSetColor(MedAqua);
    float triangleX = 100;
    if (ofGetFrameNum() % 12 == 0){
    ofTriangle(100,100,150,150,100,200);
    }
    if (ofGetFrameNum() % 12 == 1){
    ofTriangle(100+20,100,150+20,150,100+20,200);
    }
    if (ofGetFrameNum() % 12 == 2){
    ofTriangle(100+40,100,150+40,150,100+40,200);
    }
    if (ofGetFrameNum() % 12 == 3){
    ofTriangle(100+60,100,150+60,150,100+60,200);
    }
    if (ofGetFrameNum() % 12 == 4){
    ofTriangle(100+80,100,150+80,150,100+80,200);
    }
    if (ofGetFrameNum() % 12 == 5){
    ofTriangle(100+100,100,150+100,150,100+100,200);
    }
    if (ofGetFrameNum() % 12 == 6){
    ofTriangle(100+140,100,150+140,150,100+140,200);
    }
    if (ofGetFrameNum() % 12 == 7){
    ofTriangle(100+160,100,150+160,150,100+160,200);
    }
    if (ofGetFrameNum() % 12 == 8){
    ofTriangle(100+180,100,150+180,150,100+180,200);
    }
    if (ofGetFrameNum() % 12 == 9){
    ofTriangle(100+220,100,150+220,150,100+220,200);
    }
    if (ofGetFrameNum() % 12 == 10){
    ofTriangle(100+240,100,150+240,150,100+240,200);
    }
    if (ofGetFrameNum() % 12 == 11){
    ofTriangle(100+270,100,150+270,150,100+270,200);
    }
    else if (ofGetFrameNum() % 12 == 12){
    ofTriangle(100+300,100,150+300,150,100+300,200);
    }

    ofSetColor(Salmon);

    if (ofGetFrameNum() % 12 == 1){
    ofTriangle(70,100,120,150,70,200);
    }
    if (ofGetFrameNum() % 12 == 2){
    ofTriangle(100,100,150,150,100,200);
    }
    if (ofGetFrameNum() % 12 == 3){
    ofTriangle(100+20,100,150+20,150,100+20,200);
    }
    if (ofGetFrameNum() % 12 == 4){
    ofTriangle(100+40,100,150+40,150,100+40,200);
    }
    if (ofGetFrameNum() % 12 == 5){
    ofTriangle(100+70,100,150+70,150,100+70,200);
    }
    if (ofGetFrameNum() % 12 == 6){
    ofTriangle(100+100,100,150+100,150,100+100,200);
    }
    if (ofGetFrameNum() % 12 == 7){
    ofTriangle(100+130,100,150+130,150,100+130,200);
    }
    if (ofGetFrameNum() % 12 == 8){
    ofTriangle(100+160,100,150+160,150,100+160,200);
    }
    if (ofGetFrameNum() % 12 == 9){
    ofTriangle(100+180,100,150+180,150,100+180,200);
    }
    if (ofGetFrameNum() % 12 == 10){
    ofTriangle(100+200,100,150+200,150,100+200,200);
    }
    if (ofGetFrameNum() % 12 == 11){
    ofTriangle(100+220,100,150+220,150,100+220,200);
    }
    if (ofGetFrameNum() % 12 == 12){
    ofTriangle(100+240,100,150+240,150,100+240,200);
    }
    else if (ofGetFrameNum() % 12 == 0){
    ofTriangle(100+260,100,150+260,150,100+260,200);
    }
ofPopMatrix();

float animateAtime = 1.0; // does 1 mean 1 second?
float animateBtime = 1.0;  // assume that b is first
float totalAnimatetime = animateAtime + animateBtime;
float currentTime = ofGetElapsedTimef(); // get the current time
float timeInAnimation = currentTime;
while (timeInAnimation > totalAnimatetime){ //while the current time is greater than A-B
    timeInAnimation -= totalAnimatetime; // this is like fmod for time (I can explain)
} //now we've gotten a value that counts up to 2 seconds every two seconds.  Now some logic to figure out what pct of a and b we've done given time
float apct = ofMap(timeInAnimation -animateBtime , 0,
                   animateAtime, 0,1, true);  // the minus animateBtime is cause b is assumed first
float bpct = ofMap(timeInAnimation, 0,
                   animateBtime, 0,1, true);
float cpct = ofMap(timeInAnimation+1, 0,
                   animateBtime, 0,1, true);
float a = ofMap(apct, 0,1,0,100); // what do these numbers mean?
float b = ofMap(bpct, 0,1,0,100);
float c = ofMap(cpct, 0,1,0,100);
ofLine(600,b,600,c);
ofSetColor(MedAqua);
ofLine(590,a,590,b);
ofSetColor(Pink);
ofLine(500,b,500,a);
ofLine(510,a,510,b);
}

//-----------------HI------------------------------------------------------

void ofApp::drawHI(float xPos, float yPos, float scale){
    
ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    
    //-----------------h------------------------
    ofBeginShape();
    ofVertex(0,0);
    ofVertex(30, 0);
    ofVertex(30+(Mousereact/2.5),40);
    ofVertex(70+(Mousereact/2.5),40);
    ofVertex(70,0);
    ofVertex(100,0);
    ofVertex(100+Mousereact,100); // moved Mousereact parameters to update. Was this a good idea?
    ofVertex(70+Mousereact,100);
    ofVertex(70+(Mousereact/2),60);
    ofVertex(30+(Mousereact/2),60);
    ofVertex(30+Mousereact,100);
    ofVertex(0+Mousereact,100);
    ofVertex(0,0);
    ofEndShape();

ofPushMatrix();
        ofTranslate(110, 0);
        ofBeginShape();
        ofVertex(0,0);
        ofVertex(30, 0);
        ofVertex(30+Mousereact,100);
        ofVertex(0+Mousereact,100);
        ofVertex(0,0);
        ofEndShape();
        ofPopMatrix();
ofPopMatrix();
}

void ofApp::drawanL(float xPos, float yPos, float scale){
    
ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    ofBeginShape();
    ofVertex(0,0);
    ofVertex(30, 0);
    ofVertex(30+(Mousereact/1.4),70);
    ofVertex(90+(Mousereact),70);
    ofVertex(90+Mousereact,100); // moved Mousereact parameters to update. Was this a good idea?
    ofVertex(0+Mousereact,100);
    ofVertex(0,0);
    ofEndShape();
ofPopMatrix();
}


//--------------------------draw a U--------
void ofApp::drawaU(float xPos, float yPos, float scale){
ofPushMatrix();
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    ofFill();
    ofRect(0,0,25,50);
    ofRect(75, 0, 25, 50);
    ofCircle(50,50,50);
ofPopMatrix();
}

// draw an M --------------------------
void ofApp::drawanM(float xPos, float yPos, float scale){
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    ofNoFill();
    ofSetColor(myOutlines);
    ofSetLineWidth(MyOutlineWidth);
    ofBeginShape();
    ofVertex(0,100);
    ofVertex(50,0);
    ofVertex(100,100);
    ofVertex(80,100);
    ofVertex(50,35);
    ofVertex(20,100);
    ofVertex(0,100);
    ofEndShape();

    ofPushMatrix();
        ofTranslate(50, 00);
        ofNoFill();
        ofSetColor(myOutlines);
        ofSetLineWidth(MyOutlineWidth);
        ofBeginShape();
        ofVertex(0,100);
        ofVertex(50,0);
        ofVertex(100,100);
        ofVertex(80,100);
        ofVertex(50,35);
        ofVertex(20,100);
        ofVertex(0,100);
        ofEndShape();
    ofPopMatrix();
}

// ------------------- draw a circle with pink polka dots inside
void ofApp::drawaPolkaDotO(float xPos, float yPos, float scale){
    
ofPushMatrix(); // we're going to push this thing
    ofTranslate(xPos, yPos); // push it this far. Why is this a variable and not a fixed number?
    ofScale(scale, scale); //scale it this much
    float CircCenterBX, CircCenterBY, CircRadius;
    CircCenterBX = 0;
    CircCenterBY = 0;
    CircRadius = 100; // why am i defining this here?
    ofSetColor(myOutlines);
    ofNoFill();
    ofSetLineWidth(6);
    ofCircle(CircCenterBX,CircCenterBY,CircRadius); // centerx, centery, radius - this is drawing the black outline to be at 0,0,100 radius
    ofSetColor(yellow); //now i'm doing the polka dots
    ofFill();
    float circleX = CircCenterBY;
    float circleY = CircCenterBX;
    float circleRadius = CircRadius;
    for (int i = -circleRadius; i < circleRadius; i = i + 20)
        { //scoot it over 20 each time
        for (int k = -circleRadius; k < circleRadius; k = k + 20)
            { //scoot it over 20 each time
            float distance = ofDist(CircCenterBX, CircCenterBY, i, k);
            if (distance < circleRadius-4){
                if ((k/20) % 2 == 0) {     // is k even or not ?
                    ofCircle(k,i,4);
                } else {
                    ofCircle(k,i + 10,4);
                    }
                }
            }
        }
    
 ofPopMatrix(); //now we're done, reset coordinates to normal
    
}



//--------------------------------------------------------------
void ofApp::setup(){
    
    sprintf(eventString, "HELLO, hit 'W' or 'A'");
    NTSAkkhara.loadFont("NTSAkkhara.ttf", 52); //font size

    sprintf(eventStringB, "1  2  3  4  5  6  7  8  9  10");
    NTSAkkhara.loadFont("NTSAkkhara.ttf", 32); //font size
    
    
    img.allocate(256, 256, OF_IMAGE_COLOR_ALPHA);
    img.loadImage("Cage_TenRules.jpg");
    FU.loadImage("FU.png");
    
    imggrad.allocate(800 ,800,OF_IMAGE_COLOR);
    drawGradient();

    //    ofEnableAntiAliasing();
    ofSetLineWidth(2);
    last = ofGetElapsedTimeMillis();
    col.setHsb(0,255,255);
    yellow.setHex(0xF9FF4B);
    Myradius=10;

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetFrameRate(30);
    ofSetCircleResolution(50);
//    Tweenzor::update(ofGetElapsedTimeMillis());
    
    float skewFactor = .1;
    Mousereact = ((ofGetWidth()/2) - mouseX) * skewFactor;
    ofMap(mouseX, 0, ofGetWidth(), -5, 5);   // true = stay in range of 0-1 // float value, float inputMin, float inputMax, float outputMin, float outputMax)
//    
//    
//    if (mouseX <= ofGetWidth()/2){
//        Mousereact = Mousereact*2;
//    } else {                       // we are one of two conditions here...
//        Mousereact = Mousereact*-2;
//    }
}

//-----------DRAW---------------DRAW----------------DRAW-----------DRAW---------------DRAW---------DRAW-------------
void ofApp::draw(){
    
    ofBackgroundGradient(Gold, Aqua, OF_GRADIENT_LINEAR);
    
        ofFill();
    ofSetColor(MedAqua);
    if (ofGetElapsedTimef() <= 10){
        ofTriangle(10*ofGetElapsedTimef(),100,10*ofGetElapsedTimef()+50,150,10*ofGetElapsedTimef(),200);
    }
 
//-----------mesh------square--------slowly---------dropping-----------------------------------------------------
    ofPushMatrix();
    //  ofRotate(2*ofGetElapsedTimef());
    ofTranslate(-200, -600+2*ofGetElapsedTimef());
    ofScale(7,7);
    
    ofMesh tempMesh;
    tempMesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    tempMesh.addVertex( ofPoint(100,100));
    tempMesh.addColor(Gold);
    
    tempMesh.addVertex( ofPoint(200,100));
    tempMesh.addColor(Gold);
    
    tempMesh.addVertex( ofPoint(100,200));
    tempMesh.addColor(Aqua);
    
    tempMesh.addVertex( ofPoint(200,200));
    tempMesh.addColor(Aqua);
    
    tempMesh.draw();
    ofPopMatrix();

    
//-----------------------bg ball drops----------------------------------------------------------------------
    ofSetColor(col);
    if(ofGetElapsedTimeMillis() - last > 50)
        col.setHue(counter % 256); // what does the division sign do?
    counter ++;
    last = ofGetElapsedTimeMillis();
    ofFill();
    float rando = ofRandom(0, 100); // random number from 0 to 100
    
    for (int l = 0; l<30; l++) {
        for (int m = 0; m<10; m++) {
            ofCircle(500*m,-1000+20*ofGetElapsedTimef()+(l*500),Myradius*2);
        }
    }
    
    for (int n = 0; n<30; n++) {
        for (int nb = 0; nb<10; nb++) {
            ofCircle(250+500*nb,-250+20*ofGetElapsedTimef()+(n*500),Myradius);
        }
    }

    
//---------------------------black box at bottom of screen-------------------------------------------
    ofSetColor(0);
    ofRect(0,ofGetHeight()-100,ofGetWidth(),100);


//-----------------------------Circle nav------------------------------------
    ofColor myColor;    // create a color variable
    int randomNumber = (int) ofRandom(0,100);
    int navcirc;
    int addcolor = 0;
    float distance = 100;
    int circlesTotal = 10;
    int addedcolorR = 100;
    int addedcolorG = 100;
    int addedcolorB = 100;
    for (navcirc = 0; navcirc < circlesTotal; navcirc++) {
        ofSetColor(myColor);    // set the draw color to this.
        myColor.setHsb(ofMap(navcirc, 0, circlesTotal, 0, 255), 190, 255);     // set it's color via hsb, map navcirc to 0 to 255 (ie, go one way around the circle during the for loop)
        ofCircle(-60*navcirc+ofGetWidth()-40,ofGetHeight()-60,20);
        int currentCircle = circlesTotal - navcirc;
        ofSetColor(0);
        NTSAkkhara.drawString(ofToString(currentCircle), -60*navcirc+ofGetWidth()-50,ofGetHeight()-50);
        }
    

    
    
//---------this was a failed experiement to try and get the cylinder length to oscillate-----------
//    float ConstMove;
//    float OsConstMove;
//    float ConstMove2;
//    float GrowingNumber;
//    ConstMove = 25 * ofGetElapsedTimef();
//    ConstMove2 = OsConstMove - 20;
//    GrowingNumber = 25 * ofGetElapsedTimef();
//    cout << GrowingNumber << " "<< endl;
//    if (GrowingNumber <= 100) {
//        OsConstMove = ConstMove;
//        }
//    else if (GrowingNumber >= 100){
//        OsConstMove = ConstMove2;
//        }
//    ofDrawCylinder(mouseX, mouseY, 20, OsConstMove);
    
    
    
   
//--------------------main draw stuff-------------------------
    
ofSetColor(255);
NTSAkkhara.drawString(eventString, 600,50); // id like to have this type's width be ofGetWidth()/2 but it doesnt seem to be centered, i  think because the line of type's axis point is not in the center, but in the top left.

img.draw(600,400,400,600); // draw cage's rules
FU.draw(mouseX, mouseY, 40,40); // draw afuck you sign
    


ofPushMatrix();
    ofTranslate(400, 200);
    drawaPolkaDotO(750, 50, 0.5);
    drawHI(270, 00, 1);
    drawanH(900, 00, 1);
    drawanM(100, 00, 1);
    drawanL(350, 00, 1);
    drawanL(450, 00, 1);
    
ofPopMatrix();
    
   
}

// -----------------------------------------what is this?
void ofApp::drawGradient() {
    for (int x=0; x<200; x++) {
        for (int y=0; y<300; y++) {
            imggrad.setColor(x, y, ofColor::fromHsb(255, y, 255));
        }
    }
    imggrad.update();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key==119) // 'w' key
    {
        Myradius--;
    }
    
    if(key=='a')
    {
        Myradius++;
    }
    if(key=='m')
    {
        drawanM(40, 40, 3);
    }
    
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
    drawanM(40, 40, 3);
    
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
