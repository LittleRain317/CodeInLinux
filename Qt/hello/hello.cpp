#include <QApplication>
#include <QLabel>
int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	QLabel * label = new QLabel("<ol>列表"
		       "<li>第一</li>"
	       		"<li>第二</li>"
	 		"</ol>");		
	label->show();
	return app.exec();
}
