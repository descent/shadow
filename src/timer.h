/*
 * $Revision$
 * $Author$
 * $Id$
 * $Date$
 * function : �ɶ����;��A�ҥӽЪ��ɶ��H�����
 */

#ifndef TIMER_H
#define TIMER_H

//#include "contitem.h"
//#include "type.h"
//#include "struct.h"
//#include "dlist.h"
#include "model.h"
#include "controller_item.h"
#include "event.h"

#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#include <vector>

// TimerCounter ���@�]�p�ΨӺ޲z�C�@�Ӯɶ��ӽЪ̪����O�C���餤�p���F�ҥN���Ҳ�
// �Υ��ҥӽЪ��ɶ����j ,�C 1/18 ��I�s�@�� ++ �禡 ,������۰ʲέp�ɶ� ,�Ӯɶ�
// �@�� ,�۰ʱN�T���ǵ��ҥN������ ,���ݵ{���]�p�̦A�ޤ�
// �Q�کҧ�諸 timer �ثe�u��H�����ӥӽЮɶ�

// function object
/*
class FindModel
{
 public:
  bool operator(const TimerCounter & t1,const TimerCounter & t2)
  {
  }

};
*/

namespace DS
{
 // �]�w�p�ɾ��H microsecond �����
 //void catch_alarm(int sig);

 class TimerCounter
 {
  //friend void DS::catch_alarm(int sig);
  public:
   TimerCounter( Model *app ,unsigned long msec );
   // app ���ɶ���ɩI�s���Ҳ�, msec �� microsecond
   //virtual unsigned is()  {  return TimerCounterCls;  }
   void go(); //�C 1 ��I�s�@�� ,���Ƥ@��,�۰ʩI�s linkApp �� from_controller()
   //const Model* getModel() { return _linkApp;  }
   TimerCounter() {}

  private:
   unsigned long _time; // Model �ӽЪ��ɶ��A�H microsecond �����
   unsigned long _cur_time; // �ثe�ֿn���ɶ��A�H microsecond �����

   DS::Model *_model;   // �O�s�P���쵲�� Model �Ҳ�
   DS::Event _event;  // �����ϥΤ��ƥ�Awhat �O���� evTimer
 }; // end class TimerCounter

 class Timer : public ControllerItem  // �ɶ����ƥ󲣥;�
 {
  public:
   static const int TIME_UP=1;
   static void catch_alarm(int sig);
   static unsigned long int alarm(unsigned long int msec);
   Timer();
   //virtual unsigned is()  {  return TimerCls;  }
   virtual int pool();
   void apply( Model *app, unsigned int msec );
       // ���禡�� Model �ӽ� Timer �ƥ󤧥�
       // app ���ӽФ� Model �A sec ���I�s�����j,��쬰��
   void remove( Model *app )  // �M������ӽЪ� Model
   {
   }
  private:
   std::vector<TimerCounter *> _applier;
   static bool timer_on;

 };
} // end namespace DS





#endif
