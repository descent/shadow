#include "color_pair.h"
#include <algorithm>
//#include <iostream>

std::vector<DS::COLOR_PAIR_TYPE> DS::ColorPair::_color_pairs;
int DS::ColorPair::_max_color;
bool DS::ColorPair::init_flag=false;

void DS::ColorPair::init_color()
{
 if (init_flag==true)
  return;
 if (has_colors())
 {
  init_flag=true;
  start_color(); // ��l���C��
  _max_color=COLOR_PAIRS-1; // _max_color ���̤j�� color pair number
  // �[�J 1,2,3 �� color pair number ,0 ���©��զr
  init_pair(1,COLOR_BLACK,COLOR_WHITE);
  init_pair(2,COLOR_WHITE,COLOR_BLUE);
  init_pair(3,COLOR_BLUE,COLOR_WHITE);
  _color_pairs.push_back(1);
  _color_pairs.push_back(2);
  _color_pairs.push_back(3);
 }
 else
 {
  throw DS::ColorPairException("The terminal does not support color");
 }

}
   
DS::ColorPair::ColorPair() // ��l�� curses �� color
{
 init_color(); 
}

// �`�N COLOR_PAIR_TYPE �n�g�� DS::COLOR_PAIR_TYPE�A�S�Q��ɤJ namespace DS �����ܱo�ܳ·�
// �o�O static member function
DS::COLOR_PAIR_TYPE DS::ColorPair::get_color_pair(short f,short b) // ���e���I����,�Ǧ^�@�� color pair number�A�w�g�s�b�ӫe���I����h�Ǧ^�� color pair number,�Y�L�h���ͷs�� color pair number �å[�J _color_pairs
{
 short foreground,background;
 std::vector<DS::COLOR_PAIR_TYPE> :: iterator it;
 
 DS::COLOR_PAIR_TYPE cur_col_pair=0;
 for (it=_color_pairs.begin() ; it!=_color_pairs.end() ; it++)
 {
  cur_col_pair=*it;
  pair_content(cur_col_pair,&foreground,&background); // find foreground
  if (foreground==f && background==b)
   return cur_col_pair;
 }
 // �ثe���S�� f b �զX�� color pair number
 //cur_col_pair++;
 cur_col_pair=_color_pairs.size()+1;
 if (cur_col_pair > _max_color)
  throw ColorPairException("Color pair number max"); // �Ҧ��� color pair number �w�Q�Χ�
 init_pair(cur_col_pair,f,b);
 _color_pairs.push_back(cur_col_pair);
 return cur_col_pair;
}

std::pair<short,short> DS::ColorPair::get_colors(DS::COLOR_PAIR_TYPE num) // ���w�@�� color pair number �Ǧ^�������e���I����,�Y�L�� color pair number �h��X�@�� exception ColorPairException
{
 if (std::find(_color_pairs.begin(),_color_pairs.end(),num)==_color_pairs.end())
  throw ColorPairException("The color pair number does not exist"); 
 short foreground,background;
 pair_content(num,&foreground,&background); // find foreground
 //std::cout << foreground << " " << background << std::endl;
 std::pair<short,short> colors(foreground,background);
 return colors;

}

