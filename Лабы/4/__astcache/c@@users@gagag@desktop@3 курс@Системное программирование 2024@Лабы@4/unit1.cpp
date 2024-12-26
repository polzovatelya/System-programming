//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool flag = false;
bool pic1 = false;
bool pic2 = false;
bool pic3 = false;
bool pic4 = false;
bool pic5 = false;
int OldX=600;
int OldY=600;
bool IsMouseDown=false;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void Sun(){
	Form1->Canvas->Brush->Color = clSkyBlue;
	Form1->Canvas->FillRect(TRect(100,100,400,400));
	Form1->Canvas->Brush->Color = clYellow;
	Form1->Canvas->Ellipse(150,150, 350,350);
	Form1->Canvas->Pen->Width = 30;
	Form1->Canvas->Pen->Color = clYellow;
	Form1->Canvas->MoveTo(100,400);
	Form1->Canvas->LineTo(400,100);
	Form1->Canvas->MoveTo(100,100);
	Form1->Canvas->LineTo(400,400);
	Form1->Canvas->MoveTo(250,100);
	Form1->Canvas->LineTo(250,400);
	Form1->Canvas->MoveTo(100,250);
	Form1->Canvas->LineTo(400,250);

}
void Draw_But(){
	Form1->Canvas->Brush->Color = clBtnFace;
	Form1->Canvas->FillRect(TRect(300,10,500,80));
	Form1->Canvas->Pen->Width = 1;
	Form1->Canvas->Pen->Color = clBlue;
	Form1->Canvas->MoveTo(300,10);
	Form1->Canvas->LineTo(500,10);
	Form1->Canvas->MoveTo(500,10);
	Form1->Canvas->LineTo(500,80);
	Form1->Canvas->MoveTo(500,80);
	Form1->Canvas->LineTo(300,80);
	Form1->Canvas->MoveTo(300,80);
	Form1->Canvas->LineTo(300,10);
	Form1->Canvas->Font->Size = 10;
	Form1->Canvas->TextOut(360,35, "Я кнопка");
}
void Draw_Graf(){
		double m1 = 1;
		if (Form1->Edit1->Text != "") {
			m1 = (Form1->Edit1->Text).ToDouble();
		}

		Form1-> Canvas -> Brush -> Color = TColor(RGB(0,0,0));
		Form1->Canvas -> Pen ->Color = TColor(RGB(0,0,0));
		Form1->Canvas -> Pen ->Width = 3;


		int xc = 600 ;
		int yc = 400 ;
		int lx =400; //половина длины оси Х
		int ly =400 ;  //половина длины оси Y
		double m=0.5 * m1;

		double mx =lx/10*m1;
		double my =ly/20*m1;
	// Оси
		Form1->Canvas->MoveTo(xc-round(lx*m),yc);
		Form1->Canvas->LineTo(xc+round(lx*m),yc);
		Form1->Canvas->MoveTo(xc,yc-round(ly*m));
		Form1->Canvas->LineTo(xc,yc+round(ly*m));
		Form1->Canvas -> Pen ->Color = TColor(RGB(191,55,157));
        double x =-5;
		Form1->Canvas->MoveTo(xc+round(x*mx),yc-round(  (5*sin(x + 1.2)*my - 7*sin(x*x - 10)*my)   ));
		while (x<=5) {
			Form1->Canvas->LineTo(xc+round(x*mx),yc-round((5*sin(x + 1.2)*my - 7*sin(x*x - 10)*my )));
			x += 0.1;
		}


}
void Draw_Fig(){
	int start = 0;
	int end = 255;
	Form1->Canvas->Brush->Color = TColor(RGB(random(255),random(255),random(255)));
	Form1->Canvas->Rectangle(600,600,700,700);

}
void Krug(int x, int y){
	if (pic3) {
		Form1->Canvas->Brush->Color = clBlack;
		Form1->Canvas->Ellipse(x-50,y-50, x+50,y+50);
	}
	else{
		Form1->Canvas->Brush->Color = Form1->Color;
		Form1->Canvas->FillRect(TRect(0,90, 1200,1200));
	}
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	pic1 = true;
	Form1->Refresh();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	if (pic1) {
		Sun();
	}
	if (flag) {
        Draw_Graf();
	}
	if (pic2) {
		Draw_Fig();
	}
	if (pic3) {
		 Krug(OldX,OldY);
	}


     Draw_But();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (((X<500) and (X>299))and ((Y>9) and (Y<81))){
		Form1->Canvas->Brush->Color = clBtnShadow;
		Form1->Canvas->FillRect(TRect(300,10,500,80));
		Form1->Canvas->Pen->Width = 1;
		Form1->Canvas->Pen->Color = clBlue;
		Form1->Canvas->MoveTo(300,10);
		Form1->Canvas->LineTo(500,10);
		Form1->Canvas->MoveTo(500,10);
		Form1->Canvas->LineTo(500,80);
		Form1->Canvas->MoveTo(500,80);
		Form1->Canvas->LineTo(300,80);
		Form1->Canvas->MoveTo(300,80);
		Form1->Canvas->LineTo(300,10);
		Form1->Canvas->Font->Size = 10;
		Form1->Canvas->TextOut(360,35, "Я кнопка");
	}
	OldX=X;
	OldY=Y;
	IsMouseDown=true;


}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if (((X<501) and (X >299))and ((Y>9) and (Y<81))){
		flag = true;
		Draw_But();
		Form1->Refresh();
	}

	IsMouseDown=false;
	OldX = 600;
    OldY = 600;
}


//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	pic2 = true;
	Form1->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
	Form1->Invalidate();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
     Form1->Color=TColor(RGB(random(255),random(255),random(255)));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
	pic3 = true;
	Form1 ->Refresh();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
	pic3 = false;
    Krug(OldX,OldY);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)
{
     if(IsMouseDown)
		{   pic3=false ;
			Krug(OldX,OldY);
			pic3=true;
			Krug(X,Y);

		}
}
//---------------------------------------------------------------------------
