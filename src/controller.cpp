
#include "controller.h"
#include "event.h"

// �H�U�����Ϊ��󪺩w�q
DS::Desktop *desktop; // �ୱ����
//DoubleList* msgQueue; // �ƥ�s���C
//DoubleList* contrlQueue; // �ƥ󲣥;���C
std::vector<DS::ControllerItem *> controller_queue;
std::queue<DS::Event *> event_queue;

//Timer* timer; // �ɶ��ƥ󲣥;�
//Idler* idler; // �t�ΪŶ��ƥ󲣥;�
DS::Keyboard *keyboard; // ��L�ƥ󲣥;�
DS::Timer *timer; // ��L�ƥ󲣥;�

DS::Controller::Controller()
{
 desktop = new DS::Desktop(COLOR_WHITE,COLOR_BLUE,0,0,COLS,LINES);
  // Controller ���c��̭t�d���ͩҦ����Ϊ���ΦU�ƥ󲣥;�
   //msgQueue = new DoubleList();
   //contrlQueue = new DoubleList();
   //idler = new Idler();
   keyboard = new Keyboard();
   timer = new Timer();
   // �ƥ󲣥;��ϥͫ�A�@�Ӥ@�ӥ[�J�ƥ󲣥;���C��
   //contrlQueue->add( keyboard );
   //contrlQueue->add( timer );
   //contrlQueue->add( idler );
   controller_queue.push_back( keyboard );
   controller_queue.push_back( timer );
   //contrlQueue.push_back( idler );
   // menubar ���C��� Color ���O�����Ϊ��� menubarColor �ӨM�w�C���s��b userdef.cpp �C
   // �o�O�@�ӥi�ѨϥΪ̭ק諸�ɮסA�i�b�{�� link �ɡA�@�_ link �_�ӡC
   //menubar = new Menubar( menubarColor.textColor, menubarColor.bkGroundColor,
   //menubarColor.revTxtColor,menubarColor.revBkGdColor,menubarColor.hotkeyColor );
   // statusLine ���C��P�˥� userdef.cpp �������Ϊ��� statusLineClr �M�w
   //statusLine = new StatusLine(  statusLineClr.textColor, statusLineClr.bkGroundColor,statusLineClr.hotkeyColor );

}

int DS::Controller::run()
{
 curs_set(0); // hide cursor
  //_setcursortype( _NOCURSOR ); // �N�������

 // ��کҦ��{�����ߤ@�D�ʪ����� ---- �ƥ���߰j��
 while(true)
 {
  pool();
  //for (int i=0 ; i < event_queue.size() ; i++)
  {
   //DS::Event* event = event_queue[i];
   if (!event_queue.empty())
   {

    DS::Event* event = event_queue.front();
    event_queue.pop();
    desktop->from_controller( *event );
    if( event->what() == DS::evExit )
     if( desktop->close() )
      goto end_loop;
   }
  }
 } // end while(true)
 end_loop:
 return 1;
}


DS::Controller::~Controller()
{
 delete desktop;
  //delete msgQueue;  // �b��C��������Ѧ�C�ۦ���h
  //delete contrlQueue;
  //delete menubar;
  //delete statusLine;
}
