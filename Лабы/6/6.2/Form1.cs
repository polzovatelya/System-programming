using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Security.Cryptography;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Net.Mime.MediaTypeNames;


namespace _6._2
{
    public partial class Form1 : Form
    {
        bool flag = false;
        bool fig = false;
        
        bool background = false;

        bool random_moving = false;
        bool rotation_left = false;
        bool rotation_average = false;

        int position = 0;
        Point pt11, pt22;

        int count = 0;
        bool screen = false;

        LinearGradientBrush brush_gradient;
        TextureBrush texture1;

        int dx, dy;
        Rectangle rec = new Rectangle(70, 70, 50, 50);
        Rectangle rec2 = new Rectangle(130, 70, 50, 50);
        Rectangle rec3 = new Rectangle(300, 100, 100, 100);

        public Form1()
        {
            InitializeComponent();

            //Rectangle Size_r = new Rectangle(160, 10, 140, 140);
            Rectangle Size_r = new Rectangle(10, 10, 50, 50);

            System.Drawing.Image newImage = System.Drawing.Image.FromFile("C:\\Users\\gagag\\Desktop\\3 курс\\Системное программирование 2024\\Лабы\\6\\k.jpg");
            texture1 = new TextureBrush(newImage, Size_r);


        }
        private void Draw_logo(Graphics g, Size s)
        {
            // Cоздаём кисти и карандаши
            SolidBrush my_brush_2 = new SolidBrush(Color.Teal);
            Pen my_pen_1 = new Pen(Color.Black, 3);
            Pen my_pen_2 = new Pen(Color.Orange, 3);

            int w = s.Width;
            int h = s.Height;


            g.DrawEllipse(my_pen_1,System.Convert.ToInt32(w*0.1), System.Convert.ToInt32(h * 0.1), System.Convert.ToInt32(w * 0.2), System.Convert.ToInt32(w * 0.2));
            g.FillEllipse(my_brush_2, System.Convert.ToInt32(w * 0.1), System.Convert.ToInt32(h * 0.1), System.Convert.ToInt32(w * 0.2), System.Convert.ToInt32(w * 0.2));

            g.DrawLine(my_pen_2, System.Convert.ToInt32(w * 0.1), System.Convert.ToInt32(w * 0.1), System.Convert.ToInt32(w * 0.17), System.Convert.ToInt32(h * 0.5));
            g.DrawLine(my_pen_2, System.Convert.ToInt32(w * 0.1), System.Convert.ToInt32(w * 0.1), System.Convert.ToInt32(w * 0.3), System.Convert.ToInt32(w * 0.1));
            g.DrawLine(my_pen_2,System.Convert.ToInt32(w * 0.17), System.Convert.ToInt32(h * 0.5), System.Convert.ToInt32(w * 0.3), System.Convert.ToInt32(w * 0.1));

            
        }

        private void Draw_Olympic_Flag(Graphics g)
        {
            // Cоздадим карандаши необходимых цветов
            Pen blue_pen = new Pen(Color.Blue, 7);
            Pen green_pen = new Pen(Color.LimeGreen, 7);
            Pen black_pen = new Pen(Color.Black, 7);
            Pen yellow_pen = new Pen(Color.Yellow, 7);
            Pen red_pen = new Pen(Color.Red, 7);

            // Рисуем синий, черный и в конце желтые круги
            g.DrawEllipse(blue_pen, 10, 10, 140, 140);
            g.DrawEllipse(black_pen, 160, 10, 140, 140);
            g.DrawEllipse(yellow_pen, 85, 85, 140, 140);

            // Рисуем дуги синего и черного цвета в местах, где желтый круг должен быть снизу
            Rectangle rect_1 = new Rectangle(10, 10, 140, 140);
            Rectangle rect_2 = new Rectangle(160, 10, 140, 140);
            g.DrawArc(blue_pen, rect_1, -30, 90);
            g.DrawArc(black_pen, rect_2, 90, 20);

            // Рисуем красный и зелен круги
            g.DrawEllipse(red_pen, 310, 10, 140, 140);
            g.DrawEllipse(green_pen, 235, 85, 140, 140);

            // Рисуем дуги черного и красного цвета в местах, где зеленый круг должен быть снизу
            Rectangle rect_3 = new Rectangle(160, 10, 140, 140);
            Rectangle rect_4 = new Rectangle(310, 10, 140, 140);
            g.DrawArc(black_pen, rect_3, -30, 90);
            g.DrawArc(red_pen, rect_4, 90, 20);
        }

