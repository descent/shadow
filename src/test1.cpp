#include "controller.h"
#include "model.h"
#include <time.h>

class MyApp :public DS::Model     // �D���ε{���Ҳ�
{
 public:
  MyApp();
  // �ѩ�ڭ̥u���� Controller �ҥH�ڭ̥u���Ыŧi�o��Ө禡
  int key_event( DS::Event &event );
};

MyApp::MyApp()
{
 desktop->link( this );  // �N���ҲջP�ୱ�쵲
 //timer->apply( this ,1 );  // ���եӽ� Timer and Idler ��� ���
 //idler->apply( this );
}

int MyApp::key_event( DS::Event &event )
{
 //if( event.keyDown.keyCode == kbAltX )  //�Y�ϥΪ̫��U Alt-X ,�h�{�����}
 if( event.keydown() == 'q' )  //�Y�ϥΪ̫��U Alt-X ,�h�{�����}
  event.set_event(DS::evExit);
 else
 {
  mvprintw(10,20,"%c",event.keydown());
  refresh();
 }
 return 1;
}

int main( )
{
 try
 {
  initscr();
  DS::Controller drive;  // �зǵ{���g�k ,�ٺ⤣���a !!
  new MyApp;       // ���� View �� Model �n�V�O ,�[�o !! (-:
  desktop->show();
  //signal(SIGALRM,catch_alarm);
  drive.run();
  endwin();
 } // end try
 catch(...)
 {
  
  endwin();
 }
}
