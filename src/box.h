/*
 * $Revision: 1.2 $
 * $Author: descent $
 * $Date: 2002/07/17 02:49:08 $
 * $Id: box.h,v 1.2 2002/07/17 02:49:08 descent Exp $
 * �{���\��G�e�X�~�ءB���Y�r��
*/
#ifndef BOX_H
#define BOX_H

#include "shadow_view.h"

#include <string>

namespace DS
{
 enum FrameKind {SL=0,DL}; // SL is single line , DL is double line
 class Box : public DS::ShadowView
 {
  public:
   Box(int x1,int y1,int x2,int y2,short f,short b,FrameKind frame_kind=DL,const std::string &title=""):ShadowView(x1,y1,x2,y2,f,b)
   {
    _frame_kind=frame_kind;
    _frame_flag=true;
   }
   void set_frame_kind(FrameKind frame_kind){_frame_kind=frame_kind;}
   void set_frame_flag(bool flag){_frame_flag=flag;}
   void set_title(const std::string &title){_title=" "+title+" ";}
   inline void show();


  protected:
   FrameKind _frame_kind; // �����~�ت������O��u�٬O���u
   bool _frame_flag; //�����n���n�e�X�~�ت��X�СAframe_flag=true ��ܭn�e�X�~��
   //bool _title_flag; //�����n���n�e�X�~�ت��X�СAframe_flag=true ��ܭn�e�X�~��
   std::string _title; //���Y�r��

   void draw_frame();
   void draw_title();

   // �����B�����P�|�Ө�
   static unsigned char _tl[]; // top left
   static unsigned char _tr[]; // top right
   static unsigned char _bl[]; // bottom left
   static unsigned char _br[]; // bottom right
   static unsigned char _hl[]; // �������u
   static unsigned char _vl[]; // �������u
 };

 inline void Box::show()
 {
  if (_frame_flag==true)
   draw_frame();
  draw_title(); // fraw_title() �n�b draw_frame() ����A�_�h���Y�r��|�Q�~���л\

  ShadowView::show();

 }
} // end namespace DS


#endif
