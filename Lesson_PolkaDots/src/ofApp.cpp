#include "ofApp.h"

void ofApp::drawanH(float xPos, float yPos, float scale){
// -------------------------draw an H--------------------------------

//-------------triangles-------------------
ofFill();
ofSetColor(MedAqua);
if (ofGetElapsedTimef() <= 10){
    ofTriangle(10*ofGetElapsedTimef(),100,10*ofGetElapsedTimef()+50,150,10*ofGetElapsedTimef(),200);
}

ofPushMatrix();
ofTranslate(00, 0);
ofScale(.2, .2);
float triangleX = 100;

ofSetColor(MedAqua);

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

float animateAtime = 1.0;
float animateBtime = 1.0;  // assume that b is first
float totalAnimatetime = animateAtime + animateBtime;
float currentTime = ofGetElapsedTimef(); // get the current time
float timeInAnimation = currentTime;
while (timeInAnimation > totalAnimatetime){
    timeInAnimation -= totalAnimatetime; // this is like fmod for time (I can explain)
}

//now we've gotten a value that counts up to 2 seconds every two seconds.  Now some logic to figure out what pct of a and b we've done given time

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
//    ofLine(c+500,60,b+500,60); // why why why?
ofLine(510,a,510,b);
}
//-----------------HI------------------------------------------------------
void ofApp::drawHI(float xPos, float yPos, float scale){
if (mouseX <= ofGetWidth()/2){
    Mousereact = mouseX-(mouseX-1)*2;
} else {                       // we are one of two conditions here...
    Mousereact = mouseX-(mouseX-1)*2;
}
float skewFactor;
skewFactor = .2;
Mousereact = ((ofGetWidth()/2) - mouseX) * skewFactor;


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
    ofVertex(100+Mousereact,100);
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
ofVertex(40, 0);
ofVertex(40+Mousereact,100);
ofVertex(0+Mousereact,100);
ofVertex(0,0);
ofEndShape();
ofPopMatrix();


}

//--------------------------draw a U--------
void ofApp::drawaU(float xPos, float yPos, float scale){
ofPushMatrix();
ofTranslate(0, 0);
ofFill();
ofRect(0,0,25,50);
ofRect(75, 0, 25, 50);
ofCircle(50,50,50);
ofPopMatrix();
}

// draw an M --------------------------
void ofApp::drawanM(float xPos, float yPos, float scale){
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

void ofApp::drawPinkPolkaCircle(float xPos, float yPos, float scale){
    
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
    
    for (int i = -circleRadius; i < circleRadius; i = i + 20){ //scoot it over 20 each time
        for (int k = -circleRadius; k < circleRadius; k = k + 20){ //scoot it over 20 each time
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

    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSetFrameRate(30);
    ofSetCircleResolution(50);
//    Tweenzor::update(ofGetElapsedTimeMillis());
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
 
    ofBackgroundGradient(Gold, Aqua, OF_GRADIENT_LINEAR);
    
    //------mesh----------------------------------
    ofPushMatrix();
    ofTranslate(00, -600+ofGetElapsedTimef());
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
  
//---------------------------------------------------------------------
    
    ofSetColor(255);
    NTSAkkhara.drawString(eventString, 600,50);
    
    img.draw(400,400,400,600); // draw cage's rules


    ofSetColor(col);
    if(ofGetElapsedTimeMillis() - last > 50)
    {
        col.setHue(counter % 256);
        counter ++;
        last = ofGetElapsedTimeMillis();
    }
//-------balls be dropping, y0------------------
    ofFill();
    float rando = ofRandom(0, 100);
//    for (int i = 0; i<10; i++) {
//        for (int j = 0; j<10; j++) {
//        ofCircle(500*j,-1000+(i*500)+20*ofSignedNoise(ofGetElapsedTimef()+i*500),Myradius);
//        }
//    }
    
    for (int l = 0; l<20; l++) {
        for (int m = 0; m<10; m++) {
            ofCircle(500*m,-1000+20*ofGetElapsedTimef()+(l*500),Myradius);

        }
    }
 
//        ofCircle(700, -100+ 20*ofGetElapsedTimef(),Myradius);
//        ofCircle(1200, -70+20*ofGetElapsedTimef(),Myradius);
//        ofCircle(900,100+20*ofGetElapsedTimef(),Myradius); //gotta turn this into a forLoop


    
    FU.draw(mouseX, mouseY, 40,40); // draw afuck you sign
    


    
//    ofBackground(255);  // Clear the screen with a black color

//  ofSetColor(Blue);
//    ofFill();
   ofPushMatrix();
    ofTranslate(400, 200);
    drawPinkPolkaCircle(500, 50, 0.5);
    drawHI(300, 100, 3);
    drawanH(500, 100, 3);
    drawanM(600, 40, 3);
    drawaU(900, 400, 3);
    
    ofPopMatrix();
    
    drawHI(1,1,1);
    

    

    

    
//----------------draw a circle---------------------
//    
//    for (int i = 300; i < 400; i++) {
//        for (int j = 100; j < 200; j++) {
//            float distance = (ofPoint(i,j) - ofPoint(350,150)).length();
//            bool isWithinRadius = distance <= 50;
//            if (isWithinRadius){
//                ofSetColor(Gold);
//                ofRect(i,j,1,1);
//                
//            }
//        }
//    }
   
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
