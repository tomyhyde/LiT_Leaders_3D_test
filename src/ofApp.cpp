#include "ofApp.h"
#define NUM_OF_POLYGONS 200 //ここに書いた数字が全部に適用されます
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofEnableDepthTest();//実際の描画上での距離感（深度）を実装
    ofToggleFullscreen();
    for (int i = 0; i< NUM_OF_POLYGONS; i++){
        polygons.push_back(new Polygon3d); //push_back = 一番最後に入れるという意味
        
    }
    for (int i = 0; i< NUM_OF_POLYGONS; i++){
        cout << i <<";"<<//";"をウィンドウ内に書いて、数値をみやすく
                polygons.at(i)->mPolygonPosition <<endl;
        //靴箱の１−２００番にきちんと生成されているかをcout<<endlで確認
        //at polygonの計算式の中の(i)の数値を確認
        //-> 計算式の中の項目を指定 ポインターを勉強しましょう　アロー演算子
        //
        
        
    }
    

}

//--------------------------------------------------------------
void ofApp::update(){
//    camera.setPosition(200*cos((double)ofGetElapsedTimeMillis()/500),
//                       0,
//                       200*sin((double)ofGetElapsedTimeMillis()/500));
//    camera.lookAt(ofVec3f(0,0,0));
    
    
    //半径１の円において
    //(x,y)=(cosθ,sinθ)ということは、θの値を増やしていけば一周する
    //1秒で1000回回ると早すぎるので、/200(整数)することで速度をコントロール
    //一定の整数で割り続けると少数が出てくるので、(double)をつけることで少数を処理できるようにする
    //そうすると滑らかにカメラを回せる
    //今の状態では半径１なので、200*をすることで円の半径を200にする
    
        camera.setPosition(3000*cos((double)ofGetElapsedTimeMillis()/1500),
                           0,
                           3000*sin((double)ofGetElapsedTimeMillis()/1500));
        camera.lookAt(ofVec3f(0,0,0));
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2,0);

    
    light.enable();
    camera.begin();
    
//    box.setPosition(0, 0, 0);
//    box.set(100);
//    ofSetColor(255);
//    box.drawWireframe();
    
//    Polygon3d polygon1 = Polygon3d(); //ここでヘッダーファイルを初期化してる 新しく描きますよー
//    polygon1.draw();
    
    for (int i = 9; i < NUM_OF_POLYGONS; i++) {
        ofSetColor(ofRandom(255),ofRandom(255),ofRandom(255));
        polygons.at(i)->draw();
        ofSetColor(255, 255, 255);
        //ofLine(ofVec3f(0, 0, 0), polygons.at(i)->mPolygonPosition);
        //とりあえず中心からそれぞれの図形にラインを引きます
        ofLine(polygons.at(i-1)->mPolygonPosition, polygons.at(i)->mPolygonPosition);
        //これで形成された順番にそれぞれを線で結びます
    }
    
    
    camera.end();
    light.disable();
    
    
    
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