        private void Draw_Figure(Graphics g)
        {
            //Зададим текстурную кисть
            rec.Location = new Point(70, 70);
            rec2.Location = new Point(130, 170);

            //Градиентная кисть
            brush_gradient = new LinearGradientBrush(new Point(rec2.Left,rec2.Top), new Point(rec2.Right, rec2.Bottom), Color.FromArgb(100, 96, 217), Color.FromArgb(95, 217, 160));

            //Квадрат

            g.FillRectangle(texture1, rec);

            //Круг
            g.FillRectangle(brush_gradient, rec2);
        }


        private void Flag_Paint(object sender, PaintEventArgs e)
        {

            
            Size s = Flag.Size;
            Draw_logo(e.Graphics, s);
        }

        private void Flag_Click(object sender, EventArgs e)
        {
            flag = !flag;
            screen = false;
            Region region1 = new Region(new Rectangle(0, 0, 460, 300));
            Invalidate(region1, false);
            //Draw_Olympic_Flag(e.Graphics);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            if (background)
            {
                Drawing_Background(e.Graphics);
            }
            if (flag)
            {
                Draw_Olympic_Flag(e.Graphics);
            }
            if (fig)
            {
                Draw_Figure(e.Graphics);
            }
            if (random_moving)
            {
                Drawing_moving(e.Graphics);
            }
            if (rotation_left)
            {
                Rotate_left(e.Graphics) ;
            }
            if (rotation_average)
            {
                Rotate_Average(e.Graphics);
            }
            if (screen)
            {
                Screen_pick(e.Graphics);
            }
            

        }


        private void Figure_Paint(object sender, PaintEventArgs e)
        {
            Size s = Figure.Size;
            Draw_logo(e.Graphics, s);

        }

        private void Figure_Click(object sender, EventArgs e)
        {
            fig = !fig;
            flag = background = rotation_left= random_moving=screen = false;
            Refresh();
        }


        private void Drawing_moving(Graphics g)
        {
            g.FillRectangle(texture1, rec );

            pt11 = new Point(130, 70 + position);
            pt22 = new Point(180, 120+position);

            brush_gradient = new LinearGradientBrush(pt11, pt22, Color.FromArgb(100, 96, 217), Color.FromArgb(95, 217, 160));

            g.FillRectangle(brush_gradient, rec2);
        }
        private void Drawing_Background(Graphics g)
        {     
            System.Drawing.Image newImage = System.Drawing.Image.FromFile("C:\\Users\\gagag\\Desktop\\3 курс\\Системное программирование 2024\\Лабы\\6\\p.jpg");
            TextureBrush texture = new TextureBrush(newImage, ClientRectangle);

            g.FillRectangle(texture, ClientRectangle);
            //this.BackColor = newImage;
                
        }
        private void Moving_Click(object sender, EventArgs e)
        {
            random_moving = !random_moving;
            flag = fig  = background = rotation_left = screen = false;
            timer1.Enabled = !timer1.Enabled;
            position = 0;
            rec.Location = new Point(70, 70);
            rec2.Location = new Point(130, 170);
            pt11 = new Point(rec2.Left, rec2.Top);
            pt22 = new Point(rec2.Right, rec2.Bottom);
            Refresh();
            
        }

        private void Back_Click(object sender, EventArgs e)
        {
            background = !background;
            flag = fig = rotation_left = random_moving = screen = false;
            System.Drawing.Image newImage = System.Drawing.Image.FromFile("C:\\Users\\gagag\\Desktop\\3 курс\\Системное программирование 2024\\Лабы\\6\\p.jpg");
            if (background)
            {
                this.BackgroundImage = newImage;
            }
            else
            {
                this.BackgroundImage = null;
                //this.BackColor = Color.White;
            }
            //Refresh();
        }

