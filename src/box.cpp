#include "box.h"

// single,double
// �Ĥ@�ӬO��u���A�ĤG�ӬO���u��
// �i�� _tl[SL] _tl[DL] �Өϥγ�����u��
unsigned char DS::Box::_tl[]={218,201};
unsigned char DS::Box::_tr[]={191,187};
unsigned char DS::Box::_bl[]={192,200};
unsigned char DS::Box::_br[]={217,188};
unsigned char DS::Box::_hl[]={196,205};
unsigned char DS::Box::_vl[]={179,186};

void DS::Box::draw_title()
{
 int width=_rect.br().x()-_rect.tl().x();
 // ���Y�r�ꪺ�e�׳̤j�u��� width-2�A�]���٦���Ө���

 if (_title.length() > width-2) // ���Y�r������
 {
  int i=0;
  for (i=0 ; i < width-2 -3 ; i++)
   mvaddch(_rect.tl().y(),_rect.tl().x()+1+i,_title[i]);

  for (int j=0 ; j < 3 ; j++)
   mvaddch(_rect.tl().y(),_rect.tl().x()+1+i+j,'.');

 }
 else // ���Y�r��p��n�e�b���a�誺����
 { // ���M�w�n�e�b���̡A�N�r��q�k�쥪�e�^��
  int pen_x=(width-2)/2 + (_title.length()/2) + 1 + _rect.tl().x();
  for (int i=0 ; i < _title.length() ; i++)
   mvaddch(_rect.tl().y(),pen_x-i,_title[_title.length()-1-i]);


 }


}

void DS::Box::draw_frame()
{
 // �e�~�ت������u
 for (int x=_rect.tl().x() ; x < _rect.br().x() ; x++) // draw x
 {
  /*
  mvaddch(_rect.tl().y(),x,ACS_HLINE | COLOR_PAIR(2));
  mvaddch(_rect.br().y()-1,x,ACS_HLINE | COLOR_PAIR(2));
  mvaddch(_rect.tl().y(),x,205 | A_ALTCHARSET | COLOR_PAIR(2));
  mvaddch(_rect.br().y()-1,x,205 | A_ALTCHARSET | COLOR_PAIR(2));
  */
  mvaddch(_rect.tl().y(),x,_hl[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
  mvaddch(_rect.br().y()-1,x,_hl[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
 }


 // �e�~�ت������u
 for (int y=_rect.tl().y() ; y < _rect.br().y() ; y++) // draw y
 {
  /*
  mvaddch(y,_rect.tl().x(),ACS_VLINE | COLOR_PAIR(2));
  mvaddch(y,_rect.br().x()-1,ACS_VLINE | COLOR_PAIR(2));
  mvaddch(y,_rect.tl().x(),186 | A_ALTCHARSET | COLOR_PAIR(2));
  mvaddch(y,_rect.br().x()-1,186 | A_ALTCHARSET | COLOR_PAIR(2));
  */
  mvaddch(y,_rect.tl().x(),_vl[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
  mvaddch(y,_rect.br().x()-1,_vl[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
 }
 //�e�|�Ө�
 /*
 mvaddch(_rect.tl().y(),_rect.tl().x(),ACS_ULCORNER | COLOR_PAIR(2));
 mvaddch(_rect.tl().y(),_rect.br().x()-1,ACS_URCORNER | COLOR_PAIR(2));
 mvaddch(_rect.br().y()-1,_rect.tl().x(),ACS_LLCORNER | COLOR_PAIR(2));
 mvaddch(_rect.br().y()-1,_rect.br().x()-1,ACS_LRCORNER | COLOR_PAIR(2));
 mvaddch(_rect.tl().y(),_rect.tl().x(),201 | A_ALTCHARSET | COLOR_PAIR(2));
 mvaddch(_rect.tl().y(),_rect.br().x()-1,187 | A_ALTCHARSET | COLOR_PAIR(2));
 mvaddch(_rect.br().y()-1,_rect.tl().x(),200 | A_ALTCHARSET | COLOR_PAIR(2));
 mvaddch(_rect.br().y()-1,_rect.br().x()-1,188 | A_ALTCHARSET | COLOR_PAIR(2));
 */
 mvaddch(_rect.tl().y(),_rect.tl().x(),_tl[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
 mvaddch(_rect.tl().y(),_rect.br().x()-1,_tr[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
 mvaddch(_rect.br().y()-1,_rect.tl().x(),_bl[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));
 mvaddch(_rect.br().y()-1,_rect.br().x()-1,_br[_frame_kind] | A_ALTCHARSET | COLOR_PAIR(_color_pair_num));



}
