#include "preCompile.h"
#include "app.h"

int main(int argc, char* argv[])
{
	g_app = new App;
	g_app->init();
	g_app->run();
	g_app->uninit();
	delete g_app;
	return 0;
};
