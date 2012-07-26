/*
 * $Revision: 1.2 $
 * $Author: descent $
 * $Date: 2002/07/17 02:49:08 $
 * $Id: lview.h,v 1.2 2002/07/17 02:49:08 descent Exp $
 * �{���\��GLView �� View �� base class�A��\��u�Ψӵe�X�@�ӯx�ΡA�ӯx��
 *           �� View ���j�p�C
*/
#ifndef LVIEW_H
#define LVIEW_H

#include "geometry.h"
#include "color_pair.h"

#include <fstream>

namespace DS
{
 class LView
 {
  public:
   DS::COLOR_PAIR_TYPE color_pair_num(){return _color_pair_num;}

   LView(int x1,int y1,int x2,int y2,short f,short b):_rect(x1,y1,x2,y2)
   {
    _color_pair_num=_color_pair.get_color_pair(f,b);
   }

   virtual void show()
   {
    draw_rect();
    //refresh();
   }

  protected:
   void draw_rect()
   {
    unsigned char bg_char=176;
    bg_char=' ';
    //bg_char='O';
    for (int x=_rect.tl().x()+1 ; x < _rect.br().x()-1 ; x++) // draw x
     for (int y=_rect.tl().y()+1 ; y < _rect.br().y()-1 ; y++) // draw y
     {
       mvaddch(y,x,(bg_char >= 128 ? ( bg_char | A_ALTCHARSET) : (bg_char) ) | /*A_BOLD |*/ COLOR_PAIR(_color_pair_num));
      }
    std::ofstream log_file("lview.log");
    log_file << _color_pair_num << std::endl;

   }
   DS::ColorPair _color_pair;
   DS::Rect _rect;
   DS::COLOR_PAIR_TYPE _color_pair_num;

 };



} // end namespace DS

#endif 
