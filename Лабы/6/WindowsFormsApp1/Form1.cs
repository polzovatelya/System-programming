using System.Drawing.Drawing2D;
using System.Drawing;
using System.Windows.Forms;
using System;
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
 
namespace Lab_6_SP_5sem
{
    public partial class Form1 : Form
    {
        // Переменная для хранения логотипа
        private Image image_for_logo;
        // Переменная для хранения точки, от которой отрисовывается логотип
        private Point point_for_logo;
        // Флажок для включения/отключения отрисовки олимпийского флага
        private bool draw_flag_olympic_games;
        // Флажок для включения/отключения отрисовки игры
        private bool game;
        // Таблица для игры
        private int[,] table;
        // Флаг для определения чей ход
        bool move;
        // Градиентная и текстурная кисти
        Brush brush_gradient;
        Brush brush_texture;


        public Form1()
        {
            InitializeComponent();
            // Загружаем наш логотип дял кнопок
            image_for_logo = Image.FromFile("LOGO_LAB_6.png");
            // Логотип будет идти от верхнего левого угла
            point_for_logo = new Point(0, 0);
            // Инициализируем флаг отрисовки олимпийского флага
            draw_flag_olympic_games = false;
            // Инициализируем флаг игры
            game = false;
            // Инициализируем градиентную и текстурную кисти
            brush_gradient = new LinearGradientBrush(new Point(0, 0), new Point(60, 60), Color.FromArgb(150, 255, 0, 0), Color.FromArgb(255, 0, 0, 255));
            brush_texture = new TextureBrush(Image.FromFile("texture.png"));
        }

        // Обработчик события Paint для всех кнопок
        private void Logos_Paint(object sender, PaintEventArgs e)
        {
            // 1. На всех кнопках отрисуется логотип из файла
            //e.Graphics.DrawImage(image_for_logo, point_for_logo);

            // 2.На всех кнопках отрисуется кастомный логотип
            Draw_Custom_Logo(e.Graphics);
        }

        // Функция отрисовки кастомного логотипа
        private void Draw_Custom_Logo(Graphics g)
        {
            // Cоздаём кисти и карандаши
            SolidBrush my_brush_1 = new SolidBrush(Color.LightBlue);
            SolidBrush my_brush_2 = new SolidBrush(Color.Yellow);
            Pen my_pen_1 = new Pen(Color.Blue, 6);
            Pen my_pen_2 = new Pen(Color.Orange, 6);

            // Рисуем
            g.DrawEllipse(my_pen_1, 30, 12, 60, 60);
            g.FillEllipse(my_brush_1, 30, 12, 60, 60);
            g.DrawRectangle(my_pen_2, 40, 22, 40, 40);
            g.FillRectangle(my_brush_2, 40, 22, 40, 40);
        }

        // Функция отрисовки флага олимпийских игр
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

            // Рисуем красный и зелене круги
            g.DrawEllipse(red_pen, 310, 10, 140, 140);
            g.DrawEllipse(green_pen, 235, 85, 140, 140);

            // Рисуем дуги черного и красного цвета в местах, где зеленый круг должен быть снизу
            Rectangle rect_3 = new Rectangle(160, 10, 140, 140);
            Rectangle rect_4 = new Rectangle(310, 10, 140, 140);
            g.DrawArc(black_pen, rect_3, -30, 90);
            g.DrawArc(red_pen, rect_4, 90, 20);
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            // В зависимости от флажка рисуем олимпийский флаг
            if (draw_flag_olympic_games)
                Draw_Olympic_Flag(e.Graphics);
        }

        private void BttnFlagOlympicGames_Click(object sender, EventArgs e)
        {
            // Переключаем режим отображения олимпийского флага в противоположное положение
            draw_flag_olympic_games = !draw_flag_olympic_games;

            // Перерисовываем форму
            Refresh();
        }


   

    }
}
