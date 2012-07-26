/*
 *
 * $Revision$
 * $Author$
 * $Id$
 * $Date$
 * �{���\��GModel class �Ψ�����L�� class �~�ӧ����ӵ{�� model
 */
#ifndef MODEL_H
#define MODEL_H

#include "event.h"
#include "view.h"

namespace DS
{
 //class LView;
 //class ContlItem;
 class DS::View;
 class Model
 {
  public:
   Model( ){}
   //virtual unsigned is()  {  return ModelCls;  }
   virtual void init_menu( ){}
   virtual void init_statusLine(){}
   virtual void from_menu( DS::Event& event ){}
   virtual int from_view( DS::LView* view, DS::Event& event )
   {
    // -Y�ǤJ��"ƥ�O��L"ƥ�A�h�ǵ� keyEvent(...) �B�z
    if( event.what() == evKeyDown )
     return key_event( event );
    else
     return 0;
   }

   virtual int key_event( DS::Event &event ){return 0;}

   virtual int from_control( DS::Event &event )  { return 1; }
   virtual bool close( DS::View* view ){return true;}
   virtual ~Model(){}
 } ;

} // end namespace DS



#endif
