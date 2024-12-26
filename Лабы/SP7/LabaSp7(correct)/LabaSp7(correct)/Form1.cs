using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace LabaSp7_correct_
{
    public partial class Form1 : Form
    {
        private System.Windows.Forms.Timer timer;
        private int animationStep;
        private int Step = 0;

        // Дополнительные переменные для хранения состояний анимации
        private int currentAnimation = 0;
        private Graphics GB;
        private Font font;
        private System.Drawing.Bitmap bitmap;

        public Form1()
        {
            InitializeComponent();
        }

        //private void ShowPresentation()
        //{
        //    Graphics GB = pictureBox1.CreateGraphics();
        //    Font font = new Font("Comic Sans MS", 36, FontStyle.Bold);
        //    System.Drawing.Bitmap bitmap;

        //    GB.Clear(Color.White);
        //    bitmap = new Bitmap(@"C:\Users\cjabz\source\repos\Laba7SP(correct)\Laba7SP(correct)\bliss.bmp");
        //    for (float i = 0; i <= 10; i++)
        //    {
        //        GB.DrawImage(bitmap, bitmap.Width - i * 90, bitmap.Height - i * 70, bitmap.Width, bitmap.Height);
        //        System.Threading.Thread.Sleep(50);
        //    }
        //    GB.DrawString("Любите природу", font, Brushes.White, 0, 0);
        //    bitmap.Dispose();
        //    System.Threading.Thread.Sleep(2000);

        //    GB.Clear(Color.White);
        //    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\recom2.jpg");
        //    GB.DrawImage(bitmap, 0, 0, 90, 40 );
        //    System.Threading.Thread.Sleep(150);
        //    for (int i = 10; i >= 0; --i)
        //    {
        //        GB.DrawImage(bitmap, 0, 0, bitmap.Width + 90 - 90 * i, bitmap.Height +40 - 70* i);
        //        System.Threading.Thread.Sleep(50);
        //    }
        //    GB.DrawString("Берегите лес", font, Brushes.Lime, 140, 200);
        //    bitmap.Dispose();
        //    System.Threading.Thread.Sleep(2000);

        //    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\recom2.jpg");
        //    for (int i = 0; i < 10; i++)
        //    {
        //        GB.DrawImage(bitmap, 0, 0, bitmap.Width - (bitmap.Width/10) * i, bitmap.Height - (bitmap.Height/10) * i);
        //        System.Threading.Thread.Sleep(100);
        //        GB.Clear(Color.White);
        //        System.Threading.Thread.Sleep(50);
        //    }
            
        //    bitmap.Dispose();
        //    System.Threading.Thread.Sleep(1000);

        //    //GB.Clear(Color.White);
        //    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\belka1.jpg");
        //    for (int i = 12; i > 0; --i)
        //    {
        //        GB.DrawImage(bitmap, 0, 0, bitmap.Width / i, bitmap.Height / i);
        //        System.Threading.Thread.Sleep(50);
        //    }
        //    GB.DrawString("И его жителей", font, Brushes.Orange, 10, 3);

        //    bitmap.Dispose();
        //}

        private void OnTimerTick(object sender, EventArgs e)
        {
            GB.Clear(Color.White);

            switch (currentAnimation)
            {
                case 0:
                    // Первая анимация
                    GB.DrawImage(bitmap, bitmap.Width - animationStep * 90, bitmap.Height - animationStep * 70, bitmap.Width, bitmap.Height);
                    if (++animationStep > 10)
                    {
                        GB.DrawString("Любите природу", font, Brushes.White, 0, 0);
                        animationStep = 0;
                        currentAnimation++;
                        bitmap.Dispose();
                        timer.Interval = 2000; // Пауза перед следующей анимацией
                    }
                    break;

                case 1:
                    // Вторая анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\recom2.jpg");
                    timer.Interval = 100; // Установите новый интервал
                    GB.DrawImage(bitmap, 0, 0, bitmap.Width + 90 - 90 * (10 - animationStep), bitmap.Height + 40 - 70 * (10 - animationStep) );
                    if (++animationStep > 10)
                    {
                        GB.DrawString("Берегите лес", font, Brushes.Lime, 140, 200);
                        currentAnimation++;
                        animationStep = 0;
                        bitmap.Dispose();
                        timer.Interval = 2000; // Пауза перед следующей анимацией
                    }
                    break;

                case 2:
                    // Третья анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\recom2.jpg");
                    timer.Interval = 150; // Установите новый интервал
                    if (animationStep < 10)
                    {
                        GB.DrawImage(bitmap, 0, 0, bitmap.Width - (bitmap.Width / 10) * animationStep, bitmap.Height - (bitmap.Height / 10) * animationStep);
                        animationStep++;
                    }
                    else
                    {
                        animationStep = 0;
                        currentAnimation++;
                        bitmap.Dispose();
                        timer.Interval = 1000; // Пауза перед следующей анимацией
                    }
                    break;

                case 3:
                    // Четвёртая анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\belka1.jpg");
                    timer.Interval = 150; // Установите новый интервал
                    GB.DrawImage(bitmap, 0, 0, bitmap.Width / (12 - animationStep), bitmap.Height / (12 - animationStep));
                    if (++animationStep > 11)
                    {
                        GB.DrawString("И его жителей", font, Brushes.Orange, 10, 3);
                       animationStep = 0;
                        bitmap.Dispose();
                        timer.Stop();
                    }
                    break;
            }
        }

        private void PainClick()
        {
            GB.Clear(Color.White);

            switch (Step)
            {
                case 0:
                    // Первая анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\source\repos\Laba7SP(correct)\Laba7SP(correct)\bliss.bmp");
                    for (float i = 0; i <= 10; i++)
                    {
                        GB.DrawImage(bitmap, bitmap.Width - i * 90, bitmap.Height - i * 70, bitmap.Width, bitmap.Height);
                        System.Threading.Thread.Sleep(50);
                    }
                    GB.DrawString("Любите природу", font, Brushes.White, 0, 0);
                    bitmap.Dispose();

                    break;

                case 1:
                    // Вторая анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\recom2.jpg");
                    GB.DrawImage(bitmap, 0, 0, 90, 40);
                    System.Threading.Thread.Sleep(150);
                    for (int i = 10; i >= 0; --i)
                    {
                        GB.DrawImage(bitmap, 0, 0, bitmap.Width + 90 - 90 * i, bitmap.Height + 40 - 70 * i);
                        System.Threading.Thread.Sleep(50);
                    }
                    GB.DrawString("Берегите лес", font, Brushes.Lime, 140, 200);
                    bitmap.Dispose();
                    break;

                case 2:
                    // Третья анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\recom2.jpg");
                    for (int i = 0; i < 10; i++)
                    {
                        GB.DrawImage(bitmap, 0, 0, bitmap.Width - (bitmap.Width / 10) * i, bitmap.Height - (bitmap.Height / 10) * i);
                        System.Threading.Thread.Sleep(100);
                        GB.Clear(Color.White);
                        System.Threading.Thread.Sleep(50);
                    }

                    bitmap.Dispose();
                    break;

                case 3:
                    // Четвёртая анимация
                    bitmap = new Bitmap(@"C:\Users\cjabz\Downloads\belka1.jpg");
                    for (int i = 12; i > 0; --i)
                    {
                        GB.DrawImage(bitmap, 0, 0, bitmap.Width / i, bitmap.Height / i);
                        System.Threading.Thread.Sleep(50);
                    }
                    GB.DrawString("И его жителей", font, Brushes.Orange, 10, 3);

                    bitmap.Dispose();
                    break;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            GB = pictureBox1.CreateGraphics();
            font = new Font("Comic Sans MS", 36, FontStyle.Bold);

            timer = new System.Windows.Forms.Timer();
            timer.Interval = 50; // укажите интервал в миллисекундах
            timer.Tick += OnTimerTick;

            animationStep = 0;
            currentAnimation = 0;

            bitmap = new Bitmap(@"C:\Users\cjabz\source\repos\Laba7SP(correct)\Laba7SP(correct)\bliss.bmp");
            timer.Start();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            GB = pictureBox1.CreateGraphics();
            font = new Font("Comic Sans MS", 36, FontStyle.Bold);

            PainClick();
            Step++;

            if (Step >= 4)
            {
                Step = 0;
            }

        }
    }
}
