//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TRect btn2 = Rect(199,470,300,520);
bool pic = false, graf = false, figure = false, background = false, circle = false;
TRect figurecolor = Rect(200,200,500,300);
TRect circle7 = Rect(200,200,300,300);
TRect back ;
int x,y;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{

}

void DrawPicture(){
	Form1 -> Canvas->Pen->Width = 1;
	Form1 -> Canvas->Pen-> Color = TColor(RGB(0,0,0));
	// Небо
	Form1 -> Canvas->Brush->Color = TColor(RGB(22,37,28));
	Form1 -> Canvas->FillRect(Rect(10,10,700,450)) ;
	// Земля
	Form1 -> Canvas->Brush->Color = TColor(RGB(1,50,32)) ;
	Form1 -> Canvas->FillRect(Rect(10,250,700,450) );
	// Луна
	Form1 -> Canvas->Brush->Color = clYellow ;
	Form1 -> Canvas->Ellipse(50,50,140,140);
	Form1 -> Canvas->Pen-> Color =  TColor(RGB(22,37,28));
	Form1 -> Canvas->Brush->Color = TColor(RGB(22,37,28));
	Form1 -> Canvas->Ellipse(70,70,140,140);
	// Дерево
	Form1 -> Canvas->Brush->Color = TColor(RGB(72,60,50)) ;
	Form1 -> Canvas ->RoundRect(300, 300, 320, 150,25,25) ;
	Form1 -> Canvas->Brush->Color = TColor(RGB(0,255,0)) ;
	Form1 -> Canvas->Ellipse(230,90,390,230);
	// Цветок
	Form1 -> Canvas->Pen-> Color = clGreen;
	Form1 -> Canvas->Pen->Width = 3;
	Form1 -> Canvas->MoveTo(50,400) ; Form1 -> Canvas->LineTo(65,370)  ;
	Form1 -> Canvas->MoveTo(50,400) ; Form1 -> Canvas->LineTo(70,390)  ;
	Form1 -> Canvas->MoveTo(50,400) ; Form1 -> Canvas->LineTo(50,350)  ;
	Form1 -> Canvas->MoveTo(50,400) ; Form1 -> Canvas->LineTo(35,370)  ;
	Form1 -> Canvas->MoveTo(50,400) ; Form1 -> Canvas->LineTo(30,390)  ;
	Form1 -> Canvas->Brush->Color = clRed;
	Form1 -> Canvas->Pen->Width = 4;
	Form1 -> Canvas->Pen-> Color = TColor(RGB(239,152,170));
	Form1 -> Canvas->Ellipse(40,360,60,350);
}

void DrawSin(){
	Form1-> Canvas -> Brush -> Color = TColor(RGB(0,0,0));
	Form1->Canvas -> Pen ->Color = TColor(RGB(0,0,0));
	Form1->Canvas -> Pen ->Width = 3;


 int xc = Form1-> Width/ 2;
 int yc =  Form1 -> Height/2 ;

  double m=1.0;  //масштаб рисунка, для начала = 1

 	if  (Form1-> Edit1->Text != "" ){
	m = m* StrToFloat(Form1-> Edit1->Text); }
	else
	m = m;

 int lx =Form1-> Width/ 2/m; //половина длины оси Х
 int ly =Form1 -> Height/2/m ;  //половина длины оси Y

 double mx =lx/3.14/2;
 double my =ly/20;
 // Оси
  Form1->Canvas->MoveTo(xc-round(lx*m),yc);
  Form1->Canvas->LineTo(xc+round(lx*m),yc);
  Form1->Canvas->MoveTo(xc,yc-round(ly*m));
  Form1->Canvas->LineTo(xc,yc+round(ly*m));
  // Чёрточки
  for (int i =0 ; i<15 ;i++) {
	Form1->Canvas->MoveTo(xc+round(i*mx),yc+5);
	Form1->Canvas->LineTo(xc+round(i*mx),yc-5);

	Form1->Canvas->MoveTo(xc-round(i*mx),yc+5);
	Form1->Canvas->LineTo(xc-round(i*mx),yc-5);

	Form1->Canvas->MoveTo(xc+5,yc+round(i*my));
	Form1->Canvas->LineTo(xc-5,yc+round(i*my));

	Form1->Canvas->MoveTo(xc+5,yc-round(i*my));
	Form1->Canvas->LineTo(xc-5,yc-round(i*my));
	}
  //
  double x =-5;
  Form1->Canvas->MoveTo(xc+round(x*mx),yc-round(  (5*sin(x + 1.2)*my - 7*sin(x*x - 10)*my)   ));
  while (x<=5) {
	Form1->Canvas->LineTo(xc+round(x*mx),yc-round((5*sin(x + 1.2)*my - 7*sin(x*x - 10)*my )));
	x += 0.1;
	 }
}

