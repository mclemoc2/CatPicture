#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CatPictureApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();

private:
	float brightness, secondary;
};

void CatPictureApp::setup()
{
	brightness = 1.0f;
	secondary = 0.0f;
}

void CatPictureApp::mouseDown( MouseEvent event )
{
}

void CatPictureApp::update()
{
	//Try an additional color
	brightness -= 0.01;
	secondary += 0.01;

	if (brightness < 0.0f){
		brightness = 1.0f;
	}
	if(secondary > 0.0f){
		secondary = 0.0f;
	}
}

void CatPictureApp::draw()
{
	// clear out the window with black
	gl::clear( Color( brightness, secondary, brightness ) ); 
}

CINDER_APP_BASIC( CatPictureApp, RendererGl )
