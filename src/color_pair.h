/*
 * $Revision: 1.2 $
 * $Author: descent $
 * $Date: 2002/07/17 02:46:46 $
 * $Id: color_pair.h,v 1.2 2002/07/17 02:46:46 descent Exp $
 * �{���\��G�ھ� curses ���S��,���� color pair number �� screen class �ϥ��C�⪺�\��, screen class �b constructor �|���� initscr() ��l�� curses, �Ʊ�o�� class �i�H�Φb�Ҧ��� curses library,�o�� class �b terminal ���䴩�C��~��ϥ�,class �ʸ˦b DS �� namespcae,�ثe�S���B�z color pair number 0,�򥻤W�����ӥ� color pair number 0
 *
 */
#ifndef COLOR_PAIR_H
#define COLOR_PAIR_H

#include <curses.h>
#include <string>
#include <vector>
#include <utility> // need by pair class

// �� gcc 3 �� compile �N�ݭn�� namespace
//using std::string;


namespace DS
{
 typedef unsigned long COLOR_PAIR_TYPE;
 // ���� ColorPair class �� exception handling
 class ColorPairException
 {
  public:
   ColorPairException(const std::string &msg){_msg=msg;}
   const std::string &msg(){return _msg;}
  private:
   std::string _msg;
 };

 class ColorPair
 {
  public:
   ColorPair();
   // ���e���I����,�Ǧ^�@�� color pair number,�Y�w�g�s�b�ӫe���I����h�Ǧ^�� color pair number,�Y�L�h���ͷs�� color pair number �å[�J _color_pairs
   static COLOR_PAIR_TYPE get_color_pair(short f,short b); 
   static std::pair<short,short> get_colors(COLOR_PAIR_TYPE num); // ���w�@�� color pair number �Ǧ^�������e���I����,�Y�L�� color pair number �h��X�@�� exception ColorPairException
  private:
   static bool init_flag; // �]�� ColorPair �u�n��l�Ƥ@���N�i�H�F�C�ҥH�γo�� flag �ӨM�w�O�_�w�g��l�ƤF�C
   static void init_color();
   static std::vector<COLOR_PAIR_TYPE> _color_pairs; // �ΨӬ����w�ϥΪ� color pair number
   static int _max_color; // �̤j�� color pair number

 };

}

#endif
