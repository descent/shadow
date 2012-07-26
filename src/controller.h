/*
 * $Revision$
 * $Author$
 * $Date$
 * $Id$
 * �{���\��G�o�O controller class �Ψӱ����ӵ{�����y�{
 */
#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "desktop.h"
//#include "idler.h"
#include "keyboard.h"
#include "timer.h"
#include "controller_item.h"

#include <vector>
#include <queue>



// �H�U�����Ϊ���
extern DS::Desktop* desktop;  // �ୱ���Ϊ���
//extern  DoubleList* msgQueue; // �T����C����
//extern DoubleList* contrlQueue; // �ƥ󲣥;���C
//extern std::vector<CObject *> contrlQueue;
//extern Timer *timer; // �ɶ��ƥ󲣥;������Ϊ���
//extern Idler *idler; // �Ŷ��ƥ󲣥;������Ϊ���
extern DS::Keyboard *keyboard; // ��L�ƥ󲣥;������Ϊ���
extern DS::Timer *timer; // ��L�ƥ󲣥;�
extern std::vector<DS::ControllerItem *> controller_queue;
extern std::queue<DS::Event *> event_queue;


namespace DS
{
 class Controller
 {
  public:
   Controller();
   //virtual unsigned is()  {  return ControllerCls;  }
   virtual int run();
   // ���禡�t�d�}�l��ӰT���j�骺�ʧ@�C���y�ܻ��G�{���Ѧ��}�l�����~�����T
   // ���C�Y��������դ@�I ,�b main() �� ,�b new ���@�ǥ��n������� ,�N�O�I
   // �s�o�ӵ{���Ұʪ��C�åѦ��禡�I�s pool() �� View �� fromControler() �禡
   virtual void pool()  // ���ߦU�ƥ󲣥;����Ƶ{��
   {
    std::vector<ControllerItem *> :: iterator it;
    for ( it=controller_queue.begin() ; it !=controller_queue.end() ; it++)
     (*it)->pool() ;
     //dynamic_cast<ControllerItem*>(*it)->pool() ;
   }
   virtual int addController( ControllerItem* controller );
   // �W�[�ƥ󲣥;��ܨƥ󲣥;���C����
   virtual ~Controller();
  protected:
 } ;

inline int Controller::addController(ControllerItem * controller )
{
  // ���禡�u��ª��N�ƥ󲣥;���J�ƥ󲣥;���C���Ӥw
   //contrlQueue->add( controller );
 controller_queue.push_back( controller );
   return 1;
}

} // end namespace DS



#endif
