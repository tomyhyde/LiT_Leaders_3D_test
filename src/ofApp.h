#pragma once

#include "ofMain.h"

class Polygon3d { //新たにクラスを作る　クラスは型紙でここに道具を準備をしておく感覚　cppに書くのは内容
public:
    ofVec3f mPolygonPosition = ofVec3f(0,0,0); //どの位置にあるか
    int mPolygonSize = 0; //どんな大きさか
    int mPolygonType = 0; // 0:box, 1:Sphere どの形か
    
    Polygon3d(){
        mPolygonPosition = ofVec3f(ofRandom(-2000,2000),
                                   ofRandom(-2000,2000),
                                   ofRandom(-2000,2000));
        mPolygonSize = floor(ofRandom(10,100));
        mPolygonType = floor(ofRandom(2)); //floorで小数点以下切捨て
    
    
    
    }; //constructor　書かないと動かない　初期化関数
    ~Polygon3d(){}; //destructor
    void draw(){
        if (mPolygonType == 0){
            ofBoxPrimitive boxPrimitive;  //BoxPrimitiveというクラス　すでに用意されている
            boxPrimitive.setPosition(mPolygonPosition);
            boxPrimitive.set(mPolygonSize);
            boxPrimitive.drawWireframe();
        } else if (mPolygonType == 1){
            ofSpherePrimitive sphereprimitive;
            sphereprimitive.setPosition(mPolygonPosition);
            sphereprimitive.setRadius(mPolygonSize);
            sphereprimitive.drawWireframe();
        }
    }
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;
    ofEasyCam easycam;
    ofCamera camera;
    vector<Polygon3d *> polygons; //配列と同じように使える　番号のついた靴箱のようなもの
    
    
    
};;
