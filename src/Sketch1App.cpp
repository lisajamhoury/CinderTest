#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"
#include "LeftSensor.hpp"
#include "RightSensor.hpp"
#include "PulseSensor1.hpp"
#include "PulseSensor2.hpp"
//#include "cinder/params/Params.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sketch1App : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
    
    //void setFrameRate();

    LeftSensor *mLeftSensor;
    RightSensor *mRightSensor;
    PulseSensor1 *mPulseSensor1;
    PulseSensor2 *mPulseSensor2;
};

void Sketch1App::setup()
{
    
    gl::clear( Color::black());
    gl::enableVerticalSync();
    
    // Full Screen
    getWindow()->setPos(0, 0);
    getWindow()->setBorderless();
    getWindow()->setAlwaysOnTop();
    getWindow()->spanAllDisplays();
    
    mLeftSensor = new LeftSensor();
    mRightSensor = new RightSensor();
    mPulseSensor1 = new PulseSensor1();
    mPulseSensor2 = new PulseSensor2();
}

void Sketch1App::mouseDown( MouseEvent event )
{
}

void Sketch1App::update()
{
    mLeftSensor->update();
    mRightSensor->update();
    mPulseSensor1->update();
    mPulseSensor2->update();
}

void Sketch1App::draw()
{
    mLeftSensor->draw();
    mRightSensor->draw();
    mPulseSensor1->draw();
    mPulseSensor2->draw();
}

CINDER_APP( Sketch1App, RendererGl,
           [&]( App::Settings *settings) {
               settings->setWindowSize(1440, 135);  // 11520, 1080 / 1440, 135
               //settings->setFullScreen(true);
               //settings->setHighDensityDisplayEnabled();
           })
           
