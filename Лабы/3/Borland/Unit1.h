//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TBorland : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *Edit1;
	TButton *first;
	TButton *second;
private:	// User declarations
public:		// User declarations
	__fastcall TBorland(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TBorland *Borland;
//---------------------------------------------------------------------------
#endif
