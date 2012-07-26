//***************************************************************
//*              Name of File : timer.cpp                       *
//*              for :  Time-Event generator                    *
//*                  by : �j�M�w                                *
//***************************************************************

#include "timer.h"

#include <algorithm>
#include <fstream>

// anonymous namespace ��ܦb�� namespace �����ܼƥu��Φb���ɮפ���
namespace
{
 //const int TIME_UP=1;
 unsigned long int cur_time=0;
 //bool timer_on=false; 
}

bool DS::Timer::timer_on;


DS::TimerCounter::TimerCounter( Model *app, unsigned long msec ):_cur_time(0)
{
 _model = app;
 _event.set_event(DS::evTimer);
 _time=msec;

}

// �C 1 microsecond �I�s�@��,�� static �ܼ� time ���ҳ]�w���ɶ� _time,
// �I�s linkApp �� from_controller()
void DS::TimerCounter::go() 
{
 static int time=0;
 //_cur_time=cur_time;
 //if (_cur_time==_time)
 static std::ofstream f("time"); 
 if (time==_time)
 {
  //f << _time << std::endl;
  _model->from_control(_event);
  //_cur_time=0;
  time=0;
 }
 else
 {
  ++time;
  f << time << std::endl;
 }
}

DS::Timer::Timer()
{
 //DS::alarm(TIME_UP);
 //timer_on=false; 

 signal(SIGALRM,catch_alarm);
 Timer::alarm(TIME_UP);
}

int DS::Timer::pool()
{
 if (timer_on == true)  // timer_on �Y�� true �A��� 1 microsecond �����j�w��
 {
  std::vector<TimerCounter *> :: iterator it;
  for (it = _applier.begin() ; it != _applier.end() ; it++)
   (*it)->go();
  timer_on=false;
 }
 return 1;
}

void DS::Timer::apply( Model *app, unsigned int msec )
{
 // �C�h�@�ӥӽЪ� ,�K new �@�� TimerCounter �P���쵲 ,�M��[�J�ӽЪ̦�C���Y�i
 _applier.push_back( new TimerCounter( app ,msec ) );
}


// static function
void DS::Timer::catch_alarm(int sig)
{
 timer_on=true;
 ++cur_time;
 //DS::alarm(TIME_UP);
 signal(sig,catch_alarm);
 Timer::alarm(TIME_UP);
}


// �]�w�p�ɾ��H microsecond �����
// static function
unsigned long int DS::Timer::alarm(unsigned long int msec)
{
 struct itimerval old_time,new_time;
 new_time.it_interval.tv_usec=0;
 new_time.it_interval.tv_sec=0;
 new_time.it_value.tv_usec=msec;
 new_time.it_value.tv_sec=0;
 if (setitimer(ITIMER_REAL,&new_time,&old_time) < 0) // error
  return 0;
 else
  return old_time.it_value.tv_usec;
}
