#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Sketch1App : public App {
  public:
	void setup() override;
	void mouseDown( MouseEvent event ) override;
	void update() override;
	void draw() override;
};

void Sketch1App::setup()
{
}

void Sketch1App::mouseDown( MouseEvent event )
{
}

void Sketch1App::update()
{
}

void Sketch1App::draw()
{
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP( Sketch1App, RendererGl )