        private void Rotation_left_Click(object sender, EventArgs e)
        {
            rotation_left = !rotation_left;
            flag = fig = background = random_moving = screen = false;
            timer1.Enabled = !timer1.Enabled;
            position = 0;
            rec.Location = new Point(70, 70);
            rec2.Location = new Point(130, 170);
            pt11 = new Point(rec2.Left, rec2.Top);
            pt22 = new Point(rec2.Right, rec2.Bottom);
            Refresh();

        }
        private void Rotate_left(Graphics e)
        {
            e.TranslateTransform(rec.Left, rec.Top);
            e.RotateTransform(position);
            e.TranslateTransform(-rec.Left, -rec.Top);
            e.FillRectangle(texture1, rec);
            e.ResetTransform();

            pt11 = new Point(130, 70);
            pt22 = new Point(180, 120);
            brush_gradient = new LinearGradientBrush(pt11, pt22, Color.FromArgb(100, 96, 217), Color.FromArgb(95, 217, 160));

            e.TranslateTransform(rec2.Left, rec2.Top);
            e.RotateTransform(position);
            e.TranslateTransform(-rec2.Left, -rec2.Top);
            e.FillRectangle(brush_gradient, rec2);
        }

        private void Rotation_point_Click(object sender, EventArgs e)
        {
            rotation_average = !rotation_average;
            flag = fig = background = random_moving = screen = rotation_left = false;
            timer1.Enabled = !timer1.Enabled;
            position = 0;
            rec.Location = new Point(70, 70);
            rec2.Location = new Point(130, 170);
            pt11 = new Point(rec2.Left, rec2.Top);
            pt22 = new Point(rec2.Right, rec2.Bottom);
            Refresh();
        }
        private void Rotate_Average(Graphics e)
        {

            int coord1 = Convert.ToInt32(rec.Left+ (rec.Width / 2));
            int coord2 = Convert.ToInt32(rec.Top+(rec.Height / 2));
            e.TranslateTransform(coord1, coord2);
            e.RotateTransform(position);
            e.TranslateTransform(-coord1, -coord2);
            e.FillRectangle(texture1, rec);
            e.ResetTransform();

            pt11 = new Point(130, 70);
            pt22 = new Point(180, 120);
            brush_gradient = new LinearGradientBrush(pt11, pt22, Color.FromArgb(100, 96, 217), Color.FromArgb(95, 217, 160));

            coord1 = Convert.ToInt32(rec2.Left + (rec2.Width / 2));
            coord2 = Convert.ToInt32(rec2.Top + (rec2.Height / 2));

            e.TranslateTransform(coord1, coord2);
            e.RotateTransform(position);
            e.TranslateTransform(-coord1, -coord2);
            e.FillRectangle(brush_gradient, rec2);
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            timer2.Start();
            count = 0;
            BackColor = Color.White;
            dx = 0;
            dy = 0;
            screen = false;


        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            count++;
            if (count >= 70)
            {
                flag = fig = background = random_moving = rotation_left = rotation_average = false;
                screen = true;
                Refresh();

            }
        }
        private void Screen_pick(Graphics e)
        {
            BackColor = Color.Black;
            Random rnd = new Random();
            dx = rnd.Next(-250, 300);
            dy = rnd.Next(-100, 250);
            if (count % 2 == 0)
            {
                Pen br1 = new Pen(Color.FromArgb(128, 255, 255), 8);
                Attention(e, br1);
                
                //e.FillRectangle(br1, rec3);
            }
            else
            {
                Pen br1 = new Pen(Color.Black,8);
                Attention(e, br1);
                //e.FillRectangle(br1, rec3);
            }
        }
        private void Attention(Graphics e, Pen br)
        {

            e.DrawLine(br, 300 + dx, 100 + dy, 250 + dx, 250 + dy);
            e.DrawLine(br, 250 + dx, 250 + dy, 350 + dx, 250 + dy);
            e.DrawLine(br, 350 + dx, 250 + dy, 300 + dx, 100 + dy);

        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            timer1.Stop();
            timer2.Stop();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            if (random_moving)
            {
                int speed = 3;
                position += speed;
                rec.Location = new Point(rec.Left + 3 * speed, rec.Top + speed);
                rec2.Location = new Point(rec2.Left, rec2.Top+3);
                Refresh();
            }
            if (rotation_left)
            {
                int speed = 6;
                position += speed;
                Refresh();
            }
            if (rotation_average)
            {
                int speed = 6;
                position += speed;
                Refresh();
            }
        }
    }
}