void DrawFigure(){
	Form1->Canvas -> Brush -> Color =TColor(RGB(random(255),random(255),random(255))) ;
	Form1->Canvas->Rectangle(figurecolor) ;
}

void DrawBackground(){
	Form1->Canvas -> Brush -> Color =TColor(RGB(random(255),random(255),random(255))) ;
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width,Form1->Height));
}

void DrawCircle(){
	Form1->Canvas -> Brush -> Color =TColor(RGB(0,0,0)) ;
	Form1->Canvas->Ellipse(circle7);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	pic = true;

	DrawPicture();

}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormActivate(TObject *Sender)
{
	if (pic)  DrawPicture();
	if (graf) DrawSin();
	if (figure) DrawFigure();
	if (background) DrawBackground();
	if (circle) DrawCircle();

	//DrawCircle();

	Canvas -> Brush -> Color =clSilver;
	Canvas->FillRect(btn2) ;
	Canvas-> Font ->Name = "Tahoma";
	Canvas -> Font -> Color =clBlack;
	Canvas -> Font -> Size =  9;
	Canvas -> TextOut(200, 485, "Нажми меня!!!");

}


//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
		  int X, int Y)
{
	if ( (X > 199 && X < 300) && ( Y > 470 && Y < 520) && Button == mbLeft)  {
	Canvas -> Brush -> Color =clGray;
	Canvas->FillRect(btn2) ;
	Canvas-> Font ->Name = "Tahoma";
	Canvas -> Font -> Color =clBlack;
	Canvas -> Font -> Size =  9;
	Canvas -> TextOut(200, 485, "Нажми меня!!!");
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	if ( (X > 199 && X < 300) && ( Y > 470 && Y < 520) && Button == mbLeft)  {
	Canvas -> Brush -> Color =clSilver;
	Canvas->FillRect(btn2) ;
	Canvas-> Font ->Name = "Tahoma";
	Canvas -> Font -> Color =clBlack;
	Canvas -> Font -> Size =  9;
	Canvas -> TextOut(200, 485, "Нажми меня!!!");
	//Рисуем график функцию
	graf =true;
	pic = figure = background = circle =false;
	Form1 -> Refresh();
	DrawSin();

	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	figure = true;
	::InvalidateRect(Form1->Handle, &figurecolor,false);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
//	if (background) {
		Form1 -> Refresh();
//	}
//	if (figure) {
//	   ::InvalidateRect(Form1->Handle, &figurecolor,false);
//	}


	Canvas -> Brush -> Color =clSilver;
	Canvas->FillRect(btn2) ;
	Canvas-> Font ->Name = "Tahoma";
	Canvas -> Font -> Color =clBlack;
	Canvas -> Font -> Size =  9;
	Canvas -> TextOut(200, 485, "Нажми меня!!!");

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
   background = true;

   ::InvalidateRect(Form1->Handle, 0,false);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	graf = figure = pic = background =false;
	circle = true;

    Form1->Canvas -> Brush -> Color = Form1->Color ;
	Form1->Canvas->FillRect(Rect(0,0,Form1->Width,Form1->Height));

	Canvas -> Brush -> Color =clSilver;
	Canvas->FillRect(btn2) ;
	Canvas-> Font ->Name = "Tahoma";
	Canvas -> Font -> Color =clBlack;
	Canvas -> Font -> Size =  9;
	Canvas -> TextOut(200, 485, "Нажми меня!!!");

	::InvalidateRect(Form1->Handle, &circle7, false);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X, int Y)

{
	x = X; y = Y;
	if (Shift.Contains(ssLeft) ) {
		TRect newcircle = TRect(circle7.left ,circle7.right, x+50, x+50);
		::InvalidateRect(Form1->Handle, &circle7, true);
		circle7 = TRect(X-51, Y-51, X+51, Y+51);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
int r = (circle7.right - circle7.left) / 2;
int xrel = x - (circle7.right + circle7.left) / 2;
int yrel = y - (circle7.bottom + circle7.top) / 2;

	if ( (xrel * xrel + yrel * yrel) < r * r) {
		circle=false;
	::InvalidateRect(Form1->Handle, &circle7, true);        }
}
//---------------------------------------------------------------------------
