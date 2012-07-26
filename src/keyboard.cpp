#include "keyboard.h"
#include "controller.h"

void DS::Keyboard::getKeyEvent( DS::Event *event)
{
 cbreak();
 noecho();
 int tenths=20 ; // must in 1 ~ 255
 //halfdelay(tenths);
 #ifndef DEBUG
  nodelay(stdscr,true);
 #endif
 int key;
 if ((key=getch())==ERR) // no key to be pressed
 {
  event->set_event(DS::evNothing);
  //event->what = evMessage;
 }
 else
 {
  event->set_event(DS::evKeyDown);
  event->set_keydown(key);
  //event->what = evKeyDown;
  //(event->keyDown).key = key;
 }
 
}

int DS::Keyboard::pool()
{
 DS::Event *event = new DS::Event();
 getKeyEvent(event);
 if( event->what() == evKeyDown )  // �Y�����䲣�� ,�h�N���ƥ��J�T����C��
 {   
  //msgQueue->add( event );
  //event_queue.push_back(event);
  event_queue.push(event);
  return 1;            
 }
 else
 {    
  delete event;      // �Y�L�A�h���h��~�� new ���ƥ�C
  return 0;    
 }
}
