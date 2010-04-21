/*
 * $Revision: 1.2 $
 * $Author: descent $
 * $Date: 2002/07/17 02:49:08 $
 * $Id: port.h,v 1.2 2002/07/17 02:49:08 descent Exp $
 * �{���\��G Port ���P������p view �����e
*/
#ifndef PORT_H
#define PORT_H
#include <string>
#include <vector>
#include <curses.h>
#include "geometry.h"

namespace DS
{
/*
 class ChType
 {
  public:
   operator chtype*(){return &_ch;}
  private:
   chtype _ch;


 };
 typedef std::basic_string<ChType> ch_string;  // ch_string �� chtype �c�����r��
 */

 // �o�O�b port ����ܪ��r���A���C��A�ݩʵ��C
 class PortCh
 {
  public:
   PortCh(int ch=' ',int color_pair=0,int attr=0):_ch(ch),_color_pair(color_pair),_attribute(attr)
   {
   }
   int ch(){return _ch;}
   int color_pair(){return _color_pair;}
   int attribute(){return _attribute;}
  private:
   int _ch;
   int _color_pair;
   int _attribute;
 };

 typedef std::vector<PortCh> PortString;

 // �o�� function ��K�إ� PortString�A�n�ۤv��u�إߤ]�i�H�C
 // �� port_string �o�� reference �Ǧ^�ҫإߪ� PortString
 // make_port_string function �|�� str �[�W�ǤJ�� color pair and attribute
 // �ҥH�o�Ӧr��K�|���o�� color pair and attribute
 inline void make_port_string(const std::string &str,PortString &port_string,int color_pair=0,int attr=0)
 {
  port_string.clear();
  for (int i=0 ; i < str.length() ; i++)
   port_string.push_back(PortCh(str[i],color_pair,attr) );
 }

 class Port
 {
  public:
   Port(){_line=0,_column=0;}
   void draw(const DS::Rect &rect,int line=0,int column=0);
   void draw(int x1,int y1,int x2,int y2,int line=0,int column=0);

   int get_str_num(){return _strings.size();}

   //void add_line(const std::string &str){_strings.push_back(str);}
   void add_line(const DS::PortString &str){_port_strings.push_back(str);}
   void del_all_str(){_port_strings.clear();} // del this port all ch_string

  private:

   //std::vector<ch_string> _strings;
   std::vector<std::string> _strings;
   std::vector<PortString> _port_strings;
   int _line; // ���� line �������� 
   int _column; // ���� column ��������

 };


}
#endif
