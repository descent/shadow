/*
 * $Revision$
 * $Author$
 * $Date$
 * $Id$
 * �{���\��G��L�ƥ󲣥;�
 */
#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "event.h"
#include "controller_item.h"

#include <curses.h>

namespace DS
{
 class Keyboard : public ControllerItem
 {
  public:
   Keyboard( ){}
   void getKeyEvent( DS::Event *event );  // �����禡 ,����L�r��
   int pool();
   ~Keyboard(){}
 } ;

} // end namespace DS


#endif
