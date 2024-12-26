using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace Laba7SP
{
    public partial class Form1 : Form
    {
        bool emblemFlag, olympicFlag , textureFlag, figureFlag, randomMoveFlag, leftMoveFlag, averageMoveFlag, screenFlag ;

        static Image emblem;

        Rectangle rec = new Rectangle(10, 10, 100, 100);
        Rectangle rec2 = new Rectangle(10, 140, 100, 100);
        Rectangle rec3 = new Rectangle(140, 140, 100, 100);

        int change1 =0 ;

        Point pt11, pt22;

        int x1 = 200;
        int y1 = 100;
        int x2 = 250;
        int y2 = 100;
        int y3 = 150;


        int dx = 5;
        int dy = 5;

        public Form1()
        {
            InitializeComponent();
            emblem = Image.FromFile("C:\\Users\\cjabz\\source\\repos\\Laba7SP\\sp.png");
        }


        private void button1_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            emblemFlag = !emblemFlag;
            olympicFlag = textureFlag = figureFlag = randomMoveFlag = leftMoveFlag = averageMoveFlag =screenFlag = false; 
            Refresh(); // чтобы вызвалсь Paint кнопок
        }

        private void button2_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            TextureBrush br6;
            br6 = new System.Drawing.TextureBrush(Image.FromFile("C:\\Users\\cjabz\\source\\repos\\Laba7SP\\sp.png"));

            e.Graphics.FillRectangle(br6, 100, 200, 300, 300);

            if (olympicFlag)
            {
                Pen rPen = new Pen(Color.Red, 6);
                Pen bPen = new Pen(Color.Black, 6);
                Pen bluePen = new Pen(Color.Blue, 6);
                Pen gPen = new Pen(Color.Green, 6);
                Pen yPen = new Pen(Color.Yellow, 6);
                SolidBrush wBrush = new SolidBrush(Color.White);
                e.Graphics.DrawRectangle(bPen, 5, 5, 300, 150);
                e.Graphics.FillRectangle(wBrush, 5, 5, 300, 150);

                e.Graphics.DrawEllipse(bluePen, 10, 10, 90, 90);
                e.Graphics.DrawEllipse(bPen, 110, 10, 90, 90);
                e.Graphics.DrawEllipse(yPen, 60, 60, 90, 90);
                Rectangle r1 = new Rectangle(110, 10, 90, 90);
                Rectangle r = new Rectangle(10, 10, 90, 90);
                e.Graphics.DrawArc(bluePen, r, -30, 90);
                e.Graphics.DrawArc(bPen, r1, 90, 20);
                e.Graphics.DrawEllipse(rPen, 210, 10, 90, 90);
                e.Graphics.DrawEllipse(gPen, 160, 60, 90, 90);
                Rectangle r2 = new Rectangle(110, 10, 90, 90);
                e.Graphics.DrawArc(bPen, r2, -30, 90);
                Rectangle r3 = new Rectangle(210, 10, 90, 90);
                e.Graphics.DrawArc(rPen, r3, 90, 20);
            }

            if (textureFlag)
            {
                //TextureBrush br2;
                //br2 = new System.Drawing.TextureBrush(Image.FromFile("C:\\Users\\cjabz\\Downloads\\texture1.webp"));
                //e.Graphics.FillRectangle(br2, 0, 0, Size.Width , Size.Height);
               
            }

            if (figureFlag)
            {
                TextureBrush br2;
                br2 = new System.Drawing.TextureBrush(Image.FromFile("C:\\Users\\cjabz\\Downloads\\texture1_3.png"));
                e.Graphics.FillRectangle(br2, 10, 10, 100, 100);

                LinearGradientBrush br3;
                Point pt1, pt2;
                pt1 = new Point(10, 120);
                pt2 = new Point(150, 220);
                LinearGradientBrush br4;
                Point pt3, pt4;
                pt3 = new Point(40, 250);
                pt4 = new Point(40, 400);
                br3 = new System.Drawing.Drawing2D.LinearGradientBrush(pt1, pt2, Color.BlueViolet, Color.Chartreuse);
                e.Graphics.FillRectangle(br3, 10, 140, 100, 100);
                br4 =  new System.Drawing.Drawing2D.LinearGradientBrush(pt3, pt4, Color.BlueViolet, Color.Chartreuse);
                e.Graphics.FillEllipse(br4, 10, 260, 100, 100);
            }

            if (randomMoveFlag)
            {
                TextureBrush br2;
                br2 = new System.Drawing.TextureBrush(Image.FromFile("C:\\Users\\cjabz\\Downloads\\texture1_3.png"));
                e.Graphics.FillRectangle(br2, rec);

                LinearGradientBrush br3;
                pt11 = new Point(10 + change1, 120);
                pt22 = new Point(150 + change1, 220);
                br3 = new System.Drawing.Drawing2D.LinearGradientBrush(pt11, pt22, Color.BlueViolet, Color.Chartreuse);
                e.Graphics.FillRectangle(br3, rec2);

            }

            if (leftMoveFlag)
            {

                TextureBrush br2;
                br2 = new System.Drawing.TextureBrush(Image.FromFile("C:\\Users\\cjabz\\Downloads\\texture1_3.png"));

                e.Graphics.TranslateTransform(rec3.Left, rec3.Top);
                e.Graphics.RotateTransform(change1);
                e.Graphics.TranslateTransform(-rec3.Left, -rec3.Top);
                e.Graphics.FillRectangle(br2, rec3);

                e.Graphics.ResetTransform();

                LinearGradientBrush br3;
                pt11 = new Point(10, 120);
                pt22 = new Point(150, 220);
                br3 = new System.Drawing.Drawing2D.LinearGradientBrush(pt11, pt22, Color.BlueViolet, Color.Chartreuse);

                e.Graphics.TranslateTransform(rec2.Left, rec2.Top);
                e.Graphics.RotateTransform(change1);
                e.Graphics.TranslateTransform(-rec2.Left, -rec2.Top);
                e.Graphics.FillRectangle(br3, rec2);

            }

            if (averageMoveFlag)
            {
                TextureBrush br2;
                br2 = new System.Drawing.TextureBrush(Image.FromFile("C:\\Users\\cjabz\\Downloads\\texture1_3.png"));

                e.Graphics.TranslateTransform(rec3.Left+(rec3.Width/2), rec3.Top + (rec3.Height/2)) ;
                e.Graphics.RotateTransform(change1);
                e.Graphics.TranslateTransform(-(rec3.Left + (rec3.Width / 2)), -(rec3.Top + (rec3.Width / 2)) );
                e.Graphics.FillRectangle(br2, rec3);

                e.Graphics.ResetTransform();

                LinearGradientBrush br3;
                pt11 = new Point(10, 120);
                pt22 = new Point(150, 220);
                br3 = new System.Drawing.Drawing2D.LinearGradientBrush(pt11, pt22, Color.BlueViolet, Color.Chartreuse);

                e.Graphics.TranslateTransform(rec2.Left + (rec2.Width / 2), rec2.Top + (rec2.Height / 2));
                e.Graphics.RotateTransform(change1);
                e.Graphics.TranslateTransform(-(rec2.Left + (rec2.Width / 2)), -(rec2.Top + (rec2.Width / 2)));
                e.Graphics.FillRectangle(br3, rec2);


            }

           

            if (screenFlag)
            {
                //int speed = 5;
                //change1 += 5;
               
     
                Pen RedPen = new Pen(Color.Red, 3);
                Pen BluePen = new Pen(Color.Blue, 3);
                Pen GreenPen = new Pen(Color.Green, 3);
                Pen WhitePen  = new Pen(Color.White, 3);
              

                if (x2 >= Width - 40 )
                {

                    dx = -5;
                    

                }
                if (y3 >= Height - 40)
                {
                    dy =- 5;
                }
                if (y1 <= 5)
                {
                    dy = 5;
                }
                if (x1 <= 5)
                {
                    dx = 5;
                }

                e.Graphics.DrawLine(RedPen, x1 , y1 , x2 , y2 );
                e.Graphics.DrawLine(BluePen, x2 , y1 , x2 , y3 );
                e.Graphics.DrawLine(GreenPen, x2 , y3 , x1 , y3 );
                e.Graphics.DrawLine(WhitePen, x1 , y3 , x1 , y1 );
            }
            else
            {

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            olympicFlag = !olympicFlag;
            emblemFlag = textureFlag = figureFlag = randomMoveFlag = leftMoveFlag  =averageMoveFlag = screenFlag = false;
            Refresh(); // чтобы нарисовать в picturebox и убрать эмблему с кнопок
        }

        private void button3_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);

        }

        private void button4_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void button5_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void button6_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void button7_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void button8_Click(object sender, EventArgs e)
        {
            screenFlag = !screenFlag;
            emblemFlag = textureFlag = figureFlag = randomMoveFlag = leftMoveFlag = averageMoveFlag = olympicFlag = false;
            timer1.Enabled = !timer1.Enabled;
            if (screenFlag)
                BackColor = Color.Black;
            else BackColor = Color.White;
            Refresh(); // чтобы нарисовать в picturebox и убрать эмблему с кнопок
        }

        private void button8_Paint(object sender, PaintEventArgs e)
        {
            if (emblemFlag) e.Graphics.DrawImage(emblem, 0, 0, 50, 50);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (randomMoveFlag)
            {
                int speed = 3;
                change1 += speed;
                rec.Location = new Point(rec.Left + 3*speed, rec.Top+speed );
                rec2.Location = new Point(rec2.Left + 3, rec2.Top);
                Refresh();
            }
            if (leftMoveFlag)
            {
                int speed = 5;
                change1 += speed;
                Refresh();

            }
            if (averageMoveFlag)
            {
                int speed = 5;
                change1 += speed;
                Refresh();
            }
            if (screenFlag)
            {
                x1 += dx;
                x2 += dx;
                y1 += dy;
                y2 += dy;
                y3 += dy;

                Refresh();
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            randomMoveFlag = !randomMoveFlag;
            olympicFlag = emblemFlag = textureFlag = figureFlag = leftMoveFlag = averageMoveFlag =screenFlag = false;
            timer1.Enabled = !timer1.Enabled;
            rec.Location = new Point(10, 10);
            pt11 = new Point(10 , 120);
            pt22 = new Point(150 , 220);
            rec2.Location = new Point(10, 140);
            change1 = 0;
            Refresh(); // чтобы вызвалсь Paint кнопок
        }

        private void button6_Click(object sender, EventArgs e)
        {
            leftMoveFlag = !leftMoveFlag;
            olympicFlag = emblemFlag = textureFlag = figureFlag = randomMoveFlag = averageMoveFlag =screenFlag = false;
            timer1.Enabled = !timer1.Enabled;
            pt11 = new Point(10, 120);
            pt22 = new Point(150, 220);
            rec2.Location = new Point(10, 140);
            change1 = 0;
            Refresh(); // чтобы вызвалсь Paint кнопок

        }

        private void button7_Click(object sender, EventArgs e)
        {
            averageMoveFlag = !averageMoveFlag;
            olympicFlag = emblemFlag = textureFlag = figureFlag = randomMoveFlag = leftMoveFlag =screenFlag = false;
            timer1.Enabled = !timer1.Enabled;
            pt11 = new Point(10, 120);
            pt22 = new Point(150, 220);
            change1 = 0;
            rec2.Location = new Point(10, 140);
            Refresh(); // чтобы вызвалсь Paint кнопок

        }

        private void button4_Click(object sender, EventArgs e)
        {
            figureFlag = !figureFlag;
            olympicFlag = emblemFlag = textureFlag = randomMoveFlag = leftMoveFlag = averageMoveFlag = screenFlag = false;
            Refresh(); // чтобы вызвалсь Paint кнопок
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textureFlag = !textureFlag;
            olympicFlag = emblemFlag = figureFlag = randomMoveFlag = leftMoveFlag = averageMoveFlag = screenFlag = false;

            if (textureFlag)
            {
                BackgroundImage = Image.FromFile("C:\\Users\\cjabz\\Downloads\\texture1_3.png");
            }
            else
              BackgroundImage = null;
            Refresh(); // чтобы вызвалсь Paint кнопок

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
